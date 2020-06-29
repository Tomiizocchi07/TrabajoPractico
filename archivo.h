#include "archivo.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"

using namespace std;

Archivo::Archivo(string nombreArchivoVistas, string nombreArchivoNoVistas)
{
    ifstream archivoVistas(nombreArchivoVistas);
    ifstream archivoNoVistas(nombreArchivoNoVistas);
}

bool Archivo::existeArchivo(ifstream& archivo)
{
    if (!archivo.fail())
    {
        return true;
    }
    else
        return false;
}

void cargarListaActores(string listaActores[], ifstream& archivo)
{
    string actor;
    int i = 0;
    while (archivo >> actor)
    {
        listaActores[i] = actor;
        i++;
    }
}

void Archivo::cargarLista(ifstream& archivo, Lista<Peliculas>* pLista)
{
    string nombrePelicula;
    string generoPelicula;
    int puntajePelicula;
    string directorPelicula;
    string listaActores[10];
    while(archivo >> nombrePelicula)
    {
        archivo >> generoPelicula;
        archivo >> puntajePelicula;
        archivo >> directorPelicula;
        cargarListaActores(listaActores, archivo);
        //creo objeto Pelicula
        //cargo Lista con pLista
    }
}

void Archivo::leerArchivos()
{
    if (existeArchivo(archivoNoVistas))
    {
        if (existeArchivo(archivoVistas))
        {
            
        }
    }
    else
    {
        cout << "[-] El archivo 'no_vistas.txt' no se pudo abrir correctamente, por favor intente de nuevo." << endl;
    }
}
