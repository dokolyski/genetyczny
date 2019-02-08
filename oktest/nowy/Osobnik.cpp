#include "pch.h"
#include "Osobnik.h"

int** Osobnik::graf = NULL;

Osobnik::Osobnik(int wwierzcholki, int koloryzachlanny)
{
	kolory.push_back(0);
	wierzcholki = wwierzcholki;
	int maxkolor = 0;
	int nowykolor;
	
	for (int i = 0; i < wierzcholki-1; i++) {
		nowykolor = rand() % koloryzachlanny;
		if (nowykolor > maxkolor) {
			nowykolor=++maxkolor;
		}
		kolory.push_back(nowykolor);
	}
	liczbakolorow = maxkolor+1;
}

void Osobnik::wyswietl() {
	cout << "LICZBA KOLOROW: " << liczbakolorow << endl;
	cout << "LICZBA BLEDOW: " << bledy << endl;
	cout << "JAKOSC: " << jakosc << endl;
	for (int i = 0; i < wierzcholki; i++) {
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < kolory.size(); i++) {
		cout << kolory[i]<<"\t";
	}
}

void Osobnik::ustawGraf(int** nowygraf) {
	graf = nowygraf;
}

void Osobnik::policzBledy() {
	bledy = 0;
	for (int i = 0; i < wierzcholki-1; i++) {
		for (int j = i + 1; j < wierzcholki; j++) {
			if (graf[i][j] == 1) if (kolory[i] == kolory[j]) {
				//cout << "blad dla: " << i << " " << j << endl; 
				bledy++;
			}
		}
	}
}

void Osobnik::obliczJakosc() {
	this->policzBledy();
	jakosc = 0.8*bledy + 0.2*liczbakolorow;	//??
}

bool Osobnik::operator< (Osobnik &osobnik) {
	return jakosc < osobnik.jakosc;
}