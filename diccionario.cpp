#include "diccionario.h"
#include "clave_valor.h"

Diccionario::Diccionario(){
    this->diccionario = new ClaveValor[TAMANIO];
    this->cantidad = 0;
    this->tamanio_diccionario = TAMANIO;
}

void Diccionario::agregar(string clave, string valor){
    if ((buscar_clave(clave) == CLAVE_NO_ENCONTRADA) || (esta_vacio())){
        ClaveValor par = ClaveValor(clave, valor);
        diccionario[cantidad] = par;
        cantidad++;
    }else{
        cerr << "La clave "<< clave << " ya se encuentra en el diccionario." << endl;
    }
}

void Diccionario::swap(int posicion_1, int posicion_2){
    ClaveValor auxiliar = this->diccionario[posicion_1];
    this->diccionario[posicion_1] = this->diccionario[posicion_2];
    this->diccionario[posicion_2] = auxiliar;

}

int Diccionario::buscar_clave(string clave) {
    int posicion = CLAVE_NO_ENCONTRADA;
    bool clave_en_diccionario = false;

    if (!esta_vacio()){
        while ((!clave_en_diccionario) && (posicion < this->cantidad - 1)){
            posicion++;
            if (this->diccionario[posicion].obtener_clave() == clave){
                clave_en_diccionario = true;
            }
        }
    }

    if (!clave_en_diccionario) posicion = CLAVE_NO_ENCONTRADA;

    return posicion;
}

void Diccionario::eliminar(string clave){
    int posicion_clave = buscar_clave(clave);
    if ((posicion_clave == CLAVE_NO_ENCONTRADA) || (posicion_clave >= this->cantidad)){
        cerr << "La clave no se encuentra en el diccionario." << endl;
    }else{
        swap(posicion_clave, this->cantidad - 1);
        this->cantidad--;
    }
}

string Diccionario::obtener_valor(string clave){
    int posicion_clave = buscar_clave(clave);
    string valor_asociado = "";
    if (posicion_clave == CLAVE_NO_ENCONTRADA){
        cerr << "La clave no se encuentra en el diccionario." << endl;
    }else{
        valor_asociado = this->diccionario[posicion_clave].obtener_valor();
    }
    return valor_asociado;
}

bool Diccionario::pertenece(string clave){
    return (buscar_clave(clave) != CLAVE_NO_ENCONTRADA);
}

bool Diccionario::esta_vacio() {
    return (this->cantidad == DICCIONARIO_VACIO);
}

Diccionario::~Diccionario(){
    delete [] this->diccionario;
}
