#include "Peliculas.h"

Peliculas :: Peliculas(string nombre, string genero, int puntaje, string director, Lista<string> *actores){
	this -> nombre = nombre;
	this -> genero = genero;
	this -> puntaje = puntaje;
	this -> director = director;
	this -> actores = actores;
}

string Peliculas :: get_nombre(){
	return this -> nombre;
}

string Peliculas :: get_genero(){
	return this -> genero;
}

int Peliculas :: get_puntaje(){
	return this -> puntaje;
}

string Peliculas :: get_director(){
	return this -> director;
}

Lista<string>* Peliculas :: get_actor(){
	return this -> actores;
}

void Peliculas::mostrar_pelicula() {
    cout<< "Pelicula: " << nombre << " - Genero:  " << genero << " - Puntaje: " << puntaje << " - Director: " << director << " - Actores: ";
    for (unsigned int i = 1; i <= (* actores).get_tam(); i++)
    {
        if (i == (*actores).get_tam())
        {
            cout << actores -> get_dato(i) << endl << endl;
        }
        else
        {
        cout << actores -> get_dato(i) << ", ";
        }
        
    }
}
