#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define VALORES 10

int main (void)
{
    int i;
    int numeros[VALORES];
    vector <int> masNumeros;
    vector <char> masLetras;

    for (i = 0; i < VALORES; i++)
    {
        numeros[i] = 1483358229 + (i * 10);
        cout << hex << numeros[i];
        masNumeros.push_back(1483358229 + (i * 100));
        cout << hex << "\t\t" << masNumeros[i];
        masLetras.push_back('A'+i);
        cout << "\t\t" << masLetras[i] << endl;
    }
       
    return 0;
}