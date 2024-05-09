#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "hash_abierto.h"
#include "hash_cerrado.h"
#include "diccionario.h"

#include <iostream>
#include <fstream>

const string RUTA_AEROPUERTOS = "aeropuertos.txt";

template <typename Tipo>

class Archivo{
public:
    //PRE: hash y diccionario deben estar vacíos
    //POST: Lee el archivo  aeropuertos.txt y carga
    //todos los datos en el hash seleccionado y los
    //parec ciudad-codigo_iata en el diccinario.
    void cargar_datos(Tipo &hash, Diccionario &diccionario);

};

template <typename Tipo>
void Archivo<Tipo>::cargar_datos(Tipo &hash, Diccionario &diccionario){
    ifstream archivo;
    archivo.open(RUTA_AEROPUERTOS);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string codigo_iata, nombre, ciudad, pais;
    float superficie;
    int terminales, destinos_nacionales, destinos_internacionales;

    while(archivo >> codigo_iata >> nombre >> ciudad >> pais >> superficie >> terminales >> destinos_nacionales >> destinos_internacionales) {
        diccionario.agregar(ciudad, codigo_iata);
        Aeropuerto * aeropuerto = new Aeropuerto(codigo_iata, nombre, ciudad, pais, superficie, terminales, destinos_nacionales, destinos_internacionales);
        DatoHash dato = DatoHash(codigo_iata, aeropuerto, OCUPADO);
        hash.agregar_dato(dato);
    }
    archivo.close();
}


#endif //ARCHIVO_H