#include <allegro.h>
#include "inicia.h"

int main()
{
    inicia_allegro(1024,576);
    inicia_audio(70,70);
    install_mouse();

    BITMAP *buffer = create_bitmap(1024,576);
    BITMAP *menu=load_bitmap("01v1.bmp",NULL);

    BITMAP *inicio=load_bitmap("02inicio.bmp",NULL);
    BITMAP *continuar=load_bitmap("03continuar.bmp",NULL);
    BITMAP *puntajes=load_bitmap("04puntajes.bmp",NULL);
    BITMAP *salir=load_bitmap("salir.bmp",NULL);
    BITMAP *cursor=load_bitmap("cursor.bmp",NULL);


    int salida=0;
    //blit(menu,buffer,0,0,0,0,1024,576);
    while(salida!=1)
    {

        if(mouse_x>779&&mouse_x<967&&mouse_y>93&&mouse_y<137)
        {
            blit(inicio,buffer,0,0,0,0,1024,576);
            //click izquierdo
            if(mouse_b & 1)
             {


             }

        }

        else if(mouse_x>779&&mouse_x<967&&mouse_y>143&&mouse_y<190)
        {
            blit(continuar,buffer,0,0,0,0,1024,576);
        }

        else if(mouse_x>779&&mouse_x<967&&mouse_y>216&&mouse_y<264)
        {
            blit(puntajes,buffer,0,0,0,0,1024,576);
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

        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,52,52);
        blit(buffer,screen,0,0,0,0,1024,576);
    }
    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN();
