

#include <iostream>
#include <vector>

using namespace std;

vector <int> extraer (int arreglo[], int largo);
void mostrar (vector <int> sonpares );

void matriceria (int matrices [2] [5])
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matrices[i][j] = (i+1)*1000+(j+1);
        }
    }
}

int main(int cant, char ** nada) {
    vector<int> vec = {1, 2, 3, 4, 5};

    int matrices [5][5];
    int i, j;

    matriceria(matrices);
    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << matrices[i][j] << endl;
        }
    }

    // Remove the element at position 2 (third element)
    //vec.erase(vec.at(2));

    // Print the modified vector
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    cout << cant << "    A ver" << endl;

    cout << "0-->" << nada[0] << endl;
    cout << "1-->" << nada[1] << endl;

    return 0;
}

/*
vec.erase(vec.at(2))
*/