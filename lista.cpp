#include "lista.h"

Lista::Lista() {
    primero = nullptr;
    cantidad = 0;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 0; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (pos == 0){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 0) {
        primero = borrar->obtener_siguiente();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }

    delete borrar;
    cantidad--;
}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool Lista::esta_vacia() {
    return (cantidad == 0);
}

int Lista::obtener_cantidad() {
    return cantidad;
}

Lista::~Lista() {
    while (!esta_vacia())
        baja(0);
}