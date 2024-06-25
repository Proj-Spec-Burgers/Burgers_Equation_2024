#include "0.0.Utility.h"
#include "1.Eq1.h"

//public contstructor/s
ParDiffEq1Euler::ParDiffEq1Euler(double h, double k)
	: h(h), k(k)
{
	SetMandN(h, k, M, N);
	MidPoint(h, M, midpoint);
	IniMatrix(M, N, u);
	InitialAndBoundaryConditionsMatrix(h, M, N, u, midpoint);
}
//public function/s
void ParDiffEq1Euler::Euler()
{
	const double s{ k / (2 * h) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] - s * (u[i + 1][j] - u[i - 1][j]);
		}
	}

	std::string save_file_name{ "Results/Eq1/Euler_Eq_1_h_" + std::to_string(h) + "_k_" + std::to_string(k) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}

//public contstructor/s
ParDiffEq1RK2::ParDiffEq1RK2(double h, double k)
	: h(h), k(k)
{
	SetMandN(h, k, M, N);
	MidPoint(h, M, midpoint);
	IniVector(M, v);
	IniMatrix(M, N, u);
	InitialAndBoundaryConditionsVector(h, M, v, midpoint);
	InitialAndBoundaryConditionsMatrix(h, M, N, u, midpoint);
}
//public function/s
void ParDiffEq1RK2::RK2()
{
	const double r{ k / (4 * h) };
	const double s{ k / (2 * h) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			v[i] = u[i][j] - r * (u[i + 1][j] - u[i - 1][j]);
		}
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] - s * (v[i + 1] - v[i - 1]);
		}
	}


	std::string save_file_name{ "Results/Eq1/RK2_Eq_1_h_" + std::to_string(h) + "_k_" + std::to_string(k) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}