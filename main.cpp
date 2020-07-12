#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Peliculas.h"
#include "archivo.h"

int main()
{
    Lista<Peliculas> lista_vistas;
    Lista<Peliculas> lista_no_vistas;
    Lista<Peliculas> lista_recomendadas;
    Lista<Peliculas> *l_vistas = &lista_vistas;
    Lista<Peliculas> *l_no_vistas = &lista_no_vistas;
    Lista<Peliculas> *l_recomendadas = &lista_recomendadas;
    Archivo archivos;
    archivos.leerArchivos("peliculas_vistas.txt", "peliculas_no_vistas.txt", l_vistas, l_no_vistas);
    Menu menu(l_vistas,l_no_vistas,l_recomendadas);
    menu.mostrar_menu();
    return (0);
}