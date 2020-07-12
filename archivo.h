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
    //POST: Objeto archivo creado.
    Archivo(){};
    //Destructor
    //PRE: Objeto archivo creado.
    //Libera recursos, memoria, etc.
    ~Archivo(){};
    //PRE: Variable archivo de lectura por parametro.
    //POST: Devuelve booleana depende de si se pudo abrir el archivo o no.
    bool existeArchivo(ifstream& archivo);
    //PRE: Dos strings y dos punteros a lista de peliculas, una por cada archivo.
    //POST: Devuelve booleana depende de si pudo leer los archivos o no.
    bool leerArchivos(string nombreArchivoVistas, string nombreArchivoNoVistas, Lista<Peliculas>* pListaVistas, Lista<Peliculas>* pListaNoVistas);
    //PRE: Archivo de lectura y puntero a la lista de peliculas que se va a cargar.
    //POST: Lista cargada.
    void cargarLista(ifstream& archivo, Lista<Peliculas>* pLista);
    //PRE: 3 punteros a lista de peliculas, por cada lista.
    //POST: Lista de Recomendadas cargada.
    void cargarListaRecomendadas(Lista<Peliculas>* pListaVistas, Lista<Peliculas>* pListaNoVistas, Lista<Peliculas>* pListaRecomendadas);
    //PRE: Dos punteros a lista de strings (actores).
    //POST: Devuelve booleana depende de si coinciden en algun actor o no.
    bool coincide_actores(Lista<string>* lista_actores_no_vistas, Lista<string>* lista_actores_vistas);
};

#endif /* archivo_hpp */
