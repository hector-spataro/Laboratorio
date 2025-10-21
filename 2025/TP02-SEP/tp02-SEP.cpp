#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

#define OK 1
#define SI 1
#define NO 0
#define MILLO 1000000

struct estacion_t
{
    float lgtd;
    float lltd;
    string id;
    int valor;
};


string nombreID (string idT, int idN)
{
    string resu;

    resu = idT + to_string(idN);

    return resu;
}

int cargaVector (vector <estacion_t> & listado, int cant, string idT)
{
    int retorno = OK;
    int i, aux;
    estacion_t tempo;
    
    for (i = 0; i < cant; i++)
    {
        //float lgtd (número generado aleatoriamente entre -180 y +180 con 6 decimales)
        tempo.lgtd = (float) (rand()%(360*MILLO+1)-(180*MILLO))/MILLO;
       // tempo.lgtd = (rand()%360000001-180000000)/1000000.0;
        tempo.lltd = (float) (rand()%(360*MILLO+1)-(180*MILLO))/MILLO;
        aux = rand()%(9999-1000+1)+1000;
        //string id (nombre generado a través de la función nombreId)
        tempo.id = nombreID (idT, aux);
        //int valor (es un valor entero generado aleatoriamente entre 100.000 y 999.999)
        tempo.valor = rand()%(999999-100000+1)+100000;
        listado.push_back(tempo);
    }
    return retorno;
}

void mostrarVector (vector <estacion_t> listado)
{
    int i;

    cout << "los valores del vector son: " << endl;

    for (i = 0; i < listado.size(); i++)
    {
        //[lgtd, lltd]:id = valor
        cout << "\t[" << listado[i].lgtd << ", " << listado[i].lltd << "]: " << listado[i].id << " = " << listado[i].valor << endl;

    }
    return;
}

void ordenar(vector <estacion_t> & listado)
{
    int i;

    if(listado[i].id > listado[i+1].id)

    return;
}
string buscarValor(vector <estacion_t> listado, int buscar)
{
    string estacion = "";



    return estacion;
}

int main (int argc, char * argv [])
{
    int cant, resu;
    vector <estacion_t> listado;
    int buscar;
    string estacion;

    if(argc == 3)
    {
        srand(time(NULL));

        cant = stoi(argv[1]);
        resu = cargaVector (listado, cant, argv[2]);
        if (resu == OK)
        {
            ordenar(listado);
            mostrarVector(listado);
            cout << "Ingrese el valor a buscar: ";
            cin >> buscar;
            estacion = buscarValor(listado, buscar);
            if (estacion.empty())
            {
                cout << "No de se encontró el valor." << endl;
            }
            else
            {
                cout << "La estación con ese valor es: " << estacion << endl;
            }
            
        }        
    }
    else
    {
        cout << "Así no se puede laburar, viejo" << endl;
    }
}


