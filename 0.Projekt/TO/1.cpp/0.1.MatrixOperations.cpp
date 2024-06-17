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