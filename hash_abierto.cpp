#include "hash_abierto.h"

HashAbierto::HashAbierto() {
    this->tabla = new Lista[TAMANIO_TABLA_A];

    for (int i = 0; i < TAMANIO_TABLA_A; i++){
        this->tabla[i] = Lista();
    }
    this->tamanio = TAMANIO_TABLA_A;
}

int HashAbierto::hashing(string codigo_iata) {
    int suma = 0;
    for (char c : codigo_iata ){
        suma += int(c);
    }
    suma *= BASE;
    return suma % this->tamanio;
}

void HashAbierto::agregar_dato(DatoHash dato) {
    string codigo_iata_dato = dato.obtener_codigo_iata();
    int posicion_en_tabla = hashing(codigo_iata_dato);
    int posicion_en_lista = this->tabla[posicion_en_tabla].obtener_cantidad();
    this->tabla[posicion_en_tabla].alta(dato, posicion_en_lista);
}

int HashAbierto::buscar(string codigo_iata_dato){
    int posicion_en_tabla = hashing(codigo_iata_dato);
    int posicion_en_lista = 0;
    bool dato_encontrado = false;


    while ((!dato_encontrado) && (posicion_en_lista < this->tabla[posicion_en_tabla].obtener_cantidad())){
        if (this->tabla[posicion_en_tabla].consulta(posicion_en_lista).obtener_codigo_iata() == codigo_iata_dato){
            dato_encontrado = true;
        }else{
            posicion_en_lista++;
        }
    }
    if (!dato_encontrado){
        posicion_en_lista = -1;
    }

    return posicion_en_lista;
}

void HashAbierto::eliminar_dato(string codigo_iata_dato) {
    int posicion_en_tabla = hashing(codigo_iata_dato);
    int posicion_en_lista = buscar(codigo_iata_dato);

    if (posicion_en_lista == DATO_NO_ENCONTRADO) {
        cerr << "El dato no se encuentra en la tabla." << endl;
    } else {
        Aeropuerto * aeropuerto = tabla[posicion_en_tabla].consulta(posicion_en_lista).obtener_aeropuerto();
        delete aeropuerto;
        this->tabla[posicion_en_tabla].baja(posicion_en_lista);
    }
}

void HashAbierto::mostrar_informacion_aeropuerto(string codigo_iata_dato){
    int posicion_en_tabla = hashing(codigo_iata_dato);
    int posicion_en_lista = buscar(codigo_iata_dato);
    this->tabla[posicion_en_tabla].consulta(posicion_en_lista).obtener_aeropuerto()->imprimir_informacion();
}

HashAbierto::~HashAbierto(){
    for (int i = 0; i < tamanio; ++i) {
        for (int j = 0; j < tabla[i].obtener_cantidad(); j++){
            delete tabla[i].consulta(j).obtener_aeropuerto();
        }
    }
    delete [] tabla;
}