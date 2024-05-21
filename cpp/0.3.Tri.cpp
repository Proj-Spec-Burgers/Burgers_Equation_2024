#include "0.0.Utility.h"
#include "0.2.LUGauss.h"
#include "0.3.Tri.h"

//public contstructor/s
Tri::Tri(double s_0, double s_1, double s_2, size_t M, size_t column, std::vector<std::vector<double>>& mat)
	: M(M)
{
	class IniVector(M, b);
	class IniVector(M, x);
	class IniMatrix(M, M, A);

	ExecuteTri(s_0, s_1, s_2, column, mat);
}
//private function/s
void Tri::ExecuteTri(const double s_0, const double s_1, const double s_2, const size_t column, std::vector<std::vector<double>>& mat)
{
	SetMatrixA(s_0, s_1, s_2);
	SetVectorb(column, mat);
	class LUGauss solve(M, A, b, x);
	AssignResults(column, mat);
}
//Matrix operation functions
void Tri::SetMatrixA(const double s_0, const double s_1, const double s_2)
{
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (j == i + 1)
			{
				A[i][j] = s_0;
			}
			else if (j == i)
			{
				A[i][j] = s_1;
			}
			else if (i == j + 1)
			{
				A[i][j] = s_2;
			}
		}
	}
}
void Tri::SetVectorb(const size_t column, const std::vector<std::vector<double>>& mat)
{
	for (size_t i = 0; i < M; i++)
	{
		b[i] = mat[i][column];
	}
}
void Tri::AssignResults(const size_t column, std::vector<std::vector<double>>& mat)
{
	for (size_t i = 1; i < M - 1; i++)
	{
		mat[i][column + 1] = x[i];
	}
}