#include "0.0.Utility.h"
#include "0.2.LUGaussSpecial.h"
#include "0.3.Tri.h"

//public contstructor/s
Tri::Tri(double s_0, double s_1, double s_2, size_t M, size_t column, std::vector<double>& b, std::vector<std::vector<double>>& mat)
	: M(M)
{
	IniVector(M, x);

	ExecuteTri(s_0, s_1, s_2, column, b, mat);
}
//private function/s
void Tri::ExecuteTri(const double s_0, const double s_1, const double s_2, const size_t column, std::vector<double>& b, std::vector<std::vector<double>>& mat)
{
	LUGaussSpecial solve(M, s_0, s_1, s_2, b, x);
	AssignResults(column, mat);
}
void Tri::AssignResults(const size_t column, std::vector<std::vector<double>>& mat)
{
	for (size_t i = 1; i < M - 1; i++)
	{
		mat[i][column + 1] = x[i];
	}
}