#include "Menu.h"

Menu::Menu(Lista<Peliculas> *l_vistas, Lista<Peliculas> *l_no_vistas, Lista<Peliculas> *l_recomendadas)
{
    vistas = l_vistas;
    no_vistas = l_no_vistas;
    recomendadas = l_recomendadas;
}

void Menu :: borro_todo(){

    for (unsigned int i = 1; i <= vistas->get_tam(); i++){
        vistas->get_dato(i).borrar_manual();
    }
    for (unsigned int i = 1; i <= no_vistas->get_tam(); i++){
        no_vistas->get_dato(i).borrar_manual();
    }
}

void Menu::mostrar_menu()
{
    int opcion;
    do
    {
    cout << endl << "------------------------------------------------------------" << endl;
    cout<<"1. Mostrar peliculas vistas."<<endl;
    cout<<"2. Mostrar peliculas NO vistas."<<endl;
    cout<<"3. Mostrar peliculas recomendadas."<<endl;
    cout<<"4. Salir."<<endl;
    cout<< "\n\nElija la opcion que desea realizar: ";
    cin >> opcion;
    cout << "------------------------------------------------------------";
    while ((0 >= opcion) || (opcion > 4))
    {
        cout << endl << "La opcion ingresada no es valida, vuelva a ingresar una opcion entre 1 y 4: ";
        cin>>opcion;
    }
        mostrar_lista(opcion);
    }
    while (opcion != 4);
    borro_todo();
}

void Menu::mostrar_lista(int opcion) {
    Lista<Peliculas> *lista_aux;
    switch (opcion) {
        case 1:
            lista_aux = vistas;
            cout << endl << "Lista de Peliculas Vistas" << endl << endl;
            break;
        case 2:
            lista_aux = no_vistas;
            cout << endl << "Lista de Peliculas No Vistas" << endl << endl;
            break;
        case 3:
            lista_aux = recomendadas;
            cout << endl << "Lista de Peliculas Recomendadas" << endl << endl;
            break;
    }
    if(opcion < 4){
        for (unsigned int pos = 1; pos <= lista_aux->get_tam(); pos++)
        lista_aux->get_dato(pos).mostrar_pelicula();
    }
}
