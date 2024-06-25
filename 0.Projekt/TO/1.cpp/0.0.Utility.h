#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

class Save
{
public:
	//public constructor/s
	Save(const double h, const double k, const size_t M, const size_t N, const std::vector<std::vector<double>>& u, const std::string save_file_name);
};

class MidPoint
{
public:
	//public constructor/s
	MidPoint(const double h, const size_t M, double& midpoint);
};

class IniVector
{
public:
	//public constructor/s
	IniVector(const size_t M, std::vector<double>& vec);
};

class IniMatrix
{
public:
	//public constructor/s
	IniMatrix(const size_t M, const size_t N, std::vector<std::vector<double>>& mat);
};

class InitialAndBoundaryConditionsMatrix
{
public:
	//public constructor/s
	InitialAndBoundaryConditionsMatrix(const double h, const size_t M, const size_t N, std::vector<std::vector<double>>& mat, const double midpoint);
};

class InitialAndBoundaryConditionsVector
{
public:
	//public constructor/s
	InitialAndBoundaryConditionsVector(const double h, const size_t M, std::vector<double>& vec, const double midpoint);
};

class SetMandN
{
public:
	//public constructor/s
	SetMandN(const double h, const double k, size_t& M, size_t& N);
};

class SetM
{
public:
	//public constructor/s
	SetM(const double h, size_t& M);
};