#pragma once
#include <vector>
#include <algorithm>
#include "Osobnik.h"

using namespace std;

class Populacja
{
private:
	vector<Osobnik> osobniki;
	int** graf;
	int wierzcholki;
	int nasycenie;
	int koloryzachlanny;
public:
	Populacja(int losobnikow, int wwierzcholki, int nnasycenie);
	void stworzGraf(int n, int d);
	void wykZachlanny();
	Osobnik getOsobnik(int i) { return osobniki[i]; }
	void sortuj();
	void wyswietl();
	void obliczJakosc();
};

