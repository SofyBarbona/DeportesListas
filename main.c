#include <stdio.h>
#include <stdlib.h>
#include "deporte.h"
#include "lista.h"

/// TAREA: Bajo el paradigma de TDA trabajar con una estructura Deporte ( con 2 o 3 atributos a elección), insertar 6 deportes en una lista,
/// ordenar la lista, duplicar la lista, buscar en la lista por algun atributo y obviamente mostrar la lista.

int main()
{
    Deporte deporteUno = crearDeportePP("Voley",12);
    Deporte deporteDos = crearDeportePP("Beisbol",18);
    Deporte deporteTres = crearDeportePP("Hockey",20);
    Deporte deporteCuatro = crearDeportePP("Futbol",22);
    Deporte deporteCinco = crearDeportePP("Handball",7);
    Deporte deporteSeis = crearDeportePP("Basquet",10);

    ListaEnl listaDeportes = crearLista();

    insertar(listaDeportes,crearDato(deporteUno),0);
    insertar(listaDeportes,crearDato(deporteDos),1);
    insertar(listaDeportes,crearDato(deporteTres),0);
    insertar(listaDeportes,crearDato(deporteCuatro),3);
    insertar(listaDeportes,crearDato(deporteCinco),4);
    insertar(listaDeportes,crearDato(deporteSeis),5);

    printf("\nLista de deportes original \n");
    mostrarLista(listaDeportes);

    printf("\nLista de deportes copiada\n");
    ListaEnl copiaListaDeportes = crearCopiaLista(listaDeportes);
    mostrarLista(copiaListaDeportes);

    printf("\n------Lista Copiada Ordenada Alfabeticamente-------\n");
    ordenarBurbujeo(copiaListaDeportes);
    mostrarLista(copiaListaDeportes);

    printf("\nLista de deportes original\n");
    mostrarLista(listaDeportes);

    printf("\nEl deporte \"Futbol\" esta en la posicion %d de la lista original, sin ordenar\n",buscar(listaDeportes,"Futbol"));
    printf("El deporte \"Futbol\" esta en la posicion %d de la lista copiada y ordenada\n",buscar(copiaListaDeportes,"Futbol"));

    return 0;
}
