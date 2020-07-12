#include "archivo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Archivo::existeArchivo(ifstream& archivo)
{
    if (!archivo.fail())
    {
        return true;
    }
    else
        return false;
}

void Archivo::cargarLista(ifstream& archivo, Lista<Peliculas>* pLista)
{
    string nombrePelicula, generoPelicula, directorPelicula;
    int puntajePelicula;
    string actorPelicula;
    Lista<string>* pAux;
    while(archivo >> nombrePelicula)
    {
        pAux = new Lista<string>;
        archivo >> generoPelicula;
        archivo >> puntajePelicula;
        archivo >> directorPelicula;
        while ((archivo >> actorPelicula) && (archivo.get() != '\n'))
        {
            (*pAux).insert(actorPelicula);
        }
        //Peliculas pelicula(nombrePelicula,generoPelicula,puntajePelicula,directorPelicula, pAux);
        //(*pLista).insert(pelicula);
    }
}

bool Archivo::leerArchivos(string nombreArchivoVistas,string nombreArchivoNoVistas, Lista<Peliculas>* pListaVistas, Lista<Peliculas>* pListaNoVistas)
{
    ifstream archivoNoVistas(nombreArchivoNoVistas);
    ifstream archivoVistas(nombreArchivoVistas);
    
    if (existeArchivo(archivoNoVistas))
    {
        cargarLista(archivoNoVistas, pListaNoVistas);
        if (existeArchivo(archivoVistas))
        {
            cargarLista(archivoVistas, pListaVistas);
        }
        return true;
    }
    else
    {
        cout << "[-] El archivo de peliculas NO vistas no se pudo abrir correctamente. Por favor verifique que el archivo exista." << endl;
        return false;
    }
}

void Archivo::cargarListaRecomendadas(Lista<Peliculas>* pListaVistas, Lista<Peliculas>* pListaNoVistas, Lista<Peliculas>* pListaRecomendadas)
{
    for (unsigned int i = 1; i <= (*pListaNoVistas).get_tam(); i++)
    {
        if ((*pListaNoVistas).get_dato(i).get_puntaje() >= 7)
        {
            (*pListaRecomendadas).insert((*pListaNoVistas).get_dato(i));
        }
        else
        {
            for (unsigned int j = 1; j <= (*pListaVistas).get_tam(); j++)
            {
                if ((*pListaNoVistas).get_dato(i).get_director() == (*pListaVistas).get_dato(j).get_director())
                {
                    (*pListaRecomendadas).insert((*pListaNoVistas).get_dato(i));
                }
            }
        }
    }
}
