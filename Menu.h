#ifndef MENU_H
#define MENU_H

#include "Lista.h"
#include "Peliculas.h"

using namespace std;

class Menu
{
private:
    Lista <Peliculas> *vistas;
    Lista <Peliculas> *no_vistas;
    Lista <Peliculas> *recomendadas;
public:
    //Constructor con parametros.
    //PRE: Se le deben proporcionar listas creadas.
    //POST: Construye el menu con la lista de datos a mostrar.
    Menu (Lista<Peliculas>* l_vistas, Lista<Peliculas>* l_no_vistas, Lista<Peliculas>* l_recomendadas);
    //Accede a la tarea a realizar
    //PRE: Debe proporcionarsele la opcion elegida.
    //POST: Realiza la accion que se corresponde a la opcion elegida.
    void mostrar_menu();
    //Muestra la lista
    //PRE: -
    //POST: Muestra por pantalla el contenido de la lista elegida
    void mostrar_lista(int opcion);
};

#endif