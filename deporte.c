#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deporte.h"

struct DeporteEst{
    char nombre[30];
    int cantJug;
};


Deporte crearDeportePP(char nombre[], int cantJug){
    Deporte dep = malloc(sizeof(struct DeporteEst));

    strcpy(dep->nombre,nombre);
    dep->cantJug = cantJug;

    return dep;
}

void mostrarDeporte(Deporte dep){
    printf("El nombre del deporte es: %s, necesita de %d jugadores \n",dep->nombre, dep->cantJug);
}

char* getNombre(Deporte dep){
    return dep->nombre;
}
