#pragma warning(disable : 4996)
#include <iostream>
#include "angajat.h"
using namespace std;

int main()
{
    angajat a,b,d;
    angajati c(0);
    cin >> a>>b>>d;
    c.inserare(a);
    c.inserare(b);
    c.inserare(d);
    c.sortare();
    c.parcurgere();
    
}

