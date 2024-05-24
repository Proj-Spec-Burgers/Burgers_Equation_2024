#include "0.0.Utility.h"
#include "0.1.MatrixOperations.h"
#include "0.2.LUGaussSpecial.h"

//public contstructor/s
LUGaussSpecial::LUGaussSpecial(const size_t M, const double s_0, const double s_1, const double s_2, std::vector<double>& b, std::vector<double>& x)
	: M(M)
{
	IniVector(M, a);
	IniVector(M, c);
	IniVector(M, d);

	ExtractTriVectors(s_0, s_1, s_2);
	SpecialGaussianElimination(b, x);
}
//private function/s
void LUGaussSpecial::SpecialGaussianElimination(std::vector<double>& b, std::vector<double>& x)
{
	for (size_t i = 1; i < M; i++)
	{
		d[i] = d[i] - (a[i - 1] / d[i - 1]) * c[i - 1];
		b[i] = b[i] - (a[i - 1] / d[i - 1]) * b[i - 1];
	}
	x[M - 1] = b[M - 1] / d[M - 1];
	for (int i = M - 2; i >= 0; i--)
	{
		x[i] = (b[i] - (c[i] * x[i + 1])) / d[i];
	}
}
void LUGaussSpecial::ExtractTriVectors(const double s_0, const double s_1, const double s_2)
{
	for (size_t i = 0; i < M; i++)
	{
		a[i] = s_0;
		d[i] = s_1;
		c[i] = s_2;
	}
}