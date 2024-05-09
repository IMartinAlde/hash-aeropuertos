#ifndef DATO_HASH_H
#define DATO_HASH_H

#include "aeropuerto.h"

const int LIBRE = 1; //La posición nunca se ocupó anteriormente;
const int OCUPADO = 2; //La posición se encuentra ocupada;
const int BORRADO = 3; //La posición estuvo ocupada pero el dato anterior se borró.

const int DATO_NO_ENCONTRADO = -1;

const int BASE = 128; //AGREGADO

class DatoHash{
private:
    string codigo_iata;
    Aeropuerto * aeropuerto;
    int estado;

public:
    //CONSTRUCTORES:
    //PRE:
    //POST: Crea una instancia de DatoHash con valores iniciales predeterminados
    DatoHash();

    //PRE: estado debe valer LIBRE, OCUPADO o BORRADO
    //POST: Crea una instancia de DatoHash con los valores pasados por parámetros.
    DatoHash(string codigo_iata, Aeropuerto * aeropuerto, int estado);

    //PRE: -
    //POST: Devuelve el codigo IATA del aeropuerto.
    string obtener_codigo_iata();

    //PRE: -
    //POST: Devuelve un puntero al dato de tipo Aeropuerto.
    Aeropuerto * obtener_aeropuerto();

    //PRE: -
    //POST: Devuelve el estado del DatoHash: LIBRE, OCUPADO o BORRADO
    int obtener_estado();

    //PRE: -
    //POST: Actualiza el valor del codigo iata.
    void modificar_codigo_iata(string codigo_iata);

    //PRE: -
    //POST: Actualiza el valor de aeropuerto.
    void modificar_aeropuerto(Aeropuerto * aeropuerto);

    //PRE: -
    //POST: Actualiza el estado del hash.
    void modificar_estado(int estado);

};

#endif //DATO_HASH_H