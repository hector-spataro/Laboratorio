#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define VUELTAS 10
#define INICIAL 100

struct completa_t
{
    int campo1;
    int campo2;
    string texto;
};


int main (void)
{

    int dato = INICIAL;
    int indice;
    completa_t misDatos;

    misDatos.campo1 = 5;
    misDatos.campo2 = 10;
    misDatos.texto = "Guardar";

    return 0;
}


/*
Ver una variable file
Ver una variable estructura
Ver un vector
Poner breakpoints
Ver posiciones de memoria



Ejecutar paso a paso
Ejecutar hasta el final
Ejecutar paso a paso entrando en las funciones
Pila de llamada a funciones

Variables globales
Variables estáticas

Agregar datos en inspección

Mostrar como desaparecen las variables en locales, o en inspección cuando me voy de la función
Poner mas de un breakpoint y moverse a lo pavo.
*/