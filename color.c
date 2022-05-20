#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"


/** \brief imprime el contenido del array
 *
 * \param colores[] eColor
 * \param tam int
 * \return int
 *
 */
int listarColores(eColor colores[], int tam){

 int todoOk = 0;
    if(colores != NULL && tam > 0 ){

        printf("   *** Listado de Colores ***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", colores[i].idColor, colores[i].nombreColor);

         }
    }
    return todoOk;
}



/** \brief buscar color por Id
 *
 * \param vec[] eColor
 * \param tam int
 * \param id int
 * \param pIndex int*
 * \return int
 *
 */
int buscarColor(eColor vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].idColor == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



