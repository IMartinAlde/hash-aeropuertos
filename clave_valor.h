#ifndef DATO_DICCIONARIO_H
#define DATO_DICCIONARIO_H

#include <string>
#include <iostream>

using namespace std;

class ClaveValor{
private:
    string clave;
    string valor;

public:
    //CONSTRUCTORES:
    //PRE:
    //POST: Crea una instancia de ClaveValor con valores predeterminados.
    ClaveValor();

    //CONSTRUCTORES:
    //PRE: clave y valor deben ser de tipo string no vacíos.
    //POST: Crea una instancia de ClaveValor con valores predeterminados.
    ClaveValor(string clave, string valor);

    //PRE:
    //POST: Obtiene la clave del par clave-valor.
    string obtener_clave();

    //PRE:
    //POST: Obtiene el valor del par clave-valor.
    string obtener_valor();

};

#endif //DATO_DICCIONARIO_H