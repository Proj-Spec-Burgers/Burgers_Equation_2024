#pragma once

class MatrixCopy
{
public:
	MatrixCopy(const size_t M, const std::vector<std::vector<double>>& mat_from, std::vector<std::vector<double>>& mat_to);
};

class VectorCopy
{
public:
	VectorCopy(const size_t M, const std::vector<double>& vec_from, std::vector<double>& vec_to);
};