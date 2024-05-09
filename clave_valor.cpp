#include "clave_valor.h"

ClaveValor::ClaveValor() {
    this->clave = "";
    this->valor = "";
}

ClaveValor::ClaveValor(string clave, string valor) {
    this->clave = clave;
    this->valor = valor;
}

string ClaveValor::obtener_clave() {
    return this->clave;
}

string ClaveValor::obtener_valor() {
    return this->valor;
}