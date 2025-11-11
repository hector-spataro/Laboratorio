#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define VUELTAS 10
#define INICIAL 100

int incremento (int valor)
{
    valor = valor + valor;
    
    return valor;
}


int main (void)
{

    int dato = INICIAL;
    int indice;
    
    for (indice = 0; indice < VUELTAS; indice++)
    {
        dato = incremento (dato);
    }

    return 0;
}


/*
Ver una variable file
Ver una variable estructura
Poner breakpoints
Ver posiciones de memoria



Ejecutar paso a paso
Ejecutar hasta el final
Ejecutar paso a paso entrando en las funciones
*/