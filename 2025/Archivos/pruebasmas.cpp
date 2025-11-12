#include <iostream>
#include <fstream>

using namespace std; 

int main (void)
{
    ofstream archivoE1, archivoE2;
    ifstream archivoL1, archivoL2;
    string nombreArch1, nombreArch2;
    int contador = 0;

    archivoE1.open("Nums.txt");
    archivoE2.open("Nums.bin", ios::binary);
    if(archivoE2.is_open() && archivoE1.is_open())
    {
        for (contador = 90; contador < 100; contador++)
        {
            archivoE1 << contador << endl;
            archivoE2.write((char*) &contador, sizeof(int));
        }
        archivoE1.close();
        archivoE2.close();

        archivoL1.open("Nums.txt");
        if(archivoL1.is_open())
        {
            while (!archivoL1.eof())
            {
                archivoL1 >> contador;
                cout << contador << endl;
            }
            archivoL1.close();
        }

        archivoL2.open("Nums.bin", ios::binary);
        if(archivoL2.is_open())
        {
            while (!archivoL2.eof())
            {
                archivoL2.read((char*) &contador, sizeof(int));
                cout << contador << endl;
            }
            archivoL2.close();
        }
    }
    else
    {
        cout << "no, no" << endl;
    }
    
    return 0;
}