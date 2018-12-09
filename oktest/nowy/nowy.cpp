// nowy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>

#include "Populacja.h";
#include "Osobnik.h";

using namespace std;

int** load(string filename, int n) {
	string line;
	fstream file;
	int** mat = new int*[n];	//macierz sąsiedztwa
	for (int i = 0; i < n; i++) mat[i] = new int[n];

	file.open(filename, ios::in);
	if (file.good()) {
		getline(file, line);
		int x, y, flag;
		string xs, ys;

		while (!file.eof()) {	//odczytywanie kolejnych linii, wpisywanie polaczen w macierzy sasiedztwa
			xs = "";
			ys = "";
			getline(file, line);
			flag = -1;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == ' ') flag = i;
				if (flag < 0) xs += line[i];
				else if (flag > 0 && i > flag) ys += line[i];
			}
			x = atoi(xs.c_str()) - 1;
			y = atoi(ys.c_str()) - 1;
			mat[x][y] = 1;
			mat[y][x] = 1;
		}
		file.close();

		for (int i = 0; i < n; i++) {	//wypisywanie macierzy
			for (int j = 0; j < n; j++) {
				if (mat[i][j] != 1) {
					mat[i][j] = 0;
					mat[j][i] = 0;
				}
			}
		}
	}
	return mat;
}

void save(int**mat, int n, string name) {
	fstream file;
	file.open(name, ios::out);
	file << n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mat[i][j])
				file << endl << i + 1 << " " << j + 1;
		}
	}
	file.close();
}

/*void mdisplay(int**mat, int n) {
	for (int i = 0; i < n; i++) {	//wypisywanie macierzy
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int getn(string filename) {
	string line;
	fstream file;
	file.open(filename, ios::in);
	getline(file, line);
	return atoi(line.c_str());
}
/*
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

int ** create(int perc, int n)
{
	int ** tab = new int *[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
		for (int j = 0; j < n; j++)
			tab[i][j] = 0;
	}

	int x, y;
	for (int i = 0; i < n - 1; i++)
	{
		tab[i][i + 1] = 1;
		tab[i + 1][i] = 1;
	}

	for (int i = 0; i < ((n*(n - 1) / 2)*perc / 100.0) - (n - 1); i++)
	{
		while (true)
		{
			y = std::rand() % (n - 1);
			x = std::rand() % (n - y - 1) + y + 1;
			if (tab[y][x] == 0)
				break;
		}
		tab[y][x] = 1;
		tab[x][y] = 1;
	}
	return tab;
}*/

int main() {
	srand(time(NULL));
	//string g3 = "gc500.txt";
	//int n5 = getn(g3);
	//int ** m = load(g3, n5);
	////mdisplay(m, n5);
	//int * kolory5 = easyColoring(m, n5);
	//cout << endl << max(kolory5, n5) << endl;
	Populacja populacja(5, 20, 60);	
	
	//NIE ZROBILEM POPRAWIENIA Z BLEDNEGO NA POPRAWNY

	return 0;
}