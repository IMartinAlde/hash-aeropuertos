#ifndef _NODO_H_
#define _NODO_H_

#include "nodo_hash.h"
typedef DatoHash Dato;

class Nodo {
private:
    
    // ATRIBUTOS
    Dato dato;
    Nodo* siguiente;

public:
    
    // CONSTRUCTORES

    // pos: construye un Nodo con un dato d y siguiente en nullptr.
    Nodo(Dato d);
    // pos: construye un Nodo con un dato d y siguiente en pn
    Nodo(Dato d, Nodo* pn);

    // METODOS
    //PRE:
    //POST: Devuelve el valor del dato almacenado en el nodo.
    Dato obtener_dato();

    //PRE:
    //POST: Devuelve el nodo siguiente al nodo actual
    Nodo* obtener_siguiente();

    //PRE:-
    //POST: Cambia el dato actual del nodo por el dato d.
    void cambiar_dato(Dato d);

    //PRE: -
    //POST: Cambia el nodo siguiente al nodo actual por pn.
    void cambiar_siguiente(Nodo* pn);
};

#endif // _NODO_H_