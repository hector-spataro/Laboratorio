#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define VALORES 10

int main (void)
{
    int i;

    char mensaje[10] = "Hola";
    string texto;

    texto = "Hola Mundo";
    
    i =strlen(mensaje);
    cout << mensaje << endl;
    i =strlen(texto.c_str());
    cout << texto << endl;
       
    return 0;
}