#include "pch.h"
#include "Populacja.h"

void mdisplay(int**mat, int n) {
	for (int i = 0; i < n; i++) {	//wypisywanie macierzy
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << ", ";
		}
		cout << endl;
	}
}

void colorVertex(int ** mat, int n, int * colors, int current)
{
	bool * usedColors = new bool[n];
	for (int i = 0; i < n; i++)
		usedColors[i] = false;
	for (int i = 0; i < n; i++)
	{
		if ((mat[current][i] == 0) || (colors[i] == -1))
			continue;
		usedColors[colors[i]] = true;
	}
	int i = 0;
	while (usedColors[i])
		i++;
	colors[current] = i;
	for (int i = 1; i < n; i++)
	{
		if ((mat[current][i] == 1) && (colors[i] < 0))
			colorVertex(mat, n, colors, i);
	}
}

int * easyColoring(int ** mat, int n)
{
	int * colors = new int[n];
	for (int i = 0; i < n; i++)
		colors[i] = -1;
	colorVertex(mat, n, colors, 0);
	return colors;
}

int max(int * tab, int n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (tab[i] > m)
			m = tab[i];
	}
	return m + 1;
}

Populacja::Populacja(int losobnikow, int wwierzcholki, int nnasycenie)
{
	wierzcholki = wwierzcholki;
	nasycenie = nnasycenie;
	stworzGraf(wierzcholki, nasycenie);
	wykZachlanny();
	//mdisplay(graf, wierzcholki); 
	
	for (int i = 0; i < losobnikow; i++) {
		osobniki.push_back(Osobnik(wierzcholki, koloryzachlanny));
	}
	osobniki[0].ustawGraf(graf);
	this->obliczJakosc();
	this->sortuj();
	this->wyswietl();
}

void Populacja::stworzGraf(int n, int d) {
	graf = new int *[n];
	for (int i = 0; i < n; i++)
	{
		graf[i] = new int[n];
		for (int j = 0; j < n; j++)
			graf[i][j] = 0;
	}
	int x, y;
	for (int i = 0; i < n - 1; i++)
	{
		graf[i][i + 1] = 1;
		graf[i + 1][i] = 1;
	}

	for (int i = 0; i < ((n*(n - 1) / 2)*d / 100.0) - (n - 1); i++)
	{
		while (true)
		{
			y = std::rand() % (n - 1);
			x = std::rand() % (n - y - 1) + y + 1;
			if (graf[y][x] == 0)
				break;
		}
		graf[y][x] = 1;
		graf[x][y] = 1;
	}
}

void Populacja::wykZachlanny() {
	int * kolory = easyColoring(graf, wierzcholki);
	koloryzachlanny = max(kolory, wierzcholki);
}

void Populacja::sortuj() {
	sort(osobniki.begin(), osobniki.end());
}

void Populacja::obliczJakosc() {
	for (int i = 0; i < osobniki.size(); i++) {
		osobniki[i].obliczJakosc();
	}
}

void Populacja::wyswietl() {
	for (int i = 0; i < osobniki.size(); i++) {
		cout << i + 1 << ". " << osobniki[i].jakosc << endl;
	}
}
