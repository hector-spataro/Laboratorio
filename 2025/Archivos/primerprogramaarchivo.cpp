/* Hacemos un programa que pida palabras y las escriba en un archivo llamado "prueba1.txt" 
La condición de fin es /salir

Ej para completar: Que en lugar de leer de a palabras, lea de oraciones.
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

    cout << "Ingrese palabras (/salir para terminar): " << endl;
    cin >> palabra;

    while (palabra != "/salir")
    {
        archivoW << palabra << endl;
        cin >> palabra;
    }
    

    return 0;
}






