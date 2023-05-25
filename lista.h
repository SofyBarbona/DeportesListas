#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "dato.h"

/// TAREA: Bajo el paradigma de TDA trabajar con una estructura Deporte ( con 2 o 3 atributos a elección), insertar 6 deportes en una lista,
/// ordenar la lista, duplicar la lista, buscar en la lista por algun atributo y obviamente mostrar la lista.

enum estados {PARAMETRO_INVALIDO = -4, INDICE_INVALIDO, ESTRUCTURA_VACIA, ESTRUCTURA_NO_INICIALIZADA, FALSE, TRUE, OK=1};

//Axiomas
//Item
//Prox
//Inicio
//Tam

struct NodoE;
typedef struct NodoE* Nodo;

struct ListaE;
typedef struct ListaE* ListaEnl;

//PRE:
//POST:
ListaEnl crearLista();

//PRE:
//POST:
Nodo crearNodoPP(Dato item, Nodo prox);

//PRE:
//POST:
int destruirLista(ListaEnl lista);

//PRE:
//POST:
int obtenerTamanio(ListaEnl lista, int* tam);

//PRE:
//POST:
int obtenerElemento(ListaEnl lista, Dato* item, int pos);

//PRE:
//POST:
void mostrarLista(ListaEnl lista);

//PRE:
//POST:
int insertar(ListaEnl lista, Dato item, int pos);

//PRE:
//POST:
void ordenarBurbujeo(ListaEnl lista);

//PRE:
//POST:
ListaEnl crearCopiaLista(ListaEnl lista);

//PRE:
//POST:
int buscar(ListaEnl lista, char busco[]);

#endif // LISTA_H_INCLUDED
