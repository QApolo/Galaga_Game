
#include <allegro.h>
#include "inicia.h"
#include "archivos.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>


#define FIL 100
#define COL 100

void pintar_nave(BITMAP *nave,BITMAP *buffer,struct NAVE nav);
void iniciar();
void iniciar2();
void printEnemigo(BITMAP *enemigo, BITMAP *buffer, struct ENEMIGO ene);
void printBala(BITMAP *bala,BITMAP *buffer, struct BALAS bal,int cont);
SAMPLE *seleccionarSonido();
 BITMAP *aparecer(BITMAP *enemigo,int i);

 void pedirDatos();
 void guardarNombre(FILE *pf,char a);

