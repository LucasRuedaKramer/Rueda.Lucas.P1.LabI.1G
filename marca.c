#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

/** \brief cargar campo por Id
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \param desc[] char
 * \return int todoOk
 *
 */
int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char desc[]){

    int todoOk = 0;
    if(marcas != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( marcas[i].idMarca == id){
                strcpy( desc, marcas[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}



/** \brief imprimir el contenido del array
 *
 * \param marcas[] eMarca
 * \param tam int
 * \return int
 *
 */
int listarMarcas(eMarca marcas[], int tam){

 int todoOk = 0;
    if(marcas != NULL && tam > 0 ){

        printf("   *** Listado de Marcas ***\n");
        printf("  id      descripcion\n");
        printf("-----------------------\n");

         for(int i= 0; i < tam; i++){

           printf("    %4d      %10s\n", marcas[i].idMarca, marcas[i].descripcion);

         }
    }
    return todoOk;
}



/** \brief buscar existente por Id
 *
 * \param vec[] eMarca
 * \param tam int
 * \param id int
 * \param pIndex int*
 * \return int
 *
 */
int buscarMarca(eMarca vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].idMarca == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


