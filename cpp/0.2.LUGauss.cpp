#include "0.0.Utility.h"
#include "0.1.MatrixOperations.h"
#include "0.2.LUGauss.h"

//public contstructor/s
LUGauss::LUGauss(const size_t M, const std::vector<std::vector<double>>& vec_A, const std::vector<double>& vec_b, std::vector<double>& x)
	: M(M)
{
	class IniVector(M, b);
	class VectorCopy(M, vec_b, b);
	class IniVector(M, z);
	class IniMatrix(M, M, A);
	class MatrixCopy(M, vec_A, A);
	class IniMatrix(M, M, U);
	class IniMatrix(M, M, L);
	class IniMatrix(M, M, LU);
	class IniMatrix(M, M, P);

	GaussianElimination(x);
}
//private function/s
void LUGauss::GaussianElimination(std::vector<double>& x) /*Gaussian elimination function*/
{
	class MatrixCopy(M, A, U); /*copy matrix A into matrix U*/
	class VectorCopy(M, b, z); /*copy vector b into vector z*/

	LUSolveRowScalingPermutation();
	zSolve();

	class MatrixMatrixMultiply(M, L, U, LU); /*multiply L and U to find LU*/
	class VectorCopy(M, z, x); /*copy vector z into vector x*/

	xSolve(x); /*find x vector*/
}
void LUGauss::LUSolveRowScalingPermutation()
{
	std::vector<std::vector<double>> A_temp{};
	class IniMatrix(M, M, A_temp);
	class MatrixCopy(M, U, A_temp);

	std::vector<double> z_temp{};
	class IniVector(M, z_temp);

	std::vector<double> s{};
	class IniVector(M, s);

	std::vector<size_t> p{};
	for (size_t i = 0; i < M; i++)
	{
		p.push_back(i);
	}

	double multiplier{};
	int row_0{}, row_1{};

	for (size_t i = 0; i < M - 1; i++) /*Gaussian elimination step*/
	{
		sMax(A_temp, s); /*find the scale of each row*/

		row_0 = i; /*find 1st row that will be swapped with 2nd row*/
		row_1 = qMax(i, A_temp, s); /*find 2nd row that will be swapped with 1st row*/

		Permutation(row_0, row_1, p); /*permutate vector*/

		for (size_t j = i + 1; j < M; j++) /*matrix row to be transformed*/
		{
			/*if we try to calculate the multiplier inside of the following loop, it will become 0 after 1 iteration*/
			multiplier = A_temp[p[j]][i] / A_temp[p[i]][i];
			for (size_t k = i; k < M; k++) /*matrix column to be transformed*/
			{
				A_temp[p[j]][k] = A_temp[p[j]][k] - (multiplier * A_temp[p[i]][k]); /*performing certain elementary row operations on U matrix*/
			}
			A_temp[p[j]][i] = multiplier;
		}
	}
	PermutationVectorToPermutationMatrix(p, P);
	class MatrixMatrixMultiply(M, P, A_temp, U);
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (i > j)
			{
				L[i][j] = U[i][j]; /*copy correct elements to L matrix*/
				U[i][j] = 0; /*then discard them*/
			}
		}
	}
	for (size_t i = 0; i < M; i++) /*filling out the rest of the L matrix with 1s and 0s*/
	{
		for (size_t j = 0; j < M; j++)
		{
			if (i == j)
			{
				L[i][j] = 1;
			}
			else if (j > i)
			{
				L[i][j] = 0;
			}
		}
	}
	class VectorCopy(M, z, z_temp);
	class MatrixVectorMultiply(M, P, z_temp, z); /*permutate z vector*/
}
void LUGauss::sMax(const std::vector<std::vector<double>>& mat, std::vector<double>& s) /*find max of absolute values for each nxn row*/
{
	for (size_t i = 0; i < M; i++)
	{
		s[i] = abs(mat[i][0]); /*assign first abs value in the row as maximum and go from there*/
		for (size_t j = 1; j < M; j++) /*check with the following abs value in the row and if it's bigger, assign it as new maximum*/
		{
			if (s[i] < abs(mat[i][j]))
			{
				s[i] = abs(mat[i][j]);
			}
		}
	}
}
int LUGauss::qMax(const int i, const std::vector<std::vector<double>>& mat, const std::vector<double>& s) /*find the row where the largest quotient exists*/
{
	std::vector<double> q{};
	class IniVector(M, q);

	int row_1 = i;

	for (size_t j = i; j < M; j++)
	{
		q[j] = abs(mat[j][i]) / s[j]; /*find quotients*/
	}
	for (size_t j = i; j < M - 1; j++) /*find the largest quotient and return the row where it exists*/
	{
		if (q[j] < q[j + 1])
		{
			row_1 = j + 1;
		}
		else
		{
			q[j + 1] = q[j];
		}
	}
	return row_1;
}
void LUGauss::Permutation(const size_t row_0, const size_t row_1, std::vector<size_t>& p) /*permutate vector*/
{
	size_t p_i{}, p_j{};
	p_i = p[row_0];
	p_j = p[row_1];
	p[row_0] = p_j;
	p[row_1] = p_i;
}
void LUGauss::PermutationVectorToPermutationMatrix(const std::vector<size_t>& p, std::vector<std::vector<double>>& P) /*assign a permutation matrix to a permutation vector*/
{
	for (size_t i = 0; i < M; i++)
	{
		P[i][p[i]] = 1;
	}
}
void LUGauss::xSolve(std::vector<double>& x) /*find x vector*/
{
	std::vector<std::vector<double>> U_temp{};
	class IniMatrix(M, M, U_temp);
	class MatrixCopy(M, U, U_temp);

	double quotient{}, sum{};

	for (int i = M - 1; i >= 0; i--) /*divide each row by the value on the diagonal on that row*/
	{
		quotient = U_temp[i][i];
		for (size_t j = i; j < M; j++)
		{
			U_temp[i][j] = U_temp[i][j] / quotient;
		}
		x[i] = x[i] / quotient;
	}
	for (int i = M - 2; i >= 0; i--) /*solve for each x_i*/
	{
		sum = 0;
		for (size_t j = i + 1; j < M; j++)
		{
			sum = sum + U_temp[i][j] * x[j];
		}
		x[i] = x[i] - sum;
	}
}
void LUGauss::zSolve() /*find z vector*/
{
	std::vector<std::vector<double>> L_temp{};
	class IniMatrix(M, M, L_temp);
	class MatrixCopy(M, L, L_temp);

	double sum{};

	for (size_t i = 1; i < M; i++) /*solve for each z_i*/
	{
		sum = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			sum = sum + L_temp[i][j] * z[j];
		}
		z[i] = z[i] - sum;
	}
}