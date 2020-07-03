#ifndef archivo_h
#define archivo_h

#include <stdio.h>
#include <fstream>
#include <string>
#include "pelicula.hpp"

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
    bool leerArchivos(string nombreArchivoVistas, string nombreArchivoNoVistas, Lista<Pelicula>* pListaVistas, Lista<Pelicula>* pListaNoVistas);
    void cargarLista(ifstream& archivo, Lista<Pelicula>* pLista);
    void cargarListaRecomendadas(Lista<Pelicula>* pListaVistas, Lista<Pelicula>* pListaNoVistas, Lista<Pelicula>* pListaRecomendadas);
    void cargarActores(ifstream& archivo, Pelicula pelicula);
};

#endif /* archivo_hpp */
