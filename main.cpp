#include "diccionario.h"
#include "hash_cerrado.h"
#include "hash_abierto.h"
#include "archivo.h"
#include "menu.h"

//PRE:
//POST: Consulta sobre el tipo de hash a utilizar.
int consultar_tipo_hash();

int main() {
    Diccionario diccionario;

    int opcion_hash = consultar_tipo_hash();

    if (opcion_hash == OPCION_HASH_CERRADO) {
        HashCerrado hash = HashCerrado();

        Archivo<HashCerrado> archivo;
        archivo.cargar_datos(hash, diccionario);

        Menu<HashCerrado> menu;
        menu.menu_principal(hash, diccionario);

    } else if (opcion_hash == OPCION_HASH_ABIERTO) {
        HashAbierto hash = HashAbierto();

        Archivo<HashAbierto> archivo;
        archivo.cargar_datos(hash, diccionario);

        Menu<HashAbierto> menu;
        menu.menu_principal(hash, diccionario);
    }

    return 0;
}


int consultar_tipo_hash(){
    int opcion_hash;
    cout << "Ingrese 0 para usar hash cerrado o 1 para usar hash abierto: " ;
    cin >> opcion_hash;

    while ((opcion_hash != OPCION_HASH_ABIERTO) && (opcion_hash != OPCION_HASH_CERRADO)){
        cout << "Opción no válida." << endl;
        cout << "Ingrese 0 para usar hash cerrado o 1 para usar hash abierto: " ;
        cin >> opcion_hash;
    }
    return opcion_hash;
}