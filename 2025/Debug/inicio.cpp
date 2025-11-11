#include <iostream>
#include <string>

using namespace std;


int patodos;

int potencia (int base, int exponente)
{

    static int pepe = 5;

    int i;
    int resu = 1;

    for (i = 0; i < exponente; i++)
    {

        resu *= base;

    }

    patodos = 1234;

    return resu;
}


int main (void)
{
    int bas, exp, resultado;

    cout << "Ingrese la base: ";
    cin >> bas;

    cout << "Ingrese el exponente: ";
    cin >> exp;

    resultado = potencia(bas, exp);

    patodos = 3241;
    cout << bas << "^" << exp << "= " << resultado << endl;


    return 0;
}