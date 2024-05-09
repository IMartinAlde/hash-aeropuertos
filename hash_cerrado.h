#ifndef HASH_CERRADO_H
#define HASH_CERRADO_H

#include "nodo_hash.h"


const int CANTIDAD_AEROPUERTOS = 50;
const int TAMANIO_TABLA_C = 67; //Primer número primo mayor que 50/0,8 = 62,5.

class HashCerrado{
private:
    DatoHash * tabla;
    int tamanio;

    //PRE: 0 <= posicion < tamanio;
    //POST: Encuentra la primera posición con estado LIBRE
    //o BORRADO en la tabla de HashCerrado
    int encontrar_posicion_disponible(int posicion);

public:
    //CONSTRUCTOR:
    //PRE:
    //POST: Crea una instancia de HashCerrado con valores iniciales predeterminados.
    HashCerrado();

    //PRE: codigo_iata debe ser no vacía.
    //POST: devuelve la posición en tabla del DatoHash cuyo codigo_iata
    //es el pasado por parámetro por medio de la función de hashing division.
    int hashing(string codigo_iata);

    //PRE: -
    //POST: Agrega dato en tabla
    void agregar_dato(DatoHash dato);

    //PRE: codigo_iata_dato debe encontrarse en la tabla
    //de HashCerrado
    //POST: Elimina el dato con codigo_iata_dato asociado.
    void eliminar_dato(string codigo_iata_dato);

    //PRE: codigo-iata_dato debe ser no vacío:
    //POST: Busca el DatoHash con codigo_iata_asociado
    //y si lo encuentra devuelve la posición en la tabla
    // de hash. Devuelve -1 en caso contrario.
    int buscar(string codigo_iata_dato);

    //PRE: codigo_iata_dato se encuentra en la tabla de hash
    //POST: busca las posiciones en la tabla y en la lista, y
    //muestra toda la información del aeropuerto guardado en
    //el DatoHash
    void mostrar_informacion_aeropuerto(string codigo_iata_dato);

    //PRE: -
    //POST: Elimina la memoria dinámica utilizada al construir
    //una instancia de HashCerrado.
    ~HashCerrado();

};

#endif //HASH_CERRADO_H