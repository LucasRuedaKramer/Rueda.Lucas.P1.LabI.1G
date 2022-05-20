#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int idServicio;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED

int listarServicios(eServicio servicios[], int tam);

int buscarServicios(eServicio servicios[], int tam, int idServicio, int* pIndex);

int cargarDescripcionServicio(eServicio servicios[], int tam, int idServicio, char desc[]);



