#pragma once

//par_u/par_t - beta*par_u^2/par_x^2 = 0 differential equation using Euler + Runge-Kutta 2nd order + implicit methods

class ParDiffEq3Euler
{
public:
	//public constructor/s
	ParDiffEq3Euler(double h, double k);
	//public function/s
	void Euler();
private:
	//private variable/s
	double midpoint{};
	const size_t M{ 101 };
	const size_t N{ 101 };
	std::vector<std::vector<double>> u{};

	double beta;
	const double h;
	const double k;
};

class ParDiffEq3RK2
{
public:
	//public constructor/s
	ParDiffEq3RK2(double h, double k);
	//public function/s
	void RK2();
private:
	//private variable/s
	double midpoint{};
	const size_t M{ 101 };
	const size_t N{ 101 };
	std::vector<std::vector<double>> u{};
	std::vector<std::vector<double>> v{};

	double beta;
	const double h;
	const double k;
};

class ParDiffEq3Implicit
{
public:
	//public constructor/s
	ParDiffEq3Implicit(double h, double k);
	//public function/s
	void Implicit();
private:
	//private function/s
	void SetVectorb(const size_t column);
	//private variable/s
	double midpoint{};
	const size_t M{ 101 };
	std::vector<std::vector<double>> u{};
	std::vector<double> b{};

	double beta;
	const double h;
	const double k;
};