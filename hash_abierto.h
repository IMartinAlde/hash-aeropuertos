#ifndef HASH_ABIERTO_H
#define HASH_ABIERTO_H

#include "lista.h"
#include "nodo_hash.h"

const int TAMANIO_TABLA_A = 10;

class HashAbierto{
private:
    Lista * tabla;
    int tamanio;

public:
    //CONSTRUCTOR:
    //PRE:
    //POST: Crea una instancia de HashAbierto con valores iniciales predeterminados.
    HashAbierto();

    //PRE: codigo_iata debe ser no vacía.
    //POST: devuelve la posición en tabla del DatoHash cuyo codigo_iata
    //es el pasado por parámetro por medio de la función de hashing division
    int hashing(string codigo_iata);

    //PRE: -
    //POST: Agrega dato en tabla
    void agregar_dato(DatoHash dato);

    //PRE: codigo_iata_dato debe encontrarse en la tabla
    //de HashAbierto
    //POST: Elimina el dato con codigo_iata_dato asociado.
    void eliminar_dato(string codigo_iata_dato);

    //PRE: codigo-iata_dato debe ser no vacío:
    //POST: Busca el DatoHash con codigo_iata_asociado
    //y si lo encuentra devuelve la posición en la lista
    //dentro de la tabla de hash. Devuelve -1 en caso contrario.
    int buscar(string codigo_iata_dato);

    //PRE: codigo_iata_dato se encuentra en la tabla de hash
    //POST: busca las posiciones en la tabla y en la lista, y
    //muestra toda la información del aeropuerto guardado en
    //el DatoHash
    void mostrar_informacion_aeropuerto(string codigo_iata_dato);

    //PRE: -
    //POST: Elimina la memoria dinámica utilizada al construir
    //una instancia de HashCerrado.
    ~HashAbierto();

};

#endif //HASH_ABIERTO_H