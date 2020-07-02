#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;



int main(){

  ifstream archivo;
  archivo.open("prueba.txt", ios::in);

  if (archivo.fail()){
    cout << "El archivo no se abrio" << endl;
  }

  string nombre;

  string mystr;

  int contador = 0;

  while(!archivo.eof()){
    getline(archivo,mystr);


    if (contador == 0){
      nombre = mystr;
      cout << "Nombre Pelicula= " << nombre << endl;
      contador++;
    }

    else if (contador == 1){
      nombre = mystr;
      cout << "Genero = " << nombre << endl;
      contador ++;
    }

    else if ( contador == 2 ){
      nombre = mystr;
      cout << "Puntaje = " << nombre << endl;
      contador++;
    }

    else if ( contador == 3 ){
      nombre = mystr;
      cout << "Director = " << nombre << endl;
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
          nombre = mystr.substr(marcador,i-marcador);
          marcador = i+1;
          cout << nombre << endl;


        }

      }
      contador++;
    }

    else if (contador == 5){
      cout<<mystr<<endl;
      contador = 0;
    }

  }
  archivo.close();

  return 0;
}
