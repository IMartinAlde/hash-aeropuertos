#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include <string>
#include <iostream>
#include "diccionario.h"

using namespace std;

class Aeropuerto{
private:
    string codigo_iata, nombre, ciudad, pais;
    float superficie;
    int cantidad_terminales, cantidad_destinos_nacionales, cantidad_destinos_internacionales;

public:
    //CONSTRUCTORES:
    //PRE:
    //POST: Crea una instancia de Aeropuerto con valores iniciales predeterminados
    Aeropuerto();

    //PRE: Los valores pasados por parámetro deben ser no vacíos o no nulos.
    //POST: Crea una instancia de Aeropuerto con los valores pasados por parámetros.
    Aeropuerto(string codigo_iata, string nombre, string ciudad, string pais, float superficie, int cantidad_terminales, int cantidad_vuelos_nacionales, int cantidad_vuelos_internacionales);

    //PRE:
    //POST: Devuelve el código IATA del aeropuerto.
    string obtener_codigo_iata();

    //PRE: -
    //POST: Muestra en pantalla toda la información del aeropuerto.
    void imprimir_informacion();
};

#endif //AEROPUERTO_H