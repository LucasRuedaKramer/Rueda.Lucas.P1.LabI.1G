#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "funciones.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "Servicios.h"
#include "trabajo.h"



#define TAMA 10
#define TAMT 10
#define TAMM 5
#define TAMC 5
#define TAMS 4

int main()
{

    char salir = 'n';
    int proximoId = 1005;
    int proximoIdTrabajo = 20000;
    eAuto autos[TAMA];
    eTrabajo trabajos[TAMT];
    eMarca marcas[TAMM]=
    {
        {1000, "Renault" },
        {1001, "Ford" },
        {1002, "Fiat" },
        {1003, "Chevrolet" },
        {1004, "Peugeot" }
    };
    eColor colores[TAMC]=
    {
        {5000, "Negro" },
        {5001, "Rojo" },
        {5002, "Blanco" },
        {5003, "Verde" },
        {5004, "Azul" }
    };
    eServicio servicios[TAMS]=
    {
        {20000, "Lavado", 450 },
        {20001, "Pulido", 500 },
        {20002, "Encerado", 600},
        {20003, "Completo", 900 }
    };

      inicializarAutos(autos, TAMA);
      inicializarTrabajos(trabajos, TAMT);


    do
    {
        switch(menu())
        {
        case 1:
             if(altaAuto(autos, TAMA, marcas, TAMM, colores, TAMC, &proximoId))
            {
                printf("Auto cargado con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar el auto\n");
            }
            break;
        case 2:
             modificarAuto(autos, TAMA, marcas, TAMM, colores, TAMC);
        break;

        case 3:
             bajaAuto(autos, TAMA, marcas, TAMM);
            break;

        case 4:
               system("cls");
            ordenarAutosMarcaCaja(autos, TAMA);
            listarAutos(autos, TAMA, marcas, TAMM);
        break;

        case 5:
          system("cls");
            listarMarcas(marcas, TAMM);
        break;

        case 6:
            system("cls");
            listarColores(colores, TAMC);
        break;

        case 7:
              system("cls");
            listarServicios(servicios, TAMS);
        break;

        case 8:
            if(altaTrabajo(trabajos, TAMT, autos, TAMA, marcas, TAMM, servicios, TAMS, &proximoIdTrabajo))
            {
                printf("Trabajo cargado con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar el trabajo\n");
            }
            break;

        case 9:
               system("cls");
            listarTrabajos(trabajos, TAMT, autos, TAMA, marcas, TAMM, servicios, TAMS);
        break;

        case 10:
            salir = 's';
        break;
        }
        system("pause");
    }
    while(salir != 's');

    return 0;
}
