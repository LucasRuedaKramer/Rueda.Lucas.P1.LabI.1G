#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "Servicios.h"

/** \brief indicar que todas las posiciones del array estan vacias
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}



/** \brief imprime el contenido del array
 *
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param autos[] eAuto
 * \param tamA int
 * \param marcas[] eMarca
 * \param tamM int
 * \param servicios[] eServicio
 * \param tamS int
 * \return int
 *
 */
int listarTrabajos(eTrabajo trabajos[], int tamT,  eAuto autos[], int tamA, eMarca marcas[], int tamM, eServicio servicios[], int tamS)
{
    int todoOk = 0;
    int flag = 1;
    if( trabajos != NULL  && marcas != NULL && autos != NULL && servicios != NULL && tamT > 0 && tamM > 0 && tamA >0 && tamS > 0)
    {
        system("cls");
        printf("       *** Listado de Trabajos ***\n");
        printf("   id         id Auto         id Servicio       fecha\n");
        printf("-----------------------------------------------------------\n");
        for(int i=0; i < tamA; i++)
        {
            if( !trabajos[i].isEmpty)
            {
                mostrarTrabajoFila(trabajos[i], autos, tamA, servicios, tamS, marcas, tamM);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay trabajos en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}



/** \brief buscar una posición libre en la lista de trabajos
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \param pIndex int*
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


/** \brief guarda en la lista existente los valores ingresados como parametro
 *
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param autos[] eAuto
 * \param tamA int
 * \param marcas[] eMarca
 * \param tamM int
 * \param servicios[] eServicio
 * \param tamS int
 * \param pNextId int*
 * \return int
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eMarca marcas[], int tamM, eServicio servicios[], int tamS, int* pNextId)
{
    int todoOk = 0;
    int indice = 0;
    eTrabajo nuevoTrabajo;
    eFecha fecha;
    int idAuto;
    int idServicio;

    if( trabajos != NULL && pNextId != NULL && marcas != NULL && autos != NULL && servicios != NULL && tamT > 0 && tamM > 0 && tamA >0 && tamS > 0)
    {
        system("cls");
        printf("    *** Alta Trabajo ***\n\n");
        buscarLibreTrabajo(trabajos, tamT, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoTrabajo.id = *pNextId;

            listarAutos(autos, tamA, marcas, tamM);
            printf("Ingrese id Auto: ");
            scanf("%d", &idAuto);

            while( !validarAuto(autos, tamA, idAuto))
            {
                printf("Auto invalido. Ingrese id Auto: ");
                scanf("%d", &idAuto);
            }
            nuevoTrabajo.idAuto = idAuto;

            listarServicios(servicios, tamS);
            printf("Ingrese id Servicio: ");
            scanf("%d", &idServicio);

            while( !validarServicio(servicios, tamS, idServicio))
            {
                printf("Servicio invalido. Ingrese id servicio: ");
                scanf("%d", &idServicio);
            }
            nuevoTrabajo.idServicio = idServicio;

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d",
                  &fecha.dia,
                  &fecha.mes,
                  &fecha.anio);

            nuevoTrabajo.fecha = fecha;

            nuevoTrabajo.isEmpty = 0;

            trabajos[indice] = nuevoTrabajo;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}



/** \brief muestra el contenido de un Trabajo del array trabajos
 *
 * \param trabajos eTrabajo
 * \param autos[] eAuto
 * \param tamA int
 * \param servicios[] eServicio
 * \param tamS int
 * \param marcas[] eMarca
 * \param tamM int
 * \return int
 *
 */
int mostrarTrabajoFila(eTrabajo trabajos, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM)
{
    int todoOk = 0;
    char descripcionServicio[20];
    char descripcion[20];

    if(autos != NULL && servicios != NULL && tamA > 0 && tamS > 0)
    {

        cargarDescripcionMarca(marcas, tamM, autos->idMarca, descripcion);
        cargarDescripcionServicio(servicios, tamS, trabajos.idServicio, descripcionServicio);

        printf("   %d  %10s       %10s      %02d/%02d/%d\n",
               trabajos.id,
               descripcionServicio,
               descripcion,
               trabajos.fecha.dia,
               trabajos.fecha.mes,
               trabajos.fecha.anio);


        todoOk = 1;
    }

    return todoOk;
}


