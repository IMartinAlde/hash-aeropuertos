#include "hash_cerrado.h"

HashCerrado::HashCerrado() {
    this->tabla = new DatoHash[TAMANIO_TABLA_C];

    for (int i = 0; i < TAMANIO_TABLA_C; i++){
        this->tabla[i] = DatoHash();
    }
    this->tamanio = TAMANIO_TABLA_C;
}

int HashCerrado::hashing(string codigo_iata) {
    int suma = 0;
    for (char c : codigo_iata ){
        suma += int(c);
    }
    suma *= BASE;
    return suma % this->tamanio;
}


int HashCerrado::encontrar_posicion_disponible(int posicion){
    while (this->tabla[posicion].obtener_estado() == OCUPADO){
        posicion++;
        if (posicion == TAMANIO_TABLA_C){
            posicion = 0;
        }
    }
    return posicion;
}

void HashCerrado::agregar_dato(DatoHash dato) {
    string codigo_iata_dato = dato.obtener_codigo_iata();
    int posicion = hashing(codigo_iata_dato);

    posicion = encontrar_posicion_disponible(posicion);

    this->tabla[posicion] = dato;
}

int HashCerrado::buscar(string codigo_iata_dato){
    int posicion = hashing(codigo_iata_dato);

    bool dato_encontrado = false;

    while ((!dato_encontrado) && (this->tabla[posicion].obtener_estado() != LIBRE)){
        if (this->tabla[posicion].obtener_estado() != BORRADO){
            if (this->tabla[posicion].obtener_codigo_iata() == codigo_iata_dato){
                dato_encontrado = true;
            }
        }
        if (!dato_encontrado){
            posicion++;
            if (posicion == TAMANIO_TABLA_C){
                posicion = 0;
            }
        }
    }
    if (!dato_encontrado){
        posicion = DATO_NO_ENCONTRADO;
    }
    return posicion;
}


void HashCerrado::eliminar_dato(string codigo_iata_dato) {

    int posicion = buscar(codigo_iata_dato);

    if (posicion == DATO_NO_ENCONTRADO) {
        cerr << "El dato no se encuentra en la tabla." << endl;
    } else {
        Aeropuerto * aeropuerto = tabla[posicion].obtener_aeropuerto();
        delete aeropuerto;
        this->tabla[posicion].modificar_codigo_iata("");
        this->tabla[posicion].modificar_aeropuerto(nullptr);
        this->tabla[posicion].modificar_estado(BORRADO);

    }
}

void HashCerrado::mostrar_informacion_aeropuerto(string codigo_iata_dato) {
    int posicion = buscar(codigo_iata_dato);
    this->tabla[posicion].obtener_aeropuerto()->imprimir_informacion();
}

HashCerrado::~HashCerrado(){
    for (int i = 0; i < tamanio; ++i) {
        delete tabla[i].obtener_aeropuerto();
    }
    delete [] tabla;
}