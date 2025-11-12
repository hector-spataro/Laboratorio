#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define VALORES 5
#define MAXIMO 5

struct datos_t
{
    int entero1;
    int entero2;
    char letra;
    string texto;
};

struct datos2_t
{
    int entero1;
    int entero2;
    char letra;
    char texto[MAXIMO];
};

vector <datos_t> cargar (int cuantos)
{
    int i;
    datos_t aux;
    vector <datos_t> listado;
    vector <string> nombres = {"Juan", "Alan", "Mari", "Ceci", "Beto", "Viki", "Teod", "Toad", "Tito", "Tita"};

    for (i = 0; i < cuantos; i++)
    {
        aux.entero1 = rand();
        aux.entero2 = rand();
        aux.letra = rand()%24+'A';
        aux.texto = nombres[rand()%10];
        listado.push_back(aux);
    }

    return listado;
}

void metonombre (char * destino, string origen)
{
    int i;

    for (i = 0; i < MAXIMO; i++)
    {
        destino[i] = origen[i];
    }
}

vector <datos2_t> cargar2 (int cuantos)
{
    int i;
    datos2_t aux;
    vector <datos2_t> listado;
    vector <string> nombres = {"Juana", "Juan", "Maria", "Mario", "Cecilia", "Cecilio", "Alberto", "Alberta", "Tito", "Tita"};

    for (i = 0; i < cuantos; i++)
    {
        aux.entero1 = rand();
        aux.entero2 = rand();
        aux.letra = rand()%24+'A';
        metonombre(aux.texto, nombres[rand()%10]);
        listado.push_back(aux);
    }

    return listado;
}

int main (void)
{       
    vector <datos_t> valor;
    vector <datos2_t> valor2;
    
    int i;

    srand(time(NULL));

    valor = cargar(VALORES);
    valor2 = cargar2(VALORES);

    for (i = 0; i < VALORES; i++)
    {
        cout << "------ Registro: " << i+1 << "----------" << endl;
        cout << "Entero1: " << hex << valor[i].entero1 << endl;
        cout << "Entero2: " << hex << valor[i].entero2 << endl;
        cout << "Letra: " << valor[i].letra << endl;
        cout << "String: " << valor[i].texto << endl;
        cout << "------------------------------" << endl;
    }

    for (i = 0; i < VALORES; i++)
    {
        cout << "------ Registro: " << i+1 << " ----------" << endl;
        cout << "Entero1: " << hex << valor2[i].entero1 << endl;
        cout << "Entero2: " << hex << valor2[i].entero2 << endl;
        cout << "Letra: " << valor2[i].letra << endl;
        cout << "String: " << valor2[i].texto << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}