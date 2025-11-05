/*
Realizar un programa que me permita cargar mi base de datos de juegos
Tendrá un menú que me permite agregar datos, mostrarlos y salir.

Agregamos las funcionalidades de borrar y modificar (hay que agregarlas en el menu, ya están en el enum)
La busqueda es por nombre. Si hay dos juegos con el mismo nombre, pregunto la versión. Sino, elijo ese juego.

Al iniciar el programa debo leer el archivo datos.bin y cargar el listado de juegos que ya habia ingresado en 
otra oportunidad

Version 5:
Agregamos la funcionalidad de usuario e idioma.
1) Recibe por argumento de main un nombre de usuario
2) Abre el archivo usuario.cfg, busca ese usuario y extrae el idioma para ese usuario
3) Abre el archivo con las opciones en el idioma correspondiente y carga las opciones en un vector para mostrar el menú
4) Muestra el archivo correspondiente
5) Formato de archivos
----> usuario.cfg
userid:xx
Ej:
    hector:ES
    franco:ES
    nicolas:EN

El reconocimiento del usuario no deber diferenciar entre mayúsculas y minúsculas.
Debe definir un idioma por defecto si no existe el usuario o no existe el idioma pedido.

----> menuXX.txt
El menú de idioma tendrá una opción por línea en el orden correspondiente al menú.

Ejemplo para menuES.txt
    Elija una opción:
    Agregar Juego
    Borrar Juego
    Modificar Juego
    Mostrar Juegos
    Guardar Juegos en un archivo
    Salir

Ejemplo para menuEN.txt
    Chose an option:
    Add game
    Delete game
    Modify game
    Print games
    Save games in a file
    Exit

Version 6:
El archivo de usuario ahora tiene el formato
userid:ID:PR:Clave
donde 
    userid es el nombre de usuario
    ID es el idioma (ejemplo ES, EN)
    PR es el nivel del privilegio (puede ser US -usuario- o AD -administrador-)
    Clave es la clave del usuario encriptado con ROT13/ROT5

Entonces:
    Si el usuario tiene privilegio de administrador, puede hacer todo.
    Sino, puede hacer todo MENOS agregar y borrar juegos. Cuando muestra el menú no puede mostrar esas opciones.

    Cuando inicia el programa, pide la contraseña del usuario y verifica que sea la que está grabada en el archivo.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum OPCIONES {AGREGAR = 1, BORRAR, MODIFICAR, LISTAR, GUARDAR, SALIR}; 
enum PRIVILEGIOS {NOENTRO, USUARIO, ADMINISTRADOR}; 

#define ARCHIVOTXT "salida.txt"
#define ARCHIVOBIN "datos.bin"
#define ARCHIVOCFG "usuario.cfg"
#define ARCHIVOLENG "menu"

#define LARGO 40

struct fecha_t
{
    int dia;
    char mes[LARGO];
    int anio;
};

struct juego_t
{
    char nombre[LARGO]; //Nombre del juego
    char version[LARGO];//Versión del tipo 1.47.12
    fecha_t instalado;  //Fecha de instalación, formato con tres datos, día, nombre del mes y año    
    fecha_t usado;      //Fecha que lo usamos por ultima vez
    int nivel;          //Maximo nivel alcanzado (número)
    float calif;        //Que calificación le ponemos (número de 0 a 5 con un decimal)
};

/*
Opción UNO de carga: Directamente en el vector
Función: agregarJuegoUNO
*/

void agregarJuegoUNO (vector <juego_t *> & listado)
{
    int datop = listado.size();
    listado.push_back(new juego_t);

    cin.ignore();
    cout << "Ingrese el nombre del juego: ";
    cin.getline((listado[datop])->nombre, LARGO);
    cout << "Ingrese la versión: ";
    cin >> (listado[datop])->version;
    cout << "Ingrese el día de la instalación: ";
    cin >> (listado[datop])->instalado.dia;     
    cout << "Ingrese el mes de la instalación (nombre del mes): ";
    cin >> (listado[datop])->instalado.mes;     
    cout << "Ingrese el año de la instalación: ";
    cin >> (listado[datop])->instalado.anio;     
    cout << "Ingrese el día que lo uso por última vez: ";
    cin >> (listado[datop])->usado.dia;     
    cout << "Ingrese el mes que lo uso por última vez (nombre del mes): ";
    cin >> (listado[datop])->usado.mes;     
    cout << "Ingrese el año que lo uso por última vez: ";
    cin >> (listado[datop])->usado.anio;     
    cout << "Ingrese el máximo nivel alcanzado: ";
    cin >> (listado[datop])->nivel;
    cout << "Ingrese el puntaje que le otorga al juego (0 a 5 con un decimal): ";
    cin >> (listado[datop])->calif;

    return;
}
    
