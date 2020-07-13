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
	int borro = 0;
public:
	//Constructor de la clase.
    //POST: Construye la clase con los datos proporcionados.
	Peliculas(string nombre, string genero, int puntaje, string director, Lista<string> *actores);

	Peliculas(){};

	~Peliculas();

	//PRE: objeto creado
	//POST: Incrementa la variable borro
	void incremento_borro();

	//PRE:Objeto creado
	//POST: Decremento la variable borro en 1
	void decremento_borro();

	//PRE: Objeto creado
	//POST: Devuelve el valor de borro
	int borro_valor();

	//PRE:Objeto creado
	//POST: Borro la lista de actores;
	void borro_manual();


    //POST: Devuelve el nombre de la pelicula.
	string get_nombre();

    //POST: Devuelve el genero de la pelicula.
	string get_genero();

    //POST: Devuelve el puntaje de la pelicula.
	int get_puntaje();

    //POST: Devuelve el director de la pelicula.
	string get_director();

	//PRE :
	//POST: Devuelve lista de actores.
	Lista<string>* get_actor();

	//POST: Devuelve los datos de la pelicula.
	void mostrar_pelicula();
};

#endif
