#include <iostream>
#include <fstream>

using namespace std; 

int main (void)
{
    ofstream archivoL;
    ifstream archivoR;
    fstream patodo;
    string nombreArch;
    string frase;
    int contador = 0;

    cout << "nombre" << endl;
    cin >> nombreArch;
    archivoR.open(nombreArch);
    //if(archivoR.fail())
    if(archivoR)
    {
        cout << "no, no" << endl;
        cout << "no, no" << endl;
    }
    else
    {
        cout << "si, si" << endl;
        while(archivoR >> contador)
        {
            cout << "Leido: " << contador << endl;
        }
    }
    
/*
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
*/
    return 0;
}