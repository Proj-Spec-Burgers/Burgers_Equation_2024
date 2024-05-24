#pragma once

class Tri
{
public:
	//public constructor/s
	Tri(double s_0, double s_1, double s_2, size_t M, size_t column, std::vector<double>& b, std::vector<std::vector<double>>& mat);
private:
	//private function/s
	void ExecuteTri(const double s_0, const double s_1, const double s_2, const size_t column, std::vector<double>& b, std::vector<std::vector<double>>& mat);
	void AssignResults(const size_t column, std::vector<std::vector<double>>& mat);
	//private variable/s
	const size_t M;
	std::vector<double> x{};
};