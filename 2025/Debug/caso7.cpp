#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define VUELTAS 10
#define INICIAL 100

enum OPCIONES {OPC1, OP2, OP3};

struct completa_t
{
    int campo1;
    int campo2;
    string texto;
};


completa_t cargar (int valor)
{
    completa_t tempo;

    tempo.campo1 = valor + valor;
    tempo.campo2 = valor * valor;
    tempo.texto = "CARGADO";
    
    return tempo;
}

int main (void)
{

    ifstream archivoL;
    int dato = INICIAL;
    int indice;
    completa_t misDatos[10];
    completa_t aux;
    vector <completa_t> larguito;
    char * palabra = "DaleQueVa";
    OPCIONES enumerando;

    int miarray[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    vector <int> mivector;

    enumerando = OPC1;
    enumerando = (OPCIONES) 9;
    archivoL.open("caso6.cpp");

    if(archivoL.is_open())
    {
        for (indice = 0; indice < VUELTAS; indice++)
        {
            misDatos[indice] = cargar (indice);
            aux = cargar (indice+indice);
            larguito.push_back(aux);
            mivector.push_back(indice+1);
        }
    }
    return 0;
}


/*
Ver una variable file
Ver una variable estructura
Ver un vector y un array
Poner breakpoints
Poner mas de un breakpoint y moverse a lo pavo.

Ver posiciones de memoria



Ejecutar paso a paso
Ejecutar hasta el final
Ejecutar paso a paso entrando en las funciones
Pila de llamada a funciones

Variables globales
Variables estáticas

Agregar datos en inspección: Variables, direcciones de memoria, punteros e incluso metodos

Mostrar como desaparecen las variables en locales, o en inspección cuando me voy de la función


Define y enum NOOOOOOO

Diferencia en memoria de como guarda un vector o un array
Y un string?

*/