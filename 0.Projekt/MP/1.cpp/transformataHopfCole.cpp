#include "transformataHopfCole.h"
#include <iostream>
#include <fstream>
#include <string>



vector<double> transformataHopfCole::inicjacjaThetaX0() {
    vector<double>newTheta;
    for (int i = 0; i < N; ++i) {
        double potega = (-1 / (2 * M_PI * n)) * (1 - cos(M_PI * (i * h)));
        newTheta.push_back(exp(potega));
    }
    zapisDoPliku(liczenieMu(newTheta), 0);
    return newTheta;
}

vector<double> transformataHopfCole::liczenieThetaOdCzasu() {
    vector<double>thetaDlaCzasu(N);
    thetaDlaCzasu = theta;
    for (int j = 1; j < 10; ++j) {
        t = j * k;
        vector<double>v(N);
        v[0] = (1 - 2 * r) * thetaDlaCzasu[0] + 2 * r * thetaDlaCzasu[1]; //warunki brzegowe  
        v[N - 1] = 2 * r * thetaDlaCzasu[N - 2] + (1 - 2 * r) * thetaDlaCzasu[N - 1];
        for (int i = 1; i < (N - 1); ++i) {
            double wynik = r * thetaDlaCzasu[i - 1] + (1 - 2 * r) * thetaDlaCzasu[i] + r * thetaDlaCzasu[i + 1];
            v[i] = wynik;
        }
        thetaDlaCzasu = v;
        zapisDoPliku(liczenieMu(thetaDlaCzasu), t);

    }
    return thetaDlaCzasu;
}

vector<double> transformataHopfCole::liczenieMu(vector<double> newMu) {
    vector<double>newMu1(N);
    newMu1[0] = 0;//warunek poczatkowy
    newMu1[N - 1] = 0;//warunek koncowy
    for (int i = 1; i < (N - 1); ++i) {
        newMu1[i] = (-(n / h) * ((newMu[i + 1] - newMu[i - 1]) / newMu[i]));
    }

    return newMu1;
}

void transformataHopfCole::zapisDoPliku(vector<double> newMu, double newT) {
    string nazwaPliku = "Wyniki1DlaT" + to_string(newT) + ".txt";
    std::ofstream plik(nazwaPliku);

    // Sprawdzamy, czy plik zosta³ otwarty poprawnie
    if (!plik) {
        std::cerr << "Nie mo¿na otworzyæ pliku!" << std::endl;
        return;
    }
    for (int i = 0; i < size(newMu); ++i) {

        plik << (i * h) << " " << newMu[i] << '\n';
    }

    // Zamykamy plik
    plik.close();
}

void transformataHopfCole::wynikiKonczowe() {
    theta = inicjacjaThetaX0();
    theta = liczenieThetaOdCzasu();
}
