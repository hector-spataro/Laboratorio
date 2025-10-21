/*
Paso 1:
Realizar un programa que pida valores reales al usuarioy los guarde en un archivo binario.
La carga finaliza cuando ingresa el valor 0.

Paso 2:
Realizar un programa que abra el archivo generado en el punto 1 y genere un archivo de texto con un dato por línea

Paso 3:
Leer el archivo de texto generado en el punto 2 y volver a generar un archivo binario con esos valores.

Paso 4:
Utilizar el programa que hicimos la clase pasada y verificar quelos archivos generados en el programa 1 y en el pprogrma 3 son iguales.

Nota:
Para que lo tengan todo junto, lo resolví en un solo programa haciendo 3 pasos.
Pero la función de cada paso, tranquilamente puede ser un main y un programa separado.
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define archivo1 "paso1.bin"
#define archivo2 "paso2.txt"
#define archivo3 "paso3.bin"

bool pasoUno (void)
{
    float valor;
    ofstream archivoW1;
    bool ando = true;

    archivoW1.open(archivo1, ios::binary);
    if (archivoW1.is_open())
    {
        cout << "Ingrese valores reales (ingrese 0 para finalizar)" << endl;
        cin >> valor;

        while (valor)
        {
            archivoW1.write((char *) &valor, sizeof(valor));
            cin >> valor;
        }
        archivoW1.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
        ando = false;
    }
    return ando;
}

bool pasoDos (void)
{
    float valor;
    ifstream archivoR1;
    ofstream archivoW1;
    bool ando = true;

    archivoR1.open(archivo1, ios::binary);
    archivoW1.open(archivo2);
    if (archivoR1.is_open() and archivoW1.is_open())
    {
        archivoR1.read((char *) &valor, sizeof(valor));
            
        while (!archivoR1.eof())
        {
            archivoW1 << valor << endl;
            archivoR1.read((char *) &valor, sizeof(valor));
        }
        archivoR1.close();
        archivoW1.close();
    }
    else
    {
        cout << "No se pudo abrir por lo menos un archivo." << endl;
        if (archivoR1.is_open()) cout << "Archivo: " << archivo1 << " OK" << endl;
        else cout << "Archivo: " << archivo1 << " ERROR" << endl;
        if (archivoW1.is_open()) cout << "Archivo: " << archivo2 << " OK" << endl;
        else cout << "Archivo: " << archivo2 << " ERROR" << endl;        
        ando = false;        
    }
    return ando;
}

bool pasoTres (void)
{
    float valor;
    ifstream archivoR1;
    ofstream archivoW1;
    bool ando = true;

    archivoR1.open(archivo2);
    archivoW1.open(archivo3, ios::binary);
    if (archivoR1.is_open() and archivoW1.is_open())
    {
        
        archivoR1 >> valor;
            
        while (!archivoR1.eof())
        {
            archivoW1.write((char *) &valor, sizeof(valor));
            archivoR1 >> valor;
        
        }
        archivoR1.close();
        archivoW1.close();
    }
    else
    {
        cout << "No se pudo abrir por lo menos un archivo." << endl;
        if (archivoR1.is_open()) cout << "Archivo: " << archivo2 << " OK" << endl;
        else cout << "Archivo: " << archivo2 << " ERROR" << endl;
        if (archivoW1.is_open()) cout << "Archivo: " << archivo3 << " OK" << endl;
        else cout << "Archivo: " << archivo3 << " ERROR" << endl;        
        ando = false;
    }
    return ando;
}


int main (void)
{
    bool volvioOK;

    cout << "Paso 1: Pedir datos y generar un archivo binario.............." << endl;
    volvioOK = pasoUno( );

    if (volvioOK)
    {
        cout << "Paso 2: Pedir datos y generar un archivo binario.............." << endl;
        volvioOK = pasoDos( );

        if (volvioOK)
        {
            cout << "Paso 1: Pedir datos y generar un archivo binario.............." << endl;
            volvioOK = pasoTres( );
        }

    }    
    
    if (volvioOK)
    {
        cout << "Proceso finalizado exitosamente." << endl;
    }
    else
    {
        cout << "Proceso finalizado con error." << endl;
    }

    return 0;
}