#ifndef LISTA_H
#define LISTA_H

# include <iostream>
# include "nodo.h"

template < typename Dato >
class Lista
{
    private:
        // Primer elemento de la lista
        Nodo<Dato>* primero;
        // Tamaño de la lista
        unsigned tam;
    public:
        // Constructor
        // PRE: Ninguna
        // POST: construye una lista vacía
        // - primero apunta a nulo
        // - tam = 0
        Lista();
        // Destructor
        // PRE: Lista creada
        // POST: Libera todos los recursos de la lista
        ~Lista();
        // Agregar un elemento a la lista
        // PRE: lista creada y d válido
        // POST: agrega un dato dentro de un nodo al principio
        // - modifica el primero
        // - tam se incrementa en 1
        void insert(Dato d);
        // Obtener el tamaño de la lista
        // PRE: Lista creada
        // POST: devuelve el tamaño de la lista (cantidad de nodos)
        unsigned get_tam();
        // Obtener el dato que está en la posición pos
        // PRE: - lista creada y no vacía
        // - 0 < pos <= tam
        // POST: devuelve el dato que está en la posición pos
        // se toma 1 como el primero
        Dato get_dato(unsigned pos);
        // ¿Lista vacia?
        // PRE: Lista creada
        // POST: T si es vacia, F sino
        bool lista_vacia();
};

template < typename Dato >
Lista<Dato>::Lista()
{
    primero = 0;
    tam = 0;
}

template < typename Dato >
Lista<Dato>::~Lista()
{
    while (!this->lista_vacia())
    {
        this->del_dato(1);
    }
}

template < typename Dato >
bool Lista<Dato>::lista_vacia()
{
    return (tam == 0);
}

template < typename Dato >
void Lista<Dato>::insert(Dato d)
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (!(this->lista_vacia()))
    {
        nuevo->set_sig(primero);
    }
    primero = nuevo;
    tam++;
}

template < typename Dato >
Dato Lista<Dato>::get_dato(unsigned pos)
{
    Nodo<Dato> *paux = primero;
    unsigned i = 1;
    while (i < pos && paux->get_siguiente())
    {
        paux = paux->get_siguiente();
        i++;
    }
    return paux->get_dato();
}

template < typename Dato >
unsigned Lista<Dato>::get_tam()
{
    return tam;
}
#endif
