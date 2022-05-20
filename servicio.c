#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"


/** \brief imprimir el contenido del array
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return int
 *
 */
int listarServicios(eServicio servicios[], int tam){

 int todoOk = 0;
    if(servicios != NULL && tam > 0 ){

        printf("   *** Listado de Servicios ***\n");
        printf("  id      descripcion     precio\n");
        printf("------------------------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s        %5.2f\n", servicios[i].idServicio, servicios[i].descripcion, servicios[i].precio);

         }
    }
    return todoOk;
}


/** \brief buscar existente por Id
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param idServicio int
 * \param pIndex int*
 * \return int
 *
 */
int buscarServicios(eServicio servicios[], int tam, int idServicio, int* pIndex)
{
    int todoOk = 0;
    if( servicios != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(servicios[i].idServicio == idServicio)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


/** \brief cargar campo por Id
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param idServicio int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char desc[]){

    int todoOk = 0;
    if(servicios != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( servicios[i].idServicio == idServicio){
                strcpy( desc, servicios[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}






