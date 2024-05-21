#pragma once

class LUGauss
{
public:
	//public constructor/s
	LUGauss(const size_t M, const std::vector<std::vector<double>>& vec_A, const std::vector<double>& vec_b, std::vector<double>& x);
private:
	//private function/s
	void GaussianElimination(std::vector<double>& x);
	void LUSolveRowScalingPermutation();
	void sMax(const std::vector<std::vector<double>>& mat, std::vector<double>& s);
	int qMax(const int i, const std::vector<std::vector<double>>& mat, const std::vector<double>& s);
	void Permutation(const size_t row_0, const size_t row_1, std::vector<size_t>& p);
	void PermutationVectorToPermutationMatrix(const std::vector<size_t>& p, std::vector<std::vector<double>>& P);
	void xSolve(std::vector<double>& x);
	void zSolve();
	//private variable/s
	const size_t M;
	std::vector<double> b{};
	std::vector<double> z{};
	std::vector<std::vector<double>> A{};
	std::vector<std::vector<double>> U{};
	std::vector<std::vector<double>> L{};
	std::vector<std::vector<double>> LU{};
	std::vector<std::vector<double>> P{};
};