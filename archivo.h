#ifndef archivo_h
#define archivo_h

#include <stdio.h>
#include <fstream>
#include <string>
#include "Peliculas.h"

using namespace std;

class Archivo
{
private:

public:
    //Constructor
    //PRE: -.
    //POST: Objeto archivo creado
    Archivo(){};
    //Destructor
    //PRE: Objeto archivo creado
    //Libera recursos, memoria, etc.
    ~Archivo(){};
    bool existeArchivo(ifstream& archivo);
    bool leerArchivos(string nombreArchivoVistas, string nombreArchivoNoVistas, Lista<Peliculas>* pListaVistas, Lista<Peliculas>* pListaNoVistas);
    void cargarLista(ifstream& archivo, Lista<Peliculas>* pLista);
    void cargarListaRecomendadas(Lista<Peliculas>* pListaVistas, Lista<Peliculas>* pListaNoVistas, Lista<Peliculas>* pListaRecomendadas);
    void cargarActores(ifstream& archivo, Peliculas pelicula);
};

#endif /* archivo_hpp */
