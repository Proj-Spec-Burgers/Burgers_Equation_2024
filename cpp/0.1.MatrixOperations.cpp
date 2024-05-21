#include "0.0.Utility.h"
#include "0.1.MatrixOperations.h"

MatrixCopy::MatrixCopy(const size_t M, const std::vector<std::vector<double>>& mat_from, std::vector<std::vector<double>>& mat_to)
{
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			mat_to[i][j] = mat_from[i][j];
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VectorCopy::VectorCopy(const size_t M, const std::vector<double>& vec_from, std::vector<double>& vec_to)
{
	for (size_t i = 0; i < M; i++)
	{
		vec_to[i] = vec_from[i];
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MatrixMatrixMultiply::MatrixMatrixMultiply(const size_t M, const std::vector<std::vector<double>>& mat_mult_0, const std::vector<std::vector<double>>& mat_mult_1, std::vector<std::vector<double>>& mat_result)
{
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			mat_result[i][j] = 0;
		}
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			for (size_t k = 0; k < M; k++)
			{
				mat_result[i][j] = mat_result[i][j] + mat_mult_0[i][k] * mat_mult_1[k][j];
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MatrixVectorMultiply::MatrixVectorMultiply(const size_t M, const std::vector<std::vector<double>>& mat_mult_0, const std::vector<double>& vec_mult_0, std::vector<double>& vec_result)
{
	for (size_t i = 0; i < M; i++)
	{
		vec_result[i] = 0;
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			vec_result[i] = vec_result[i] + mat_mult_0[i][j] * vec_mult_0[j];
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MatrixRowSwap::MatrixRowSwap(const size_t M, const size_t row_0, const size_t row_1, std::vector<std::vector<double>>& mat)
{
	std::vector<std::vector<double>> mat_temp{};
	class IniMatrix(M, M, mat_temp);

	class MatrixCopy(M, mat, mat_temp);

	for (size_t i = 0; i < M; i++)
	{
		mat[row_0][i] = mat_temp[row_1][i];
		mat[row_1][i] = mat_temp[row_0][i];
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VectorRowSwap::VectorRowSwap(const size_t M, const size_t row_0, const size_t row_1, std::vector<double>& vec)
{
	std::vector<double> vec_temp{};
	class IniVector(M, vec_temp);

	class VectorCopy(M, vec, vec_temp);

	vec[row_0] = vec_temp[row_1];
	vec[row_1] = vec_temp[row_0];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VectorPrint::VectorPrint(const size_t M, const std::vector<double>& vec)
{
	for (size_t i = 0; i < M; i++)
	{
		std::cout << vec[i] << " " << "\n";
	}
	std::cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MatrixPrint::MatrixPrint(const size_t M, const std::vector<std::vector<double>>& mat)
{
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << " " << mat[i][j];
		}
		std::cout << "\n";
	}
}