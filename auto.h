#include "fecha.h"
#include "marca.h"
#include "color.h"
//#include "comida.h"
#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int idAuto;
    int idMarca;
    int idColor;
    char caja;
    int isEmpty;
} eAuto;

#endif // AUTO_H_INCLUDED

int inicializarAutos(eAuto vec[], int tam);

int buscarLibre(eAuto vec[], int tam, int* pIndex);

int buscarAuto(eAuto vec[], int tam, int idAuto, int* pIndex);

void mostrarAutoFila(eAuto aut, eMarca marcas[], int tam);

int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCol, int* pNextId);

int bajaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMar);

int modificarAuto(eAuto vec[], int tam, eMarca marcas[], int tamMar, eColor colores [], int tamCol);

int listarAutos(eAuto vec[], int tam, eMarca marcas[], int tamMar);

int menuModificarAuto();

int ordenarAutosMarcaCaja(eAuto vec[], int tam);


