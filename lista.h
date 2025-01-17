#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo.h"

class Lista {
private:
    Nodo* primero;
    int cantidad;

    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo* obtener_nodo(int pos);
public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista();

    // METODOS PUBLICOS
    
    // pre: 0 < pos <= obtener_cantidad() + 1
    // pos: agrega d a la Lista en la posicion pos
    void alta(Dato d, int pos);

    // pre: 0 < pos <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion pos 
    void baja(int pos);

    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool esta_vacia();

    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion pos 
    Dato consulta(int pos);

    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_cantidad();


    // DESTRUCTOR
    // pre: -
    // pos: destruye la Lista y libera toda la memoria utilizada.
    ~Lista();
};


#endif // _LISTA_H_