/*
1) Realizar un programa que cree un vector 
2) Pedirle al usuario la cantidad de elementos a poner en el vector
3) Cargar el vector con números aleatorios enteros (el rango de valores será entre 0 y la cantidad de valores * 100)
4) Mostrar el vector
5) Ordenarlo de menor a mayor con alguno de los tres métodos vistos la clase pasada.
6) Pedirle al usuario un valor a buscar
7) Buscarlo con búsqueda binaria
8) Mostrar la posición donde se encuentra el valor o avisar si no se encontró.
*/

#include <iostream>
#include <vector>

using namespace std;

void burbuja (vector <int> &arreglo)
{
    int j=0, i, aux;
    int largo = arreglo.size();
    bool desordenado = true;

    while (desordenado) 
    {
	    j++;
	    desordenado = false;

        for (i = 0; i < largo-j; i++) 
        {
		    if (arreglo[i] > arreglo[i+1]) 
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[i+1];
                arreglo[i+1] = aux;
                desordenado = true;
            }
        }
    }
    return;
}

int busqueda_binaria(vector <int> arreglo, int elemento)
{
    int inf = 0, sup = arreglo.size() - 1, mitad, resu = -1;
    bool sigue;

    if(inf <= sup)
    {
        sigue = true;
    }

    while(sigue)
    {
        mitad = (inf + sup) / 2;

        if (arreglo[mitad] == elemento){
            resu = mitad;
            sigue = false;
        }
        else if(inf > sup)
        {
            sigue = false;
        }
        else if (arreglo[mitad] > elemento){
            sup = mitad - 1;
        }
        else if (arreglo[mitad] < elemento){
            inf = mitad + 1;
        }
    }

    return resu;
}

int main (void)
{
    vector <int> secuencia;
    int cantidad, valor, i, resu;

    srand(time(NULL));

    cout << "Ingrese la cantidad de valores a generar: ";
    cin >> cantidad;

    for (i = 0; i < cantidad; i++)
    {
        secuencia.push_back(rand()%(cantidad*100));
    }

    for (int i : secuencia)
    {
        cout << i << "\t";
    }

    cout << endl;

    burbuja(secuencia);

    for (int i : secuencia)
    {
        cout << i << "\t";
    }

    cout << endl;

    cout << "Ingrese el valor que desea buscar: ";
    cin >> valor;

    resu = busqueda_binaria(secuencia, valor);

    if (resu == -1)
    {
        cout << "No se encontró el valor." << endl;
    }
    else
    {
        cout << "El valor buscado está en la posición: " << resu << endl;
    }

    return 0;
}