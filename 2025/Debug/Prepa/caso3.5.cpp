#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define VUELTAS 10
#define INICIAL 100

int esGlobal;

void paraGlobal ()
{
    esGlobal++;
}


int incremento (int valor)
{
    int olvidate = 12345;
    valor = valor + valor;
    static int soloAca = 50;

    esGlobal++;
    soloAca--;
    olvidate++;

    paraGlobal();

    return valor;
}


int main (void)
{

    int dato = INICIAL;
    int indice;
    int arreglo[10];
    vector <int> conjunto;

    esGlobal = 1000;
    
    for (indice = 0; indice < VUELTAS; indice++)
    {
        dato = incremento (dato);
        arreglo[indice] = dato+indice;
        conjunto.push_back(indice*indice);
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
Pila de llamada a funciones

Variables globales
Variables estáticas

Agregar datos en inspección
*/