#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

 int idColor;
 char nombreColor[20];

}eColor;


#endif // COLOR_H_INCLUDED

int listarColores(eColor colores[], int tam);
int buscarColor(eColor vec[], int tam, int idColor, int* pIndex);
