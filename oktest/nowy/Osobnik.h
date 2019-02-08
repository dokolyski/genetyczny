#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Osobnik
{
private:
	vector<int> kolory;
	static int** graf;
	int bledy;
	int wierzcholki;
	int liczbakolorow;
public:
	double jakosc;
	Osobnik(int wwierzcholki, int koloryzachlanny);
	void ustawGraf(int** nowygraf);
	void policzBledy();
	void obliczJakosc();
	void wyswietl();
	bool operator< (Osobnik &osobnik);
};

