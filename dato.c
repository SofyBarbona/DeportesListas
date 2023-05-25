#include <stdio.h>
#include <stdlib.h>
#include "dato.h"

Dato crearDato(Deporte dep){
    Dato d = malloc(sizeof(struct DatoE));
    d->deporte = dep;

    return d;
}
