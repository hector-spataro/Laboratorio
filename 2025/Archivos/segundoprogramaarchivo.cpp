/* Hacemos un programa que pida palabras y las escriba en un archivo llamado "prueba1.txt" 
La condición de fin es /salir
Pero ahora, además verificamos que el archivo haya sido abierto, y lo cerramos antes de terminar.

Ej para completar: El nombre del archivo lo recibe por argumento de main.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (void)
{
    string palabra;
    ofstream archivoW;

    archivoW.open("prueba1.txt");
    if (archivoW.is_open())
    {
        cout << "Ingrese palabras (/salir para terminar): " << endl;
        cin >> palabra;

        while (palabra != "/salir")
        {
            archivoW << palabra << endl;
            cin >> palabra;
        }

        archivoW.close();
    }
    else
    {
        cout << "Hubió problemitas para abrir el archivo" << endl;
    }

    return 0;
}






