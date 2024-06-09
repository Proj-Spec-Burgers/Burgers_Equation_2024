#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <math.h>
using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.71828182845904523536
#endif
class transformata {
	const int N = 11;      // liczba punktów siatki
	const double k = 0.005, h = 0.1;
	const double n = ((0.5 * pow(h, 2)) / k) - 0.01;
	const double r = n*k / pow(h, 2);
	double t = 0;

	vector<double>theta;
	vector<double>mu;
	vector<double> inicjacja_u(); //wzror 4 z pracy
	vector<double>inicjacjaThetaX0(); //wzor 8 z pracy
	vector<double>liczenieThetaOdCzasu();

	vector<double>liczenieMu(vector<double>newMu);//wzor 15
	void zapisDoPliku(vector<double> Theta, double newT);
public:
	void wynikiKonczowe();

};

