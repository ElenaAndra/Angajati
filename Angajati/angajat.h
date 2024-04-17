#pragma once
#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

class angajat{

private:
	char nume[15], prenume[15], functie[20];
	int varsta, zile_concediu;
	double salariu;
public:
	angajat();
	angajat(char n[15], char pr[15], char fun[20], int v, int z_c, double sal);
	friend istream& operator>>(istream& in, angajat& t);
	void operator=(angajat a);
	friend ostream& operator<<(ostream& out, const angajat& t);
	void salariu_new();
	char* GetNume();
	int GetZile();
};

class angajati {

private:
	angajat *v;
	int n;
public:
	angajati();
	angajati(int n);
	void inserare(angajat pers);
	friend ostream& operator<<(ostream& out, const angajati& t);
	void stergere(int poz);
	void sortare();
	void parcurgere();
	void meniu();
};

