#include <stdio.h>
#include <stdlib.h>

int cantidadPuntajes(FILE *pf);
void leerPuntaje(FILE *pf,int *puntaje);
void guardarPuntaje(FILE *pf, int puntaje);

void ordenar_numeros(int *arreglo, int lon);
void ordenarPuntajes(FILE *pf);
int *getPuntajesAltos(FILE *pf);

int *leerPosicionNave(FILE *pf);
void guardarPosiciones(FILE *pf,int x,int y,int dir,int ndisparos);