/*
Opción DOS de carga: A través de variables auxiliares
La ventaja de este método es que la función para agregar juegos es siempre la misma.
Si cambian los campos de la estructura solo modifico la función de carga.
Funciones: agregarJuegoDOS, nuevoJuego y nuevaFecha
*/

fecha_t nuevaFecha (void)
{
    fecha_t nueva;

    cout << "Ingrese el día: ";
    cin >> nueva.dia;     
    cout << "Ingrese el mes (nombre del mes): ";
    cin >> nueva.mes;     
    cout << "Ingrese el año: ";
    cin >> nueva.anio;
    
    return nueva;  
}

juego_t nuevoJuego(void)
{
    juego_t nuevo;

    cin.ignore();
    cout << "Ingrese el nombre del juego: ";
    cin.getline(nuevo.nombre, LARGO);
    cout << "Ingrese la versión: ";
    cin >> nuevo.version;
    cout << "Ingrese la fecha de instalación" << endl;
    nuevo.instalado = nuevaFecha();
    cout << "Ingrese la fecha que lo usó por última vez" << endl;
    nuevo.usado = nuevaFecha();
    cout << "Ingrese el máximo nivel alcanzado: ";
    cin >> nuevo.nivel;
    cout << "Ingrese el puntaje que le otorga al juego (0 a 5 con un decimal): ";
    cin >> nuevo.calif;

    return nuevo;
}

void agregarJuegoDOS (vector <juego_t *> & listado)
{
    juego_t * pAuxD = new juego_t;
    
    *pAuxD = nuevoJuego();
    listado.push_back(pAuxD);

    return;
}


void mostrarJuegos (vector <juego_t *> listado)
{
    int i;

    if (listado.empty())
    {
        cout << "***** No hay programas instalados. *****" << endl << endl;
    }
    else 
    {
        cout << "***** Los programas instalados son: *****" << endl;

        for ( i = 0; i < listado.size() ; i++)
        {
            // A continución va de las dos formas que se pueden acceder a los campos.
            // Una forma la use para el nombre y a otra para la versión.
            cout << "\tNombre: " << (listado[i])->nombre;
            cout << "\t- Versión: " << (*(listado[i])).version << endl;
            // Las dos formas para ver las estructuras anidadas
            cout << "\tUsada por última vez el " << (listado[i])->usado.dia;
            cout << " - " << (*(listado[i])).usado.mes << " - " << (*(listado[i])).usado.anio << endl;
            
            cout << "----------------------------------------" << endl;
        }
    }
    return;
}

void guardarJuegos (vector <juego_t *> listado)
{
    int i;
    ofstream archivoW;

    archivoW.open(ARCHIVOTXT);

    if(archivoW.is_open())
    {

        if (listado.empty())
        {
            archivoW << "***** No hay programas instalados. *****" << endl << endl;
        }
        else 
        {
            archivoW << "***** Los programas instalados son: *****" << endl;

            for ( i = 0; i < listado.size() ; i++)
            {
                // A continución va de las dos formas que se pueden acceder a los campos.
                // Una forma la use para el nombre y a otra para la versión.
                archivoW << "\tNombre: " << (listado[i])->nombre;
                archivoW << "\t- Versión: " << (*(listado[i])).version << endl;
                // Las dos formas para ver las estructuras anidadas
                archivoW << "\tUsada por última vez el " << (listado[i])->usado.dia;
                archivoW << " - " << (*(listado[i])).usado.mes << " - " << (*(listado[i])).usado.anio << endl;
                archivoW << "\tinstalada el " << (listado[i])->instalado.dia;
                archivoW << " - " << (*(listado[i])).instalado.mes << " - " << (*(listado[i])).instalado.anio << endl;
                archivoW << "\tMax. Nivel: " << (*(listado[i])).nivel << endl;
                archivoW << "\tCalificacion: " << (*(listado[i])).calif << endl;
                archivoW << "----------------------------------------" << endl;
            }
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo de salida." << endl;
    }
    return;
}

void salvar (vector <juego_t *> listado)
{
    int i;
    ofstream archivoW1;

    archivoW1.open(ARCHIVOBIN,ios::binary);
    if (archivoW1.is_open())
    {
        for ( i = 0; i < listado.size(); i++)
        {
            cout << "Tamaño: " << sizeof(juego_t) << endl;
            archivoW1.write((char *) listado[i], sizeof(juego_t));
        }

        archivoW1.close();
    }
    return;
}

void recarga (vector <juego_t *> & listado)
{
    juego_t * pAuxD;
    ifstream archivoR1;

    archivoR1.open(ARCHIVOBIN,ios::binary);
    if (archivoR1.is_open())
    {
        while (!archivoR1.eof())
        {
            pAuxD = new juego_t;            
            archivoR1.read((char *) pAuxD, sizeof(juego_t));
            if (!archivoR1.eof())
            {
                listado.push_back(pAuxD);
            }
        }
        archivoR1.close();
    }
    return;
}


PRIVILEGIOS verUsuarioP (string userid)
{
    juego_t * pAuxD;
    ifstream archivoR1;
    PRIVILEGIOS permisos;

    archivoR1.open(ARCHIVOBIN,ios::binary);
    if (archivoR1.is_open())
    {
        while (!archivoR1.eof())
        {
            pAuxD = new juego_t;            
            archivoR1.read((char *) pAuxD, sizeof(juego_t));
            if (!archivoR1.eof())
            {
                
            }
        }
        archivoR1.close();
    }
    return permisos;
}

string verUsuarioI (string userid)
{
    juego_t * pAuxD;
    ifstream archivoR1;
    string idioma;

    archivoR1.open(ARCHIVOBIN,ios::binary);
    if (archivoR1.is_open())
    {
        while (!archivoR1.eof())
        {
            pAuxD = new juego_t;            
            archivoR1.read((char *) pAuxD, sizeof(juego_t));
            if (!archivoR1.eof())
            {
                
            }
        }
        archivoR1.close();
    }
    return idioma;
}

vector <string> cargarMensajes (string idioma)
{
    juego_t * pAuxD;
    ifstream archivoR1;
    vector <string> mensajes;

    archivoR1.open(ARCHIVOBIN,ios::binary);
    if (archivoR1.is_open())
    {
        while (!archivoR1.eof())
        {
            pAuxD = new juego_t;            
            archivoR1.read((char *) pAuxD, sizeof(juego_t));
            if (!archivoR1.eof())
            {
                
            }
        }
        archivoR1.close();
    }
    return mensajes;
}

int main (int argc, char * argv[])
{
    int opcion;
    bool salgo = false;
    string userid;
    vector <juego_t *> listado;
    vector <string> opcionesM;
//    vector <string> opcionesM = { "Elija una opción: ", "Agregar Juego", "Borrar Juego", "Modificar Juego", "Mostrar Juegos", "Guardar Juegos en un archivo", "Salir"};
    int permisos;
    string idioma;

    if (argc > 1)
    {
        userid = argv[1];
    }
    else
    {
        userid = "";
    }

    recarga(listado);

    permisos = verUsuarioP(userid);
    
    if (permisos != NOENTRO)
    {
        idioma = verUsuarioI(userid);

        cargarMensajes(idioma);

        while (!salgo)
        {
            cout << opcionesM[0] << endl;
            if (permisos > USUARIO) cout << "\t" << AGREGAR << " - " << opcionesM[1] << endl;
            if (permisos > USUARIO) cout << "\t" << BORRAR << " - " << opcionesM[2] << endl;
            cout << "\t" << MODIFICAR << " - " << opcionesM[3] << endl;
            cout << "\t" << LISTAR << " - " << opcionesM[4] << endl;
            cout << "\t" << GUARDAR << " - " << opcionesM[5] << endl;
            cout << "\t" << SALIR << " - " << opcionesM[6] << endl;
            cout << "\t---> ";
            cin >> opcion; 
            
            switch (opcion) {
                case AGREGAR:
                    agregarJuegoDOS(listado);
                    // Se puede cambiar esta linea por "agregarJuegoUNO(listado);" para usar el otro método
                    break;
                case BORRAR:
                    
                    break;
                case MODIFICAR:
                    
                    break;
                case LISTAR:
                    mostrarJuegos(listado);
                    break;
                case GUARDAR:
                    guardarJuegos(listado);
                    break;            
                case SALIR:
                    salvar(listado);
                    salgo = true;
                    break;            
                default:
                    cout << "Que te crees, que podés poner cualquier cosa?????";
                    break;        
            }
        }
    }
    else
    {
        cout << "Login invalido. Chau......" << endl;
    }
    return 0;
}








