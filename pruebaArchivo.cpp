
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "Nodo.h"
#include "Lista.h"
#include "Peliculas.h"

using namespace std;



int main(){



    ifstream archivo;
    archivo.open("prueba.txt", ios::in);

    if (archivo.fail()){
        cout << "El archivo no se abrio" << endl;
    }
    Lista<Pelicula>* pLista;

    string nombrePelicula, nombreDirector, genero, actor;
    int puntaje;
    string mystr;
    Lista<string>* pAux = 0;
    int contador = 0;

    while(!archivo.eof()){
        Lista<string> actores;
        getline(archivo,mystr);

        if (contador == 0){
            nombrePelicula = mystr;
            contador++;
        }

        else if (contador == 1){
            genero = mystr;
            contador ++;
        }

        else if ( contador == 2 ){
            puntaje = stringstream(mystr);
            contador++;
        }

        else if ( contador == 3 ){
            nombreDirector = mystr;
            contador ++;
        }

        else if (contador == 4){
            cout << "nombre actores:" <<endl;
            int marcador = 0;

            for ( unsigned int i = 0; i <= mystr.length(); i++){

                if (mystr[i] == '_'){
                    mystr[i] = ' ';
                }

                else if (mystr[i] == ' ' || (i == mystr.length() && mystr[i] != ' ')){
                    actor = mystr.substr(marcador,i-marcador);
                    marcador = i+1;
                }
                actores.insert(actor);
                pAux = &actores;
            }
        contador++;
        }

        else if (contador == 5){
            Peliculas pelicula(nombrePelicula,generoPelicula,puntajePelicula,directorPelicula);
            pelicula.setActores(pAux);
            (*pLista).insert(pelicula);
            contador = 0;
        }

    }
    archivo.close();

    return 0;
}
