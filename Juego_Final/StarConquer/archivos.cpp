#include "archivos.h"

void leerPuntaje(FILE *pf,int *puntaje)
{
    pf=fopen("puntajes.txt","r");
    if(pf==NULL)
        printf("Error al abrir el archivo: \n");
    fscanf(pf,"%d\n",puntaje);
    fclose(pf);
}
int *getPuntajesAltos(FILE *pf)
{
    pf=fopen("scores.txt","r");
    if(pf==NULL)
       printf("error");

        int i=0;

    int *arreglo=(int*)malloc(sizeof(int)*cantidadPuntajes(pf));
    while(!feof(pf))
    {
         fscanf(pf,"%d\n",&arreglo[i++]);
    }
    return arreglo;


}
void guardarPuntaje(FILE *pf, int puntaje)
{
    pf=fopen("puntajes.txt","w");
     if(pf==NULL)
        printf("Error al abrir el archivo: \n");

    fprintf(pf,"%d\n",puntaje);
    fclose(pf);

    pf=fopen("scores.txt","a");
    if(pf==NULL)
        printf("Error al abrir el archivo: \n");

    fprintf(pf,"\n%d",puntaje);
    fclose(pf);

    pf=fopen("letraScore.txt","a");
       if(pf==NULL)
        printf("Error al abrir el archivo: \n");

    fprintf(pf,"%d\n",puntaje);
}

int *leerPosicionNave(FILE *pf)
{
    pf=fopen("coordenadas.txt","r");
    if(pf==NULL)
    {
        printf("Hubo un error al intentar abrir el archivo: ");
    }
    int *arreglo=(int*)malloc(sizeof(int)*4);
    int i=0;
    while(!feof(pf))
    {
        fscanf(pf,"%d\n",&arreglo[i++]);
    }
return arreglo;
}

void guardarPosiciones(FILE *pf, int x,int y,int dir,int ndisparos)
{
    pf=fopen("coordenadas.txt","w");
    if(pf==NULL)
        printf("Error al abrir ell archivo:");

    fprintf(pf,"%d\n%d\n%d\n%d\n",x,y,dir,ndisparos);
}

//funciones de orden

void ordenar_numeros(int *arreglo, int lon)
{
        int Temp;
         for(int i=0;i<lon;i++)
                for(int j=0;j<lon-1;j++)
                    if(arreglo[j]<arreglo[j+1])
                    {// cambia "<" a ">" para cambiar la manera de ordenar
                        Temp=arreglo[j];
                        arreglo[j]=arreglo[j+1];
                        arreglo[j+1]=Temp;
                    }


           int i=0;
           FILE *pf=fopen("scores.txt","w");
           while(i<lon)
           {
               fprintf(pf,"%d\n",arreglo[i++]);

           }
           fclose(pf);
    }


void ordenarPuntajes(FILE *pf)
{
    pf=fopen("scores.txt","r");
    if(pf==NULL)
        printf("Error al abrir el archivo:");

    int *arreglo=(int*)malloc(sizeof(int)*cantidadPuntajes(pf));

    int i=0;
    while(!feof(pf)&&i<cantidadPuntajes(pf))
    {
        fscanf(pf,"%d\n",&arreglo[i++]);
        //printf("%d trabaja\n", i);
    }
    ordenar_numeros(arreglo,cantidadPuntajes(pf));

    fclose(pf);
    }


int cantidadPuntajes(FILE *pf)
{
    int tam=0;
    pf=fopen("scores.txt","r");
    while(!feof(pf))
    {
        if(fgetc(pf)=='\n')
            tam++;

    }

return tam;
}




