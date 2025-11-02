/* Hacemos un programa que lea un archivo llamado "Sicuel.txt" y lo muestre por pantalla pero de a una oración por vez.
La oración termina donde haya un punto.
Lee todo el contenido del archivo hasta terminarlo 
*/












#include <iostream>
#include <fstream>

using namespace std; 

int main (void)
{
    ifstream archivoL;
    string frase;
    int contador = 0;

    archivoL.open("Sicuel.txt");

    if(archivoL.is_open())
    {
        while(!archivoL.eof())
        {
            getline(archivoL, frase, '.');
            cout << frase << "." << endl;
            contador++;
        }    

        cout << endl;
        cout << "contador: " << contador << endl;
        archivoL.close();
    }
    else
    {
        cout << "Cosa e mandinga, el archivo no está" << endl;
    }

    return 0;
}