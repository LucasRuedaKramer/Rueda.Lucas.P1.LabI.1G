#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "color.h"



/** \brief Indicar que todas las posiciones del array estan vacias
 *  coloca el flag isEmpty en True
 * \param vec[] eAuto
 * \param tam int
 * \return int return todoOk, si hay error nulo
 *
 */
int inicializarAutos(eAuto vec[], int tam)
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


/** \brief Buscar auto por Id
 *
 * \param vec[] eAuto
 * \param tam int
 * \param idAuto int
 * \param pIndex int*
 * \return int return todoOk
 *
 */
int buscarAuto(eAuto vec[], int tam, int idAuto, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].idAuto == idAuto)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



/** \brief Buscar una posición libre en la lista de autos
 *
 * \param vec[] eAuto
 * \param tam int
 * \param pIndex int*
 * \return int todoOk, la primer posición libre
 *
 */
int buscarLibre(eAuto vec[], int tam, int* pIndex)
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



/** \brief mostrar el contenido del array Auto
 *
 * \param aut eAuto
 * \param marcas[] eMarca
 * \param tamMar int
 * \return void
 *
 */
void mostrarAuto(eAuto aut, eMarca marcas[], int tamMar)
{
    char descripcion[20];
    cargarDescripcionMarca(marcas,tamMar, aut.idMarca, descripcion);

    printf("Id: %d\n", aut.idAuto);
    printf("idMarca: %d\n", aut.idMarca);
    printf("idColor: %d\n", aut.idColor);
    printf("Caja: %c\n", aut.caja);
    printf("Modelo: %s\n", descripcion);
}


/** \brief mostrar el contenido de un auto del array auto
 *
 * \param aut eAuto
 * \param marcas[] eMarca
 * \param tam int
 * \return void
 *
 */
void mostrarAutoFila(eAuto aut, eMarca marcas[], int tam)
{

    char descripcion[20];

    cargarDescripcionMarca(marcas, tam, aut.idMarca, descripcion);


    printf("    %4d    %4d      %4d    %c    %10s\n",
           aut.idAuto,
           aut.idMarca,
           aut.idColor,
           aut.caja,
           descripcion
          );
}



/** \brief imprimir el contenido del array
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \return int todoOk
 *
 */
int listarAutos(eAuto vec[], int tam, eMarca marcas[], int tamMar)
{
    int todoOk = 0;
    int flag = 1;

    if( vec != NULL && tam > 0)
    {
        //system("cls");
        printf("       *** Listado de Autos ***\n");
        printf("   idAuto     idMarca     idColor  Caja   Modelo   \n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {

                mostrarAutoFila(vec[i], marcas, tamMar);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay autos en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}



/** \brief ordena los elementos del array por 2 parámetros
 *
 * \param vec[] eAuto
 * \param tam int
 * \return int todoOk
 *
 */
int ordenarAutosMarcaCaja(eAuto vec[], int tam)
{
    int todoOk = 0;
    eAuto auxAuto;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].caja == vec[j].caja && (vec[i].idMarca > vec[j].idMarca) > 0)
                        ||(vec[i].caja != vec[j].caja && (vec[i].caja > vec[j].caja)))
                {
                    auxAuto = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxAuto;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}


/** \brief guarda en la lista existente los valores ingresados como parametro
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \param colores[] eColor
 * \param tamCol int
 * \param pNextId int*
 * \return int todoOk
 *
 */
int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCol, int* pNextId)
{
    int todoOk = 0;
    int indice = 0;
    int idMarca;
    int idColor;
    eAuto nuevoAuto;
    eFecha fecha;

    if( vec != NULL && pNextId != NULL && marcas != NULL && tam > 0 && tamMar > 0 && colores != NULL && tamCol >0)
    {
        system("cls");
        printf("    *** Alta Auto ***\n\n");
        buscarLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoAuto.idAuto = *pNextId;

            printf("Ingrese caja: ");
            fflush(stdin);
            scanf("%c", &nuevoAuto.caja);
            nuevoAuto.caja = tolower(nuevoAuto.caja);

         //   printf("Ingrese fecha ingreso dd/mm/aaaa: ");
           // scanf("%d/%d/%d",
                //  &fecha.dia,
                //  &fecha.mes,
                //  &fecha.anio);

            listarMarcas(marcas, tamMar);

            printf("Ingrese id marca: ");
            scanf("%d", &idMarca);

            // validar si existe ese id marca
            while( !validarMarca(marcas,tamMar, idMarca) )
            {
                printf("Id invalido. Reingrese id marca: ");
                scanf("%d", &idMarca);
            }


            nuevoAuto.idMarca = idMarca;

            listarColores(colores, tamCol);

            printf("Ingrese id color: ");
            scanf("%d", &idColor);

            // validar si existe ese id color
            while( !validarColor(colores,tamCol, idColor) )
            {
                printf("Id invalido. Reingrese id color: ");
                scanf("%d", &idColor);
            }


            nuevoAuto.idColor = idColor;

            nuevoAuto.isEmpty = 0;

            vec[indice] = nuevoAuto;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}




/** \brief permite modificar un auto por id
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \param colores[] eColor
 * \param tamCol int
 * \return int todoOk
 *
 */
int modificarAuto(eAuto vec[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCol)
{
    int todoOk = 0;
    int indice;
    int idAuto;
    char descripcion;
    char auxCad[100];
    int idMarca;
    int idColor;

    if( vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 )
    {
        listarAutos(vec, tam, marcas, tamMar);
        printf("Ingrese id: ");
        scanf("%d", &idAuto);

        if( buscarAuto(vec, tam, idAuto, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un auto con id: %d en el sistema\n", idAuto);
            }
            else
            {

                mostrarAuto(vec[indice], marcas, tamMar);

                switch(menuModificarAuto())
                {

                case 1:
                    listarColores(colores, tamCol);

                    printf("Ingrese id color: ");
                    scanf("%d", &idColor);

                    // validar si existe ese id sector
                    while( !validarColor(colores,tamCol, idColor) )
                    {
                        printf("Id invalido. Reingrese id sector: ");
                        scanf("%d", &idColor);
                    }

                    vec[indice].idColor = idColor;
                    break;

                case 2:
                    listarMarcas(marcas, tamMar);

                    printf("Ingrese id marca: ");
                    scanf("%d", &idMarca);

                    // validar si existe ese id sector
                    while( !validarMarca(marcas,tamMar, idMarca) )
                    {
                        printf("Id invalido. Reingrese id sector: ");
                        scanf("%d", &idMarca);
                    }

                    vec[indice].idMarca = idMarca;
                    break;

                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}



/** \brief imprime menu de opciones para el usuario
 *
 * \return int opcion seleccionada
 *
 */
int menuModificarAuto()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Color\n");
    printf("2. Modelo\n");
    printf("3. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}



/** \brief permite remover un Auto por Id
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \return int todoOk
 *
 */
int bajaAuto(eAuto vec[], int tam, eMarca marcas[], int tamMar)
{
    int todoOk = 0;
    int indice;
    int idAuto;
    char confirma;
    if( vec != NULL && tam > 0 && marcas != NULL && tamMar > 0)
    {
        listarAutos(vec, tam, marcas, tamMar);
        printf("Ingrese id: ");
        scanf("%d", &idAuto);

        if( buscarAuto(vec, tam, idAuto, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un auto con id: %d en el sistema\n", idAuto);
            }
            else
            {

                mostrarAuto(vec[indice], marcas, tamMar);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}



