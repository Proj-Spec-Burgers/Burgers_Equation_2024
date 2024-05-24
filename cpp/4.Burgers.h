#pragma once

//Burgers' equation: par_u/par_t + u*par_u/par_x - beta*par_u^2/par_x^2=0 = 0 using Euler + Runge-Kutta 2nd order + implicit methods

class ParDiffEqBurgersEuler
{
public:
	//public constructor/s
	ParDiffEqBurgersEuler(double h, double k);
	//public function/s
	void Euler();
private:
	//private variable/s
	double midpoint{};
	const size_t M{ 101 };
	const size_t N{ 101 };
	std::vector<std::vector<double>> u{};

	double beta;
	double h;
	double k;
};

class ParDiffEqBurgersRK2
{
public:
	//public constructor/s
	ParDiffEqBurgersRK2(double h, double k);
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

class ParDiffEqBurgersImplicit
{
public:
	//public constructor/s
	ParDiffEqBurgersImplicit(double h, double k);
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