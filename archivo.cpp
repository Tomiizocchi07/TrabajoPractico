#include "archivo.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Archivo::existe_archivo(ifstream& archivo)
{
    if (!archivo.fail())
    {
        return true;
    }
    else
        return false;
}

string Archivo :: limpiar_string(string mystr){
    for(unsigned int i = 0; i < mystr.length() ; i++){
        if (mystr[i] == '_'){
            mystr[i] = ' ';
        }
    }
    return mystr;
}

void Archivo::cargar_lista(ifstream& archivo, Lista<Peliculas>* p_lista)
{
    string nombre_pelicula, genero_pelicula, director_pelicula;
    int puntaje_pelicula;
    string actor_pelicula;

    string my_str;
    while(archivo >> nombre_pelicula)
    {
        Lista<string> * p_aux;
        p_aux = new Lista<string>;
        archivo >> genero_pelicula;
        archivo >> puntaje_pelicula;
        archivo >> director_pelicula;
        nombre_pelicula = limpiar_string(nombre_pelicula);
        genero_pelicula = limpiar_string(genero_pelicula);
        director_pelicula = limpiar_string(director_pelicula);

        getline(archivo,my_str);
        getline(archivo,my_str);
        int marcador  =  0;
        for ( unsigned int i = 0; i <= my_str.length(); i++){
            if (my_str[i] == '_'){
                my_str[i] = ' ';
            }
            else if (my_str[i] == ' ' || (i == my_str.length() && my_str[i] != ' ')){
                actor_pelicula = my_str.substr(marcador,i-marcador);
                (*p_aux).insert(actor_pelicula);
                marcador = i+1;
            }

        }
        Peliculas pelicula(nombre_pelicula,genero_pelicula,puntaje_pelicula,director_pelicula, p_aux);
        (*p_lista).insert(pelicula);
        p_aux = 0;
        delete p_aux;
    }
}

bool Archivo::leer_archivos(string nombre_archivo_vistas,string nombre_archivo_no_vistas, Lista<Peliculas>* p_lista_vistas, Lista<Peliculas>* p_lista_no_vistas)
{
    ifstream archivo_no_vistas(nombre_archivo_no_vistas);
    ifstream archivo_vistas(nombre_archivo_vistas);

    if (existe_archivo(archivo_no_vistas))
    {
        cargar_lista(archivo_no_vistas, p_lista_no_vistas);
        if (existe_archivo(archivo_vistas))
        {
            cargar_lista(archivo_vistas, p_lista_vistas);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Archivo::coincide_actores(Lista<string>* lista_actores_no_vistas, Lista<string>* lista_actores_vistas)
{
    bool recomendada = false;
    for (unsigned int i = 1; i <= (*lista_actores_no_vistas).get_tam(); i ++)
    {
        for (unsigned int j = 1; j <= (*lista_actores_vistas).get_tam(); j ++)
        {
            if ((*lista_actores_vistas).get_dato(i) == (*lista_actores_no_vistas).get_dato(j))
            {
                recomendada = true;
            }
        }
    }
    return recomendada;
}

void Archivo::cargar_lista_recomendadas(Lista<Peliculas>* p_lista_vistas, Lista<Peliculas>* p_lista_no_vistas, Lista<Peliculas>* p_lista_recomendadas)
{
    for (unsigned int i = 1; i <= (*p_lista_no_vistas).get_tam(); i++)
    {
        if ((*p_lista_no_vistas).get_dato(i).get_puntaje() >= 7)
        {
            (*p_lista_recomendadas).insert((*p_lista_no_vistas).get_dato(i));
            p_lista_no_vistas->get_dato(i).incremento_borro();
        }
        else
        {
            for (unsigned int j = 1; j <= (*p_lista_vistas).get_tam(); j++)
            {
                if ((*p_lista_no_vistas).get_dato(i).get_director() == (*p_lista_vistas).get_dato(j).get_director())
                {
                    (*p_lista_recomendadas).insert((*p_lista_no_vistas).get_dato(i));
                    p_lista_no_vistas->get_dato(i).incremento_borro();
                }
                else
                {
                    if(coincide_actores((*p_lista_no_vistas).get_dato(i).get_actor(), (*p_lista_vistas).get_dato(j).get_actor()))
                    {
                        (*p_lista_recomendadas).insert((*p_lista_no_vistas).get_dato(i));
                        p_lista_no_vistas->get_dato(i).incremento_borro();
                    }
                }
            }
        }
    }
}
