#include "archivo.hpp"
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


void Archivo::cargarLista(ifstream& archivo, Lista<Pelicula>* pLista)
{
    string nombrePelicula, generoPelicula, directorPelicula;
    int puntajePelicula;
    string actorPelicula;
    Lista<string>* pAux = 0;
    while(archivo >> nombrePelicula)
    {
        Lista<string> actores;
        pAux = &actores;
        archivo >> generoPelicula;
        archivo >> puntajePelicula;
        archivo >> directorPelicula;
        while ((archivo >> actorPelicula) && (archivo.get() != '\n'))
        {
            actores.insert(actorPelicula);
        }
        Pelicula pelicula(nombrePelicula,generoPelicula,puntajePelicula,directorPelicula);
        pelicula.setActores(pAux);
        (*pLista).insert(pelicula);
        
    }
    

}

bool Archivo::leerArchivos(string nombreArchivoVistas,string nombreArchivoNoVistas, Lista<Pelicula>* pListaVistas, Lista<Pelicula>* pListaNoVistas)
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

void Archivo::cargarListaRecomendadas(Lista<Pelicula>* pListaVistas, Lista<Pelicula>* pListaNoVistas, Lista<Pelicula>* pListaRecomendadas)
{
    for (int i = 1; i <= (*pListaNoVistas).get_tam(); i++)
    {
        if ((*pListaNoVistas).get_dato(i).getPuntaje() >= 7)
        {
            (*pListaRecomendadas).insert((*pListaNoVistas).get_dato(i));
        }
        else
        {
            for (int j = 1; j <= (*pListaVistas).get_tam(); j++)
            {
                if ((*pListaNoVistas).get_dato(i).getDirector() == (*pListaVistas).get_dato(j).getDirector())
                {
                    (*pListaRecomendadas).insert((*pListaNoVistas).get_dato(i));
                }
            }
        }
    }
}
