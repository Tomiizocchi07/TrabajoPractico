#ifndef PELICULAS_H
#define PELICULAS_H

#include <string>
#include "Lista.h"

using namespace std;

class Peliculas{

private:
	string nombre;
	string genero;
	int puntaje;
	string director;
	Lista<string>* actores;
public:
	//Constructor de la clase.
    //POST: Construye la clase con los datos proporcionados.
	Peliculas(string nombre, string genero, int puntaje, string director, Lista<string> *actores);

    //POST: Devuelve el nombre de la pelicula.
	string get_nombre();

    //POST: Devuelve el genero de la pelicula.
	string get_genero();

    //POST: Devuelve el puntaje de la pelicula.
	int get_puntaje();

    //POST: Devuelve el director de la pelicula.
	string get_director();

	//PRE : La posicion pos debe estar entre cero y la cantidad de actores presentes en la pelicula -1.
	//POST: Devuelve el actor de la pelicula que este en la posicion pos de la lista.
	string get_actor(int pos);

	//Destructor de la clase.
    //POST: Destruye la clase, liberando la memoria dinamica utilizada.
	~Peliculas();

	//POST: Devuelve los datos de la pelicula.
	void mostrar_pelicula();
};

#endif
