#include <iostream>
#include <string>

using namespace std;

int potencia (int base, int exponente)
{

    int i;
    int resu = 1;

    for (i = 0; i < exponente; i++)
    {

        resu *= base;

    }

    return resu;
}


int suma (int oper1, int oper2)
{
    int resu = 1;

    resu = oper1 + oper2;
    
    return resu;
}

int resta (int oper1, int oper2)
{
    int resu = 1;

    resu = oper1 - oper2;
    
    return resu;
}

int main (void)
{
    int oper1, oper2, operacion, resultado;

    cout << "Ingrese el oper1: ";
    cin >> oper1;

    cout << "Ingrese el oper2: ";
    cin >> oper2;

    cout << "Ingrese operación (1-Potencia / 2-Suma / 3-Resta / 4-Salir): ";
    cin >> operacion;

    switch (operacion)
    {
        case 1:
            cout << oper1 << " ^ " << oper2 << " = " << potencia(oper1, oper2) << endl;
            break;
        case 2:
            cout << oper1 << " + " << oper2 << " = " << suma(oper1, oper2) << endl;
            break;
        case 3:
            cout << oper1 << " - " << oper2 << " = " << resta(oper1, oper2) << endl;
            break;
        case 4:
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
    }
    
    if (operacion != 4) main();

    return 0;
}