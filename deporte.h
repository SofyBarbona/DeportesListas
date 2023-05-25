#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED

//axiomas
//nombre: sin caracteres especiales
//cantJug: sólo numeros

struct DeporteEst;
typedef struct DeporteEst* Deporte;

//PRE:
//POST:
Deporte crearDeportePP(char nombre[], int cantJug);
//PRE:
//POST:
void mostrarDeporte(Deporte dep);
//PRE:
//POST:
char* getNombre(Deporte dep);

#endif // DEPORTE_H_INCLUDED
