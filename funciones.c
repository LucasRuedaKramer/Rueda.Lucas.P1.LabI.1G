#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "Servicios.h"


/** \brief imprime menu para el usuario
 *
 * \return int opcion
 *
 */
int menu()
{

    int opcion;

    system("cls");
    printf("     * ABM Lavadero *\n\n");
    printf("1. ALTA AUTO\n");
    printf("2. MODIFICAR AUTO\n");
    printf("3. BAJA AUTO\n");
    printf("4. LISTAR AUTOS\n");
    printf("5. LISTAR MARCAS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


/** \brief buscar existente en el array
 *
 * \param autos[] eAuto
 * \param tam int
 * \param idAuto int
 * \return int esValido
 *
 */
int validarAuto(eAuto autos[], int tam, int idAuto)
{
    int esValido = 0;
    int indice;

    if (buscarAuto(autos, tam, idAuto, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}


/** \brief buscar existente en el array
 *
 * \param vec[] eColor
 * \param tam int
 * \param idColor int
 * \return int esValido
 *
 */
int validarColor(eColor vec[], int tam, int idColor){
 int esValido = 0;
 int indice;

 if (buscarColor(vec, tam, idColor, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}


/** \brief buscar existente en el array
 *
 * \param vec[] eMarca
 * \param tam int
 * \param id int
 * \return int esValido
 *
 */
int validarMarca(eMarca vec[], int tam, int id){
 int esValido = 0;
 int indice;

 if (buscarMarca(vec, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}


/** \brief buscar existente en el array
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param idServicio int
 * \return int esValido
 *
 */
int validarServicio(eServicio servicios[], int tam, int idServicio){
 int esValido = 0;
 int indice;

 if (buscarServicios(servicios, tam, idServicio, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}

