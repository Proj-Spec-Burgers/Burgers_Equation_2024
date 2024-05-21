#include "0.0.Utility.h"

Save::Save(const double h, const double k, const size_t M, const size_t N, const std::vector<std::vector<double>>& u, const std::string save_file_name)
{
	std::ofstream out;
	out.open(save_file_name);
	if (out.is_open())
	{
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MidPoint::MidPoint(const double h, const size_t M, double& midpoint)
{
	midpoint = ((M - 1) * h) / 2;;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IniVector::IniVector(const size_t M, std::vector<double>& vec)
{
	vec.resize(M);
	for (size_t i = 0; i < M; i++)
	{
		vec[i] = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

InitialConditions::InitialConditions(const double h, const size_t M, const size_t N, std::vector<std::vector<double>>& vec, const double midpoint)
{
	for (size_t i = 0; i < M; i++)
	{
		vec[i][0] = exp(-pow((i * h - midpoint), 2));
	}
	for (size_t j = 0; j < N; j++)
	{
		vec[0][j] = 0;
		vec[M - 1][j] = 0;
	}
}