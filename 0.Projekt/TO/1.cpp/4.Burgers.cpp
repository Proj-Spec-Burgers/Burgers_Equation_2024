#include "0.0.Utility.h"
#include "0.3.Tri.h"
#include "4.Burgers.h"

//public contstructor/s
ParDiffEqBurgersEuler::ParDiffEqBurgersEuler(double h, double k)
	: h(h), k(k)
{
	beta = 1.3; /*satisfy (beta*k)/h^2 < 0.5 for stability*/

	SetMandN(h, k, M, N);
	MidPoint(h, M, midpoint);
	IniMatrix(M, N, u);
	InitialAndBoundaryConditionsMatrix(h, M, N, u, midpoint);
}
//public function/s
void ParDiffEqBurgersEuler::Euler()
{
	const double s_0{ k / (4 * h) };
	const double s_1{ (beta * k) / pow(h,2) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] - s_0 * (pow(u[i + 1][j], 2) - pow(u[i - 1][j], 2)) + s_1 * (u[i + 1][j] - 2 * u[i][j] + u[i - 1][j]);
		}
	}

	std::string save_file_name{ "Results/Eq4/Euler_Burgers_h_" + std::to_string(h) + "_k_" + std::to_string(k) + "_beta_" + std::to_string(beta) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}

//public contstructor/s
ParDiffEqBurgersRK2::ParDiffEqBurgersRK2(double h, double k)
	: h(h), k(k)
{
	beta = ((0.5 * pow(h, 2)) / k) - 0.01; /*satisfy (beta*k)/h^2 < 0.5 for stability*/

	SetMandN(h, k, M, N);
	MidPoint(h, M, midpoint);
	IniVector(M, v);
	IniMatrix(M, N, u);
	InitialAndBoundaryConditionsVector(h, M, v, midpoint);
	InitialAndBoundaryConditionsMatrix(h, M, N, u, midpoint);
}
//public function/s
void ParDiffEqBurgersRK2::RK2()
{
	const double r_0{ k / (8 * h) };
	const double r_1{ (beta * k) / (2 * pow(h,2)) };

	const double s_0{ k / (4 * h) };
	const double s_1{ (beta * k) / pow(h,2) };

	for (size_t j = 0; j < N - 1; j++)
	{
		for (size_t i = 1; i < M - 1; i++)
		{
			v[i] = u[i][j] - r_0 * (pow(u[i + 1][j], 2) - pow(u[i - 1][j], 2)) + r_1 * (u[i + 1][j] - 2 * u[i][j] + u[i - 1][j]);
		}
		for (size_t i = 1; i < M - 1; i++)
		{
			u[i][j + 1] = u[i][j] - s_0 * (pow(v[i + 1], 2) - pow(v[i - 1], 2)) + s_1 * (v[i + 1] - 2 * v[i] + v[i - 1]);
		}
	}

	std::string save_file_name{ "Results/Eq4/RK2_Burgers_h_" + std::to_string(h) + "_k_" + std::to_string(k) + "_beta_" + std::to_string(beta) + ".csv" };

	Save(h, k, M, N, u, save_file_name);
}

//public contstructor/s
ParDiffEqBurgersImplicit::ParDiffEqBurgersImplicit(double h, double k)
	: h(h), k(k)
{
	beta = ((0.5 * pow(h, 2)) / k) - 0.01; /*satisfy (beta*k)/h^2 < 0.5 for stability*/

	SetM(h, M);
	MidPoint(h, M, midpoint);
	IniMatrix(M, M, u);
	IniVector(M, b);
	InitialAndBoundaryConditionsMatrix(h, M, M, u, midpoint);
}
//public function/s
void ParDiffEqBurgersImplicit::Implicit()
{
	const double s{ (beta * k) / pow(h,2) };
	const double s_0{ -s };
	const double s_1{ 1 + 2 * s };
	const double s_2{ -s };;

	for (size_t j = 0; j < M - 1; j++)
	{
		SetVectorb(j);
		Tri solve(s_0, s_1, s_2, M, j, b, u);
	}

	std::string save_file_name{ "Results/Eq4/Implicit_Burgers_h_" + std::to_string(h) + "_k_" + std::to_string(k) + "_beta_" + std::to_string(beta) + ".csv" };

	Save(h, k, M, M, u, save_file_name);
}
void ParDiffEqBurgersImplicit::SetVectorb(const size_t column)
{
	b[0] = u[0][column];
	for (size_t i = 1; i < M - 1; i++)
	{
		b[i] = u[i][column] - (k / (4 * h)) * (pow(u[i + 1][column], 2) - pow(u[i - 1][column], 2));
	}
	b[M - 1] = u[M - 1][column];
}