#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "clave_valor.h"

const int TAMANIO = 50;
const int CLAVE_NO_ENCONTRADA = -1;
const int DICCIONARIO_VACIO = 0;

class Diccionario{
private:
    ClaveValor * diccionario = nullptr;
    int cantidad;
    int tamanio_diccionario;

    //PRE: 0 <= posicion_1 < this->cantidad, 0 <= posicion_2 < this->cantidad
    //POST: intercambia el par ClaveValor ubicado en posicion_1
    //por el par ClaveValor ubicado en posicion_2
    void swap(int posicion_1, int posicion_2);

    //PRE:
    //POST: busca la clave entre todos los pares ClaveValor del diccionario
    //Si la encuentra devuelve la posicion del par ClaveValor asociado a clave
    //en el diccionario. En caso contrario, devuelve CLAVE_NO_ENCONTRADA
    int buscar_clave(string clave);

public:
    //CONSTRUCTOR:
    //PRE:
    //POST: Crea una instancia de Diccionario con valores iniciales predeterminados.
    Diccionario();

    //DESTRUCTOR:
    //PRE:
    //POST: Se libera la memoria dinámica asociada a la instancia de Diccionario creada.
    ~Diccionario();

    //PRE: clave y valor son de tipo string no vacíos;
    //POST: Agrega al diccionario un par ClaveValor.
    void agregar(string clave, string valor);

    //PRE: clave debe encontrarse en el diccionario.
    //POST: Elimina el par ClaveValor asociado a  clave.
    void eliminar(string clave);


    //PRE: clave debe encontrarse en el diccionario.
    //POST Devuelve el valor asociado a clave
    string obtener_valor(string clave);

    //PRE: -
    //POST: Devuelve true si la clave se encuentra cargada
    //en el diccioario, false en caso contrario.
    bool pertenece(string clave);

    //PRE:-
    //POST: Devuelve true si el diccionario está vacío, false
    //en caso contrario
    bool esta_vacio();

};

#endif //DICCIONARIO_H