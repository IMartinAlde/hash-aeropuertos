#include "aeropuerto.h"

Aeropuerto::Aeropuerto(){
    this->codigo_iata = "";
    this->nombre = "";
    this->ciudad = "";
    this->pais = "";
    this->superficie = 0;
    this->cantidad_terminales = 0;
    this->cantidad_destinos_nacionales = 0;
    this->cantidad_destinos_internacionales = 0;
}

Aeropuerto::Aeropuerto(string codigo_iata, string nombre, string ciudad, string pais, float superficie, int cantidad_terminales, int cantidad_destinos_nacionales, int cantidad_destinos_internacionales){
    this->codigo_iata = codigo_iata;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->pais = pais;
    this->superficie = superficie;
    this->cantidad_terminales = cantidad_terminales;
    this->cantidad_destinos_nacionales = cantidad_destinos_nacionales;
    this->cantidad_destinos_internacionales = cantidad_destinos_internacionales;
}

string Aeropuerto::obtener_codigo_iata(){
    return this->codigo_iata;
}

void Aeropuerto::imprimir_informacion() {
    cout << endl;
    cout << "===============================================" << endl;
    cout << "           INFORMACIÓN DEL AEROPUERTO      " << endl;
    cout << "===============================================" << endl;
    cout << "Código IATA:             " << "\t" << this->codigo_iata << endl;
    cout << "Nombre del aeropuerto:   " << "\t" << this->nombre << endl;
    cout << "Ciudad:                  " << "\t" << this->ciudad << endl;
    cout << "País:                    " << "\t" << this->pais << endl;
    cout << "Superficie:              " << "\t" << this->superficie << " km²" << endl;
    cout << "Terminales:              " << "\t" << this->cantidad_terminales << endl;
    cout << "Destinos nacionales:     " << "\t" << this->cantidad_destinos_nacionales << endl;
    cout << "Destinos internacionales:" << "\t" << this->cantidad_destinos_internacionales << endl;
    cout << "===============================================" << endl;
}