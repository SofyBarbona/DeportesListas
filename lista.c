#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/// TAREA: Bajo el paradigma de TDA trabajar con una estructura Deporte ( con 2 o 3 atributos a elección), insertar 6 deportes en una lista,
/// ordenar la lista, duplicar la lista, buscar en la lista por algun atributo y obviamente mostrar la lista.

struct NodoE{
    Dato item;
    Nodo prox;
};

struct ListaE{
    Nodo inicio;
    int tam;
};

ListaEnl crearLista(){
    ListaEnl lista = malloc(sizeof(struct ListaE));

    if(lista == NULL)
        return NULL;

    lista->inicio = NULL;
    lista->tam = 0;

    return lista;

}
Nodo crearNodoPP(Dato item, Nodo prox){
    Nodo nodo = malloc(sizeof(struct NodoE));

    if(nodo == NULL)
        return NULL;

    nodo->item = item;
    nodo->prox = prox;

    return nodo;

}

int destruirLista(ListaEnl lista){
    free(lista);
    lista->inicio = NULL;

    return OK;
}

int obtenerTamanio(ListaEnl lista, int* tam){
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    if (tam == NULL)
        return PARAMETRO_INVALIDO;

    *tam = lista->tam;
    return OK;
}
int obtenerElemento(ListaEnl lista, Dato* item, int pos){
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    if (pos < 0 || pos >= lista->tam)
        return INDICE_INVALIDO;

    if (item == NULL)
        return PARAMETRO_INVALIDO;

    Nodo aux;

    aux = lista->inicio;
    for(int i=0;i<pos;i++){
        aux = aux->prox;
    }
    *item = aux->item;

    return OK;
}
void mostrarLista(ListaEnl lista){
    int tam;
    obtenerTamanio(lista, &tam);

    for(int i=0; i<tam;i++){
        Dato el;
        obtenerElemento(lista,&el,i);
        mostrarDeporte(el->deporte);
    }
}

int insertar(ListaEnl lista, Dato item, int pos){
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    if (pos > lista->tam)
        return INDICE_INVALIDO;

    Nodo nuevoNodo;

    Nodo aux;
    aux = lista->inicio;
    if(pos == 0){
        nuevoNodo = crearNodoPP(item,lista->inicio);
        lista->inicio =  nuevoNodo;
    }else{
        for(int i=0;i<pos-1;i++){
            aux = aux->prox;
        }
        nuevoNodo = crearNodoPP(item,aux->prox);

        if (nuevoNodo== NULL)
            return ESTRUCTURA_NO_INICIALIZADA;

        aux->prox = nuevoNodo;
    }

    lista->tam++;

    return OK;
}

void ordenarBurbujeo(ListaEnl lista){
    int tam;
    obtenerTamanio(lista,&tam);

    Dato auxItem;
    Nodo actual;
    for(int i=0;i<tam;i++){
        actual = lista->inicio;
        for(int j=0;j<tam-1;j++){
            if(strcmp(getNombre(actual->item->deporte), getNombre(actual->prox->item->deporte)) == 1){
                auxItem = actual->item;
                actual->item = actual->prox->item;
                actual->prox->item = auxItem;
            }
            actual = actual->prox;
        }
    }
}

ListaEnl crearCopiaLista(ListaEnl lista){
    //No encontré ningun ejemplo de cómo realizar el "duplicado de la lista" por lo que me guié por lo que entendí e imaginé, sepa disculpar.

    ListaEnl copia = crearLista();

    Dato el;
    for(int i=0; i<lista->tam ;i++){
        obtenerElemento(lista,&el,i);
        insertar(copia,el,i);
    }

    return copia;
}

int buscar(ListaEnl lista, char busco[]){
    if (lista == NULL)
        return ESTRUCTURA_NO_INICIALIZADA;

    int encontrado = -1;
    int tam;
    obtenerTamanio(lista, &tam);

    Dato el;
    for(int i=0;i<tam;i++){
        obtenerElemento(lista,&el,i);
        if( strcmp(busco,getNombre(el->deporte)) == 0){
            encontrado = i;
            i=tam;
        }
    }
    return encontrado;
}
