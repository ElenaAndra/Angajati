#pragma warning(disable : 4996)
#include "angajat.h"
#include <cstring>
using namespace std;

angajat::angajat() {}

angajat::angajat(char n[15], char pr[15], char fun[20], int v, int z_c, double sal) {

	strcpy(this->nume, n);
	strcpy(this->prenume, pr);
	strcpy(this->functie, fun);
	this->varsta = v;
	this->zile_concediu = z_c;
	this->salariu = sal;
}

istream& operator>>(istream& in, angajat& t) {
	cout << "Nume si prenume: ";
	in >> t.nume >> t.prenume;
	cout << "Functie: ";
	in >> t.functie;
	cout << "Varsta: ";
	in >> t.varsta;
	cout << "Zile de concediu: ";
	in >> t.zile_concediu;
	cout <<"Salariu: ";
	in >> t.salariu;

	return in;
}

ostream& operator<<(ostream& out, const angajat& t) {
	out << t.nume<<" "<<t.prenume<<" "<<t.functie<<" "<<t.varsta<<" "<<t.salariu<<" " << t.zile_concediu << endl;
	
	return out;
}

angajati::angajati(){}

angajati::angajati(int n) {
	this->n = n;
	this->v = new angajat[n];
}

void angajat::operator=(angajat a) {
	strcpy(this->nume, a.nume);
	strcpy(this->prenume, a.prenume);
	strcpy(this->functie, a.functie);
	this->varsta = a.varsta;
	this->salariu = a.salariu;
	this->zile_concediu = a.zile_concediu;
}

void angajati::inserare(angajat pers) {
	this->n = this->n + 1;
	angajat* temp = new angajat[this->n];

	for (int i = 0; i < this->n - 1;i++) {
		temp[i] = this->v[i];
	}
	temp[n - 1] = pers;

	delete this->v;

	this->v = new angajat[this->n];
	for (int i = 0; i < this->n; i++) {
		this->v[i] = temp[i];
	}

	delete temp;
}

ostream& operator<<(ostream& out, const angajati& t) {
	
	for (int i = 0; i < t.n; i++) {
		out <<i+1<<". " << t.v[i]<<endl;
	}

	return out;
}

void angajat::salariu_new() {

	int new_sal;
	cin >> new_sal;
	this->salariu = new_sal;
}

void angajati::stergere(int p) {

	
	for (int i = p-1; i < this->n-1; i++) {
		this->v[i] = this->v[i + 1];
	}
	angajati temp(this->n - 1);
	temp.v = new angajat[temp.n];   

	for (int i = 0; i < temp.n; i++) {
		temp.v[i] = this->v[i];
	}
	delete this->v;

	this->v = new angajat[temp.n];
	this->n = temp.n;
	for (int i = 0; i < this->n; i++) {
		this->v[i] = temp.v[i];
	}
	delete temp.v;
}

char* angajat::GetNume() {

	return this->nume;
}

void angajati::sortare() {
	for (int i = 0; i < this->n-1; i++) {
		for (int j = i + 1; j < this->n; j++) {
			if (strcmp(this->v[i].GetNume(), this->v[j].GetNume())> 0) {
				swap(this->v[i], this->v[j]);
			}
		}
	}
}

int angajat::GetZile() {

	return this->zile_concediu;
}

void angajati::parcurgere() {

	for (int i = 0; i < this->n; i++) {
		if (this->v[i].GetZile() > 0) {
			cout << this->v[i];
		}
	}
}