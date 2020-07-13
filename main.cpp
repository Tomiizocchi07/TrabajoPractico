#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Peliculas.h"
#include "archivo.h"

const string mensaje = "[-] El archivo de peliculas NO vistas no se pudo abrir correctamente. Por favor verifique que el archivo exista.";

int main()
{

    Lista<Peliculas> lista_vistas;
    Lista<Peliculas> lista_no_vistas;
    Lista<Peliculas> lista_recomendadas;
/*
    Lista<Peliculas> *l_vistas = &lista_vistas;
    Lista<Peliculas> *l_no_vistas = &lista_no_vistas;
    Lista<Peliculas> *l_recomendadas = &lista_recomendadas;
*/
    Archivo archivos;
    if(archivos.leer_archivos("peliculas_vistas.txt", "peliculas_no_vistas.txt", &lista_vistas, &lista_no_vistas))
    {
        archivos.cargar_lista_recomendadas(&lista_vistas,&lista_no_vistas,&lista_recomendadas);
        Menu menu(&lista_vistas,&lista_no_vistas,&lista_recomendadas);
        menu.mostrar_menu();
    }
    else
    {
        cout << mensaje << endl;
    }
    return (0);
}
