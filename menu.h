#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "archivo.h"

const int OPCION_HASH_CERRADO = 0;
const int OPCION_HASH_ABIERTO = 1;
const int OPCION_CONSULTA = 1;
const int OPCION_ALTA = 2;
const int OPCION_BAJA = 3;
const int OPCION_SALIR = 4;

using namespace std;

template < typename Tipo >

class Menu{
private:
public:
    //PRE: -
    //POST: Muestra las opciones disponibles del menú principal.
    void mostrar_opciones();

    //PRE: hash y diccionario no deben estar vacíos.
    //POST: Pide el ingreso de la opcion deseada y en función de
    //lo ingresado, añade un aeropuerto, lo borra, muestra su
    //información o termina el programa.
    void menu_principal(Tipo &hash, Diccionario &diccionario);

    //PRE: -
    //POST: Pide al usuario el ingreso de una ciudad y la busca
    //en el diccionario. Si está, devuelve la información guardada
    //en el hash del aeropuerto de la ciudad. Caso contrario muestra
    //un mensaje de que no se encontró la ciudad.
    void consulta(Tipo &hash, Diccionario &diccionario);

    //PRE: -
    //POST: Pide los datos de un aeropuerto. Si la ciudad no se encuentra
    //guardada ni en el hash ni en el diccionario, los guarda en ambos.
    //Caso contrario muestra mensaje de que la ciudad indicada ya fue
    //cargada.
    void alta(Tipo &hash, Diccionario &diccionario);

    //PRE: -
    //POST: Pide al usuario el ingreso de una ciudad y la busca
    //en el diccionario. Si está, elimina los datos del aeropuerto
    //tanto en el hash como en el diccionario. Caso contrario muestra
    //un mensaje de que no se encontró la ciudad.
    void baja(Tipo &hash, Diccionario &diccionario);

    //PRE:-
    //POST: Termina la ejecución del programa.
    void salir();

};


template <typename Tipo>
void Menu<Tipo>::mostrar_opciones(){
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "*                MENU PRINCIPAL               *" << endl;
    cout << "***********************************************" << endl;
    cout << "*  Opción 1: CONSULTA                         *" << endl;
    cout << "*  Opción 2: ALTA                             *" << endl;
    cout << "*  Opción 3: BAJA                             *" << endl;
    cout << "*  Opción 4: SALIR                            *" << endl;
    cout << "***********************************************" << endl;
    cout << "Ingrese una opción: ";
}

template <typename Tipo>
void Menu<Tipo>::menu_principal(Tipo &hash, Diccionario &diccionario) {

    int opcion;
    mostrar_opciones();
    cin >> opcion;

    switch(opcion) {
        case OPCION_CONSULTA:
            consulta(hash, diccionario);
            menu_principal(hash, diccionario);
            break;
        case OPCION_ALTA:
            alta(hash, diccionario);
            menu_principal(hash, diccionario);
            break;
        case OPCION_BAJA:
            baja(hash, diccionario);
            menu_principal(hash, diccionario);
            break;
        case OPCION_SALIR:
            salir();
            break;
        default:
            cout << "La opción ingresada no es válida. Intente nuevamente." << endl;
            menu_principal(hash, diccionario);
    }
}

template <typename Tipo>
void Menu<Tipo>::consulta(Tipo &hash, Diccionario &diccionario){
    string ciudad;
    cout << "Ingrese la ciudad: ";
    cin >> ciudad;

    if (!diccionario.pertenece(ciudad)){
        cout << "La ciudad no se encuentra en la base de datos." << endl;
    } else{
        string codigo_iata = diccionario.obtener_valor(ciudad);
        hash.mostrar_informacion_aeropuerto(codigo_iata);
    }
    cout << endl;
}

template <typename Tipo>
void Menu<Tipo>::alta(Tipo &hash, Diccionario &diccionario){
    string codigo_iata, nombre, ciudad, pais;
    float superficie;
    int terminales, destinos_nacionales, destinos_internacionales;

    cout << "Ingrese la ciudad: ";
    cin >> ciudad;
    if (diccionario.pertenece(ciudad)){
        cout << "La ciudad ya fue ingresada. Intente nuevamente." << endl;
    }else{
        cout << "Ingrese el código IATA: " ;
        cin >> codigo_iata;
        cout << "Ingrese el nombre del aeropuerto: ";
        cin >> nombre;
        cout << "Ingrese el pais: ";
        cin >> pais;
        cout << "Ingrese la superficie (en km²): ";
        cin >> superficie;
        cout << "Ingrese la cantidad de terminales: ";
        cin >> terminales;
        cout << "Ingrese la cantidad de destinos nacionales: ";
        cin >> destinos_nacionales;
        cout << "Ingrese la cantidad de destinos internacionales: ";
        cin >> destinos_internacionales;

        diccionario.agregar(ciudad, codigo_iata);
        Aeropuerto * aeropuerto = new Aeropuerto(codigo_iata, nombre, ciudad, pais, superficie, terminales, destinos_nacionales, destinos_internacionales);
        DatoHash dato = DatoHash(codigo_iata, aeropuerto, OCUPADO);
        hash.agregar_dato(dato);
    }
    cout << endl;
}

template <typename Tipo>
void Menu<Tipo>::baja(Tipo &hash, Diccionario &diccionario){
    string ciudad;
    cout << "Ingrese la ciudad: " << endl;
    cin >> ciudad;

    if (!diccionario.pertenece(ciudad)){
        cout << "La ciudad no se encuentra en la base de datos." << endl;
    } else{
        string codigo_iata = diccionario.obtener_valor(ciudad);
        hash.eliminar_dato(codigo_iata);
        diccionario.eliminar(ciudad);
        cout << "Se eliminó la ciudad " << ciudad << "." << endl;
    }
    cout << endl;
}

template <typename Tipo>
void Menu<Tipo>::salir(){
    cout << "Fin del programa." << endl;
}

#endif //MENU_H