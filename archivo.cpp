#ifndef archivo_h
#define archivo_h

#include <stdio.h>
#include <fstream>
#include <string>
#include "lista.h"

using namespace std;

class Archivo
{
private:
    ifstream archivoVistas;
    ifstream archivoNoVistas;
public:
    //Constructor
    //PRE: -.
    //POST: Objeto archivo creado
    Archivo(string nombreArchivoVistas, string nombreArchivoNoVistas);
    //Destructor
    //PRE: Objeto archivo creado
    //Libera recursos, memoria, etc.
    ~Archivo();
    //Carga la lista con la info del archivo que contiene las figuras
    //PRE: nombre del archivo como string y un puntero a lista
    //POST: Devuelve el puntero a la lista cargada
    bool existeArchivo(ifstream &archivo);
    void cargarLista(ifstream &archivo,Lista<Peliculas>* pLista);
    void leerArchivos();
    void cargarRecomendadas();
};
#endif /* archivo_h */
