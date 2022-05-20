#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

 int idMarca;
 char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED

int cargarDescripcionMarca(eMarca marcas[], int tam, int id, char desc[]);
int listarMarcas(eMarca marcas[], int tam);
int buscarMarca(eMarca vec[], int tam, int id, int* pIndex);




