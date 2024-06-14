#include "0.0.Utility.h"
#include "0.3.Tri.h"
#include "3.Eq3.h"

//public contstructor/s
ParDiffEq3Euler::ParDiffEq3Euler(double h, double k)
	: h(h), k(k)
{
	beta = ((0.5 * pow(h, 2)) / k) - 0.01; /*satisfy (beta*k)/h^2 < 0.5 for stability*/

	MidPoint(h, M, midpoint);
	IniMatrix(M, N, u);
	InitialConditions(h, M, N, u, midpoint);
}
//public function/s
void ParDiffEq3Euler::Euler()
{
	const double s{ (beta * k) / pow(h,2) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] + s * (u[i + 1][j] - 2 * u[i][j] + u[i - 1][j]);
		}
	}

	std::string save_file_name{ "Results/Eq3/Euler_Eq_3_h_" + std::to_string(h) + "_k_" + std::to_string(k) + "_beta_" + std::to_string(beta) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//public contstructor/s
ParDiffEq3RK2::ParDiffEq3RK2(double h, double k)
	: h(h), k(k)
{
	beta = ((0.5 * pow(h, 2)) / k) - 0.01; /*satisfy (beta*k)/h^2 < 0.5 for stability*/

	MidPoint(h, M, midpoint);
	IniMatrix(M, N, u);
	IniMatrix(M, N, v);
	InitialConditions(h, M, N, u, midpoint);
	InitialConditions(h, M, N, v, midpoint);
}
//public function/s
void ParDiffEq3RK2::RK2()
{
	const double r{ (beta * k) / (2 * pow(h,2)) };
	const double s{ (beta * k) / pow(h,2) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			v[i][j + 1] = u[i][j] + r * (u[i + 1][j] - 2 * u[i][j] + u[i - 1][j]);
		}
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] + s * (v[i + 1][j + 1] - 2 * v[i][j + 1] + v[i - 1][j + 1]);
		}
	}

	std::string save_file_name{ "Results/Eq3/RK2_Eq_3_h_" + std::to_string(h) + "_k_" + std::to_string(k) + "_beta_" + std::to_string(beta) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//public contstructor/s
ParDiffEq3Implicit::ParDiffEq3Implicit(double h, double k)
	: h(h), k(k)
{
	beta = ((0.5 * pow(h, 2)) / k) - 0.01; /*satisfy (beta*k)/h^2 < 0.5 for stability*/

	MidPoint(h, M, midpoint);
	IniMatrix(M, M, u);
	IniVector(M, b);
	InitialConditions(h, M, M, u, midpoint);
}
//public function/s
void ParDiffEq3Implicit::Implicit()
{
	const double s{ (beta * k) / pow(h,2) };
	const double s_0{ -s };
	const double s_1{ 1 + 2 * s };
	const double s_2{ -s };;

	for (size_t j = 0; j < M-1; j++)
	{
		SetVectorb(j);
		Tri solve(s_0, s_1, s_2, M, j, b, u);
	}

	std::string save_file_name{ "Results/Eq3/Implicit_Eq_3_h_" + std::to_string(h) + "_k_" + std::to_string(k) + "_beta_" + std::to_string(beta) + ".csv" };

	Save(h, k, M, M, u, save_file_name);
}
//private function/s
void ParDiffEq3Implicit::SetVectorb(const size_t column)
{
	for (size_t i = 0; i < M; i++)
	{
		b[i] = u[i][column];
	}
}