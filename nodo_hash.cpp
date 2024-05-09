#include "nodo_hash.h"

DatoHash::DatoHash() {
    this->codigo_iata = "";
    this->aeropuerto = nullptr;
    this->estado = LIBRE;
}

DatoHash::DatoHash(string codigo_iata, Aeropuerto * aeropuerto, int estado) {
    this->codigo_iata = codigo_iata;
    this->aeropuerto = aeropuerto;
    this->estado = estado;
}


string DatoHash::obtener_codigo_iata() {
    return this->codigo_iata;
}

Aeropuerto * DatoHash::obtener_aeropuerto(){
    return this->aeropuerto;
}

int DatoHash::obtener_estado(){
    return this->estado;
}

void DatoHash::modificar_codigo_iata(string codigo_iata) {
    this->codigo_iata = codigo_iata;
}

void DatoHash::modificar_aeropuerto(Aeropuerto * aeropuerto){
    this->aeropuerto = aeropuerto;
}

void DatoHash::modificar_estado(int estado){
    this->estado = estado;
}