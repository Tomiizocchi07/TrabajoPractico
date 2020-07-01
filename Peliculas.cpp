#include "Peliculas.h"


Peliculas :: Peliculas(string nombre, string genero, int puntaje, string director, Lista<string> actores){
	this->nombre = nombre;
	this->genero = genero;
	this-> puntaje = puntaje;
	this->director = director;
	this->actores = new actores;
}


string Peliculas :: get_nombre(){
	return this->nombre;
}


string Peliculas :: get_genero(){
	return this->genero;
}


int Peliculas :: get_puntaje(){
	return this->puntaje;
}


string Peliculas :: get_director(){
	return this->director;
}


string Peliculas :: get_actor(int pos){
	return this->actores->get_dato(pos);
}


Peliculas :: ~Peliculas();