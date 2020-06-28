#include <iostream>
#include "Lista.h"
using namespace std;

int main()
{
    cout << "Funciona bien la lista ?" <<endl;
    char mychar;
    Lista <char> mylista;
    cout << "El tamaño inicial de la lista es = "<< mylista.get_tam() <<endl;
    while (mychar != 'n'){
        cout << "Digite el caracter que quiera agregar ";
        cin >> mychar;
        cin.ignore();
        mylista.insert(mychar);
        cout << "El nuevo tamaño es = " << mylista.get_tam() <<endl;
    }

    for ( unsigned int i = 1; i <= mylista.get_tam(); i++){
        cout << i << ")" << mylista.get_dato(i) << "." << endl;
    }
    cout<< "Borre la posicion 2"<<endl;
    mylista.del_dato(2);
    for ( unsigned int i = 1; i <= mylista.get_tam(); i++){
        cout << i << ")" << mylista.get_dato(i) << "." << endl;
    }




    return 0;
}
