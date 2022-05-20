#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "auto.h"
#include "Servicios.h"
#include "fecha.h"

typedef struct
{
    int id;
    int idAuto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo vec[], int tam);

int buscarLibreAlmuerzo(eTrabajo vec[], int tam, int* pIndex);

int altaTrabajo(eTrabajo trabajo[], int tamT, eAuto autos[], int tamA, eMarca marcas[], int tamM, eServicio servicios[], int tamS, int* pNextId);

int mostrarTrabajoFila(eTrabajo trabajos, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas [], int tamM);

int listarTrabajos(eTrabajo trabajos[], int tamT,  eAuto autos[], int tamA, eMarca marcas[], int tamM, eServicio servicios[], int tamS);
