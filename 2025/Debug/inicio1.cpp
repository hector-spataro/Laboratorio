#include <iostream>
#include <string>

using namespace std;

int main (void)
{
    int i, resultado = 0;

    for (i = 0; i < 10; i++);
    {
        cout << "Pase por aca" << endl;
        resultado++;
    }
    
    cout << "Guauuu, mirá lo que vale resultado: " << resultado << endl;

    return 0;
}