#include "0.0.Utility.h"
#include "1.Eq1.h"
#include "2.Eq2.h"
#include "3.Eq3.h"
#include "4.Burgers.h"

const static double h{ 0.1 };
const static double k{ 0.005 };

void DemoParDiffEq1()
{
	class ParDiffEq1Euler eq1_eul(h, k);
	eq1_eul.Euler();

	class ParDiffEq1RK2 eq1_rk2(h, k);
	eq1_rk2.RK2();
}
void DemoParDiffEq2()
{
	class ParDiffEq2Euler eq2_eul(h, k);
	eq2_eul.Euler();

	class ParDiffEq2RK2 eq2_rk2(h, k);
	eq2_rk2.RK2();
}
void DemoParDiffEq3()
{
	class ParDiffEq3Euler eq3_eul(h, k);
	eq3_eul.Euler();

	class ParDiffEq3RK2 eq3_rk2(h, k);
	eq3_rk2.RK2();

	class ParDiffEq3Implicit eq3_implicit(h, k);
	eq3_implicit.Implicit();
}
void DemoBurgersEq()
{
	class ParDiffEqBurgersEuler Burgers_eul(h, k);
	Burgers_eul.Euler();

	class ParDiffEqBurgersRK2 Burgers_rk2(h, k);
	Burgers_rk2.RK2();

	class ParDiffEqBurgersImplicit Burgers_implicit(h, k);
	Burgers_implicit.Implicit();
}

void MainMenu(bool& run)
{
	size_t choice{ 0 };
	const size_t final_choice{ 4 };

	system("cls");
	do
	{
		std::cout << "0. par_u/par_t + par_u/par_x = 0, PARABOLIC" << "\n";
		std::cout << "1. par_u/par_t + u*par_u/par_x = 0, PARABOLIC" << "\n";
		std::cout << "2. par_u/par_t - beta*par_u^2/par_x^2 = 0, beta > 0 => ELIPTIC, beta < 0 => HYPERBOLIC" << "\n";
		std::cout << "3. Burgers' equation: par_u/par_t + u*par_u/par_x - beta*par_u^2/par_x^2=0 = 0 , beta > 0 => ELIPTIC, beta < 0 => HYPERBOLIC" << "\n";
		std::cout << "4. Exit" << "\n";
		std::cin >> choice;
		if (choice > final_choice)
		{
			std::cout << "Wrong choice!";
			Sleep(1000);
			system("cls");
		}
		system("cls");
	} while (choice > final_choice);
	if (choice == 0)
	{
		DemoParDiffEq1();
	}
	else if (choice == 1)
	{
		DemoParDiffEq2();
	}
	else if (choice == 2)
	{
		DemoParDiffEq3();
	}
	else if (choice == 3)
	{
		DemoBurgersEq();
	}
	else if (choice == final_choice)
	{
		run = false;
	}
	else
	{
		throw std::string("Fatal Error!");
	}
}
int main()
{
	bool run{ true };

	while (run == true)
	{
		MainMenu(run);
	}
	return 0;
}