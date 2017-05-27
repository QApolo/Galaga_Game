#include <allegro.h>
#include "funciones.h"
#include "inicia.h"


void menuInicio()
{
    inicia_allegro(1024,576);//inicia Allegro, su configuraciòn
    inicia_audio(70,70);//inicia audio
    install_mouse();//inicializaciòn del mouse

    BITMAP *buffer = create_bitmap(1024,576);//crear puntero bitmap para el buffer
    BITMAP *menu=load_bitmap("01v1.bmp",NULL);//cargar imagen del menù

    BITMAP *inicio=load_bitmap("02inicio.bmp",NULL);//inicio
    BITMAP *continuar=load_bitmap("03continuar.bmp",NULL);//continuar
    BITMAP *puntajes=load_bitmap("04puntajes.bmp",NULL);//puntajes
    BITMAP *salir=load_bitmap("salir.bmp",NULL);//salir
    BITMAP *cursor=load_bitmap("cursor.bmp",NULL);//cursor


    int salida=0;
    //blit(menu,buffer,0,0,0,0,1024,576);
    while(salida!=1)//repetir la carga de imagenes
    {//pocisiones de las opciones del menù

        if(mouse_x>779&&mouse_x<967&&mouse_y>93&&mouse_y<137)
        {
            blit(inicio,buffer,0,0,0,0,1024,576);
            //click izquierdo
            if(mouse_b & 1)
             {

//tamalo de ventana
                FILE *pf;
                pedirDatos();


                set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 450, 0, 0);
                    iniciar();
                    exit(-1);
             }

        }

        else if(mouse_x>779&&mouse_x<967&&mouse_y>143&&mouse_y<190)
        {
            blit(continuar,buffer,0,0,0,0,1024,576);
            if(mouse_b & 1)
             {

                set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 450, 0, 0);
                    iniciar2();
                    exit(-1);
             }

        }

        else if(mouse_x>779&&mouse_x<967&&mouse_y>216&&mouse_y<264)
        {

             blit(puntajes,buffer,0,0,0,0,1024,576);
            if(mouse_b & 1)
             {
                 FILE *pf;

            int puntaje;
            int i=0;
            int *puntajes=getPuntajesAltos(pf);
             pf=fopen("scores.txt","r");

                 while(!feof(pf)&&i<5)
                 {

                textprintf_centre_ex(buffer, font, 200, i*30,makecol(0, 80, 243), NULL,
                           "PUNTAJE: %d",
                           puntajes[i++]);
                 }

             }



        }
        else if(mouse_x>779&&mouse_x<967&&mouse_y>294&&mouse_y<340)
        {
            blit(salir,buffer,0,0,0,0,1024,576);
             if(mouse_b & 1)
             {
                //accion a realizar
                salida=1;
             }

        }

        else blit(menu,buffer,0,0,0,0,1024,576);

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,52,52);//carga imagen, pero quita el fondo de la imagen de interès guardada
        blit(buffer,screen,0,0,0,0,1024,576);
    }
    destroy_bitmap(buffer);


}
END_OF_FUNCTION();
//END_OF_MAIN();
