#include "0.0.Utility.h"

Save::Save(const double h, const double k, const size_t M, const size_t N, const std::vector<std::vector<double>>& u, const std::string save_file_name)
{
	std::ofstream out;
	out.open(save_file_name);
	if (out.is_open())
	{
		for (size_t j = 0; j < N; j++)
		{
			for (size_t i = 0; i < M; i++)
			{
				out << i * h << "," << j * k << "," << u[i][j] << "\n";
			}
		}
	}
	else
	{
		throw std::string("Could not save to file!");
	}
	out.close();
}

MidPoint::MidPoint(const double h, const size_t M, double& midpoint)
{
	midpoint = ((M - 1) * h) / 2;;
}

IniVector::IniVector(const size_t M, std::vector<double>& vec)
{
	vec.resize(M);
	for (size_t i = 0; i < M; i++)
	{
		vec[i] = 0;
	}
}

IniMatrix::IniMatrix(const size_t M, const size_t N, std::vector<std::vector<double>>& mat)
{
	mat.resize(M, std::vector<double>(N));
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			mat[i][j] = 0;
		}
	}
}

InitialAndBoundaryConditionsMatrix::InitialAndBoundaryConditionsMatrix(const double h, const size_t M, const size_t N, std::vector<std::vector<double>>& mat, const double midpoint)
{
	for (size_t i = 0; i < M; i++)
	{
		mat[i][0] = exp(-pow((i * h - midpoint), 2));
	}
	for (size_t j = 0; j < N; j++)
	{
		mat[0][j] = 0;
		mat[M - 1][j] = 0;
	}
}

InitialAndBoundaryConditionsVector::InitialAndBoundaryConditionsVector(const double h, const size_t M, std::vector<double>& vec, const double midpoint)
{
	for (size_t i = 0; i < M; i++)
	{
		vec[i] = exp(-pow((i * h - midpoint), 2));
	}
	vec[0] = 0;
	vec[M - 1] = 0;
}

SetMandN::SetMandN(const double h, const double k, size_t& M, size_t& N)
{
	M = (10 / h) + 1;
	N = (5 / k) + 1;
}

SetM::SetM(const double h, size_t& M)
{
	M = (10 / h) + 1;
}