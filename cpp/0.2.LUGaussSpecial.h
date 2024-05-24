#pragma once

class LUGaussSpecial
{
public:
	//public constructor/s
	LUGaussSpecial(const size_t M, const double s_0, const double s_1, const double s_2, std::vector<double>& b, std::vector<double>& x);
private:
	//private function/s
	void SpecialGaussianElimination(std::vector<double>& b, std::vector<double>& x);
	void ExtractTriVectors(const double s_0, const double s_1, const double s_2);
	//private variable/s
	const size_t M;
	std::vector<double> a{};
	std::vector<double> c{};
	std::vector<double> d{};
};