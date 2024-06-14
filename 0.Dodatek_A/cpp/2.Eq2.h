#pragma once

//par_u/par_t + u*par_u/par_x = 0 differential equation using Euler + Runge-Kutta 2nd order methods

class ParDiffEq2Euler
{
public:
	//public constructor/s
	ParDiffEq2Euler(double h, double k);
	//public function/s
	void Euler();
private:
	//private variable/s
	double midpoint{};
	const size_t M{ 101 };
	const size_t N{ 1001 };
	std::vector<std::vector<double>> u{};

	const double h;
	const double k;
};

class ParDiffEq2RK2
{
public:
	//public constructor/s
	ParDiffEq2RK2(double h, double k);
	//public function/s
	void RK2();
private:
	//private variable/s
	double midpoint{};
	const size_t M{ 101 };
	const size_t N{ 1001 };
	std::vector<std::vector<double>> u{};
	std::vector<std::vector<double>> v{};

	const double h;
	const double k;
};