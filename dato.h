#ifndef DATO_H_INCLUDED
#define DATO_H_INCLUDED
#include "deporte.h"

//axiomas
//deporte:
struct DatoE{
    Deporte deporte;
};

typedef struct DatoE* Dato;

//PRE:
//POST:
Dato crearDato();

#endif // DATO_H_INCLUDED
