#include <iostream>
#include <string>

using namespace std;


int patodos;

int potencia (int base, int exponente)
{

    static int pepe;
    int pepe1 = 1;

    pepe = 42;

    int i;
    int resu = 1;

    for (i = 0; i < exponente; i++)
    {

        resu *= base;

    }

    patodos = 1234;
    cout << "Ejecuté potencia " << pepe << " veces" << endl;
    pepe++;

    cout << "Ejecuté potencia (pepe1)" << pepe1 << " veces" << endl;
    pepe1++;

    return resu;
}


int main (void)
{
    int bas, exp, resultado, i;

    //for (i = 0; i < 3; i++)
    //{
        cout << "Ingrese la base: ";
        cin >> bas;

        cout << "Ingrese el exponente: ";
        cin >> exp;

        resultado = potencia(bas, exp);

        patodos = 3241;
        cout << bas << "^" << exp << "= " << resultado << endl;
    //}

    main();
    main();
    main();

    return 0;
}