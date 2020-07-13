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
    bool existe_archivo(ifstream& archivo);

    //PRE: Recibe un string
    //POST: Devuelve el string sin guion bajo
    string limpiar_string(string mystr);

    //PRE: Dos strings y dos punteros a lista de peliculas, una por cada archivo.
    //POST: Devuelve booleana depende de si pudo leer los archivos o no.
    bool leer_archivos(string nombre_archivo_vistas, string nombre_archivo_no_vistas, Lista<Peliculas>* p_lista_vistas, Lista<Peliculas>* p_lista_no_vistas);
    //PRE: Archivo de lectura y puntero a la lista de peliculas que se va a cargar.
    //POST: Lista cargada.
    void cargar_lista(ifstream& archivo, Lista<Peliculas>* p_lista);
    //PRE: 3 punteros a lista de peliculas, por cada lista.
    //POST: Lista de Recomendadas cargada.
    void cargar_lista_recomendadas(Lista<Peliculas>* p_lista_vistas, Lista<Peliculas>* p_lista_no_vistas, Lista<Peliculas>* p_lista_recomendadas);
    //PRE: Dos punteros a lista de strings (actores).
    //POST: Devuelve booleana depende de si coinciden en algun actor o no.
    bool coincide_actores(Lista<string>* lista_actores_no_vistas, Lista<string>* lista_actores_vistas);
};

#endif /* archivo_hpp */
