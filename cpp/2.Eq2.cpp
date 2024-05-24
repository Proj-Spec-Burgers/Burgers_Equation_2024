#include "0.0.Utility.h"
#include "2.Eq2.h"

//public contstructor/s
ParDiffEq2Euler::ParDiffEq2Euler(double h, double k)
	: h(h), k(k)
{
	MidPoint(h, M, midpoint);
	IniMatrix(M, N, u);
	InitialConditions(h, M, N, u, midpoint);
}
//public function/s
void ParDiffEq2Euler::Euler()
{
	const double s{ k / (4 * h) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] - s * (pow(u[i + 1][j], 2) - pow(u[i - 1][j], 2));
		}
	}

	std::string save_file_name{ "Results/Eq2/Euler_Eq_2_h_" + std::to_string(h) + "_k_" + std::to_string(k) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//public contstructor/s
ParDiffEq2RK2::ParDiffEq2RK2(double h, double k)
	: h(h), k(k)
{
	MidPoint ini_midpoint(h, M, midpoint);
	IniMatrix(M, N, u);
	IniMatrix(M, N, v);
	InitialConditions ini_initial_conditions_u(h, M, N, u, midpoint);
	InitialConditions ini_initial_conditions_v(h, M, N, v, midpoint);
}
//public function/s
void ParDiffEq2RK2::RK2()
{
	const double r{ k / (8 * h) };
	const double s{ k / (4 * h) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			v[i][j + 1] = u[i][j] - r * (pow(u[i + 1][j], 2) - pow(u[i - 1][j], 2));
		}
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] - s * (pow(v[i + 1][j + 1], 2) - pow(v[i - 1][j + 1], 2));
		}
	}

	std::string save_file_name{ "Results/Eq2/RK2_Eq_2_h_" + std::to_string(h) + "_k_" + std::to_string(k) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}