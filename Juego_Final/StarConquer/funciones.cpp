#include "funciones.h"
#include "Menu.h"
const int maxdisp=20, ANCHO=500, ALTO=450;


typedef struct
{
    SAMPLE *volando=load_sample("./Sound/moving.wav");
    SAMPLE *explosion=load_sample("./Sound/rocketDamage.wav");

}Sonidos;
struct NAVE
{
    int x,y;
    int dir;
    int ndisparos;
}nav = {250,300,1,0};

 struct ENEMIGO
{
    int x,y;
    int ndisparos;

}ene={250,100,0},ene2{300,100,0},ene3{150,120,0},ene4{380,120,0},ene5{100,184,0};

struct BALAS
{
    int x,y;
    int dx,dy;
}disparos[maxdisp],disparosEne[maxdisp];

void printBala(BITMAP *bala,BITMAP *buffer, struct BALAS bal,int cont)
{
     masked_blit(bala,buffer,0,0,disparos[cont].x, disparos[cont].y,4,7);
}

void printBalaEnemigo(BITMAP *bala,BITMAP *buffer, struct BALAS bal, int cont)
{
    masked_blit(bala,buffer,0,0,disparosEne[cont].x,disparosEne[cont].y++,4,7);
}

void pintar_nave(BITMAP *nave,BITMAP *buffer,struct NAVE nav)
{
     masked_blit( nave, buffer, 40*nav.dir, 0, nav.x, nav.y, 40, 47);
}

void printEnemigo(BITMAP *enemigo, BITMAP *buffer, struct ENEMIGO ene)
{
    masked_blit(enemigo,buffer,40*nav.dir,0,ene.x,ene.y,40,47);
}
void pausar(int *pausa)
{
    if(*pausa==0)
        *pausa=1;
    else
        *pausa=0;
}

SAMPLE *seleccionarSonido()
{
    SAMPLE *sonido;
    srand (time(NULL));
    int i=rand()%4+1;


    switch(i)
    {
    case 1:
        sonido=load_wav("./Sound/EMP.wav");
        break;
    case 2:
        sonido=load_wav("./Sound/x1sound.wav");
        break;
    case 3:
        sonido=load_wav("./Sound/x1sound_b.wav");
        break;
     case 4:

        sonido=load_wav("./Sound/x3sound.wav");
        break;
     default:
        sonido=load_wav("./Sound/x4sound.wav");

    }
    return sonido;
}

//inicia una nueva partida
void iniciar()
{
     //variables para acelerar juego

    int cuenta=2,velocidad=5;

    BITMAP *nave = load_bitmap("nave.bmp",NULL);
    BITMAP *nube = load_bitmap("nube.bmp",NULL);
    BITMAP *bala = load_bitmap("Bala_amarilla.bmp", NULL);  // otra cosa
    BITMAP *buffer = create_bitmap(500,450);
    FONT *fuente=load_font("font.pcx", NULL, NULL);

    BITMAP *enemigo=load_bitmap("enemigo.bmp",NULL);
    BITMAP *enemigo2=load_bitmap("enemigo.bmp",NULL);
    BITMAP *enemigo3=load_bitmap("enemigo.bmp",NULL);
    BITMAP *enemigo4=load_bitmap("enemigo.bmp",NULL);
    //BITMAP *enemigo5=load_bitmap("enemigo.bmp",NULL);


    int i = 450 , dsw = 0 , contt = 0;
    int pausa=0,modu=3;

    int puntaje=0;
    Sonidos son;
    int j=2;

    FILE *pf;
   // leerPuntaje(pf,&puntaje);

    ordenarPuntajes(pf);

    int derrotado=0;
    while(!key[KEY_ESC]){
        //leemos puntaje:

    /*textprintf_centre_ex(screen, fuente, 0, 0,makecol(0, 100, 243), NULL,
                           "PUNTAJE: %d!",
                           puntaje);*/

    if(key[KEY_P])
        pausar(&pausa);


    if(pausa==0)
    {

        blit(nube,buffer,0,--i,0,0,500,450);  if(i == 0) i=450;
        pintar_nave(nave,buffer,nav);
        printEnemigo(enemigo,buffer,ene);
        printEnemigo(enemigo2,buffer,ene2);
        printEnemigo(enemigo3,buffer,ene3);
        //printEnemigo(enemigo4,buffer,ene4);
//        printEnemigo(enemmigo5,buffer,ene5);



       if(key[KEY_UP])
        {
             nav.dir = 1; nav.y -= 1;
       }
       else if(key[KEY_DOWN])
            {
                 nav.dir = 1; nav.y += 2;
       }
       if(key[KEY_RIGHT])
        {
             nav.dir = 2; nav.x += 1;
       }
       else if(key[KEY_LEFT])
            {
                 nav.dir = 0; nav.x -= 1;
       }
       else nav.dir = 1;

       if(ene.x-30>=nav.x&&ene.y+30<=nav.y)
        enemigo=load_bitmap("derrotado.bmp",NULL);


       //parte disparos
       if(key[KEY_SPACE])
       {

           if(nav.ndisparos<maxdisp)
           {

                nav.ndisparos++;
           disparos[nav.ndisparos].x=nav.x+20;
           disparos[nav.ndisparos].y=nav.y;

           disparos[nav.ndisparos].dx=0;
           disparos[nav.ndisparos].dy=-3;
           dsw=1;
           }

           if(contt++>4)
           {
               dsw=0;
               contt=0;
               // play_sample(seleccionarSonido(), 200, 200, 100000, 0);
                 play_sample(seleccionarSonido(), 255, 127, 1000, 0);
           }
       }
          if(nav.ndisparos>0)
    {
        for(int cont=1;cont<=nav.ndisparos;cont++)
        {
            disparos[cont].x+=disparos[cont].dx;
            disparos[cont].y+=disparos[cont].dy;
            //pintar bala
           printBala(bala,buffer,disparos[cont],cont);

            if(disparos[cont].y==ene.y&&(ene.x<=disparos[cont].x-30||ene.x>=disparos[cont].x+30))
            {
                enemigo=load_bitmap("derrotado.bmp",NULL);
                 printEnemigo(enemigo,buffer,ene);
                 derrotado=1;
                 puntaje+=100;
                 //play_sample(Sonidos.explosion, 255, 127, 1000, 0);
            }
            else if(disparos[cont].y==ene2.y&&(ene2.x<=disparos[cont].x||ene2.x>=disparos[cont].x))
            {
                enemigo2=load_bitmap("derrotado.bmp",NULL);
                printEnemigo(enemigo2,buffer,ene2);
            }
            else if(disparos[cont].y==ene3.y&&(ene3.x<=disparos[cont].x||ene3.x>=disparos[cont].x))
            {
                enemigo3=load_bitmap("derrotado.bmp",NULL);
                printEnemigo(enemigo3,buffer,ene3);
            }

            if(disparos[cont].y>ALTO||disparos[cont].y<0||disparos[cont].x>ANCHO||disparos[cont].x<0)
            {
                disparos[cont]=disparos[nav.ndisparos];
                nav.ndisparos--;
                if(nav.ndisparos<0) nav.ndisparos=0;
            }
        }

    }

    if(derrotado==0)
    {
        if(ene.ndisparos<maxdisp)
           {
           ene.ndisparos++;
           disparosEne[ene.ndisparos].x=ene.x+20;
           disparosEne[ene.ndisparos].y=ene.y;

           disparos[ene.ndisparos].dx=0;
           disparos[ene.ndisparos].dy=3;
           //dsw=1;
           }

           /*if(contt++>4)
           {
               dsw=0;
               contt=0;
           }*/

          for(int cont=1;cont<=ene.ndisparos;cont++)
           {
            disparosEne[cont].x+=disparosEne[cont].dx;
            disparosEne[cont].y+=disparosEne[cont].dy;

            //pintar bala
           printBalaEnemigo(bala,buffer,disparosEne[cont],cont);

            if(disparosEne[cont].y==nav.y&&disparosEne[cont].x==nav.x)
                nave=load_bitmap("derrotado.bmp",NULL);
            //printEnemigo(enemigo,buffer,nav);

            if(disparos[cont].y>ALTO||disparos[cont].y<0||disparos[cont].x>ANCHO||disparos[cont].x<0)
            {
                disparos[cont]=disparos[nav.ndisparos];
                nav.ndisparos--;
                if(nav.ndisparos<0) nav.ndisparos=0;
            }
          }

    }

    ene.ndisparos=1;

    if(ene.y>10)
        ene.y--;

       blit(buffer,screen,0,0,0,0,500,450);
       if(cuenta++%5000==0&&velocidad>0)
       {
           velocidad--;
       }
       textprintf_centre_ex(screen, fuente, 400, 0,makecol(0, 100, 243), NULL,
                           "PUNTAJE: %d",
                           puntaje);



        // rest(velocidad);
        enemigo=aparecer(enemigo,j);
        enemigo2=aparecer(enemigo2,j);
        enemigo3=aparecer(enemigo3,j);



          j++;


    }

    }

    guardarPuntaje(pf,puntaje);
    //fclose(pf);


    destroy_bitmap(buffer);
    destroy_bitmap(nave);
    destroy_bitmap(nube);
    allegro_exit();
    menuInicio();
    //system("C:\Users\acerv5\Desktop\Juego_Final\StarConquer\bin\Debug\StarConquer.exe");

}END_OF_FUNCTION();
 BITMAP *aparecer(BITMAP *enemigo,int i)
    {
        if(i++%3000==0)
            enemigo=load_bitmap("enemigo.bmp",NULL);

    return enemigo;
    }

void iniciar2()
{
     //variables para acelerar juego

    int cuenta=2,velocidad=5;

    //inicia_allegro(500,450);
    //inicia_audio(70,70);

    BITMAP *nave = load_bitmap("nave.bmp",NULL);
    BITMAP *nube = load_bitmap("nube.bmp",NULL);
    BITMAP *bala = load_bitmap("Bala_amarilla.bmp", NULL);  // otra cosa
    BITMAP *buffer = create_bitmap(500,450);
    FONT *fuente=load_font("font.pcx", NULL, NULL);
    BITMAP *enemigo=load_bitmap("enemigo.bmp",NULL);
    BITMAP *enemigo2=load_bitmap("enemigo.bmp",NULL);
    BITMAP *enemigo3=load_bitmap("enemigo.bmp",NULL);


    int i = 450 , dsw = 0 , contt = 0;
    int pausa=0,modu=3;

    int puntaje;

    Sonidos son;


    //proceso lectura datos anteriormente guardados
    int j=2;

    FILE *pf;
    ordenarPuntajes(pf);
    leerPuntaje(pf,&puntaje);

    int *posicionNave=leerPosicionNave(pf);
    nav.x=posicionNave[0];
    nav.y=posicionNave[1];
    nav.dir=posicionNave[2];
    nav.ndisparos=posicionNave[3];



    int derrotado=0;
    while(!key[KEY_ESC]){


    if(key[KEY_P])
        pausar(&pausa);


    if(pausa==0)
    {

        blit(nube,buffer,0,--i,0,0,500,450);  if(i == 0) i=450;


        pintar_nave(nave,buffer,nav);
        printEnemigo(enemigo,buffer,ene);
        printEnemigo(enemigo2,buffer,ene2);
        printEnemigo(enemigo3,buffer,ene3);



       if(key[KEY_UP])        { nav.dir = 1; nav.y -= 1; }
       else if(key[KEY_DOWN]) { nav.dir = 1; nav.y += 2; }
       if(key[KEY_RIGHT])     { nav.dir = 2; nav.x += 1; }
       else if(key[KEY_LEFT]) { nav.dir = 0; nav.x -= 1; }
       else nav.dir = 1;

       guardarPosiciones(pf,nav.x,nav.y,nav.dir,nav.ndisparos);

       //parte disparos
       if(key[KEY_SPACE])
       {

           if(nav.ndisparos<maxdisp)
           {

                nav.ndisparos++;
           disparos[nav.ndisparos].x=nav.x+20;
           disparos[nav.ndisparos].y=nav.y;

           disparos[nav.ndisparos].dx=0;
           disparos[nav.ndisparos].dy=-3;
           dsw=1;
           }

           if(contt++>4)
           {
               dsw=0;
               contt=0;
               // play_sample(seleccionarSonido(), 200, 200, 100000, 0);
                 play_sample(seleccionarSonido(), 255, 127, 1000, 0);
           }
       }
          if(nav.ndisparos>0)
    {
        for(int cont=1;cont<=nav.ndisparos;cont++)
        {
            disparos[cont].x+=disparos[cont].dx;
            disparos[cont].y+=disparos[cont].dy;
            //pintar bala
           printBala(bala,buffer,disparos[cont],cont);

            if(disparos[cont].y==ene.y)
            {
                enemigo=load_bitmap("derrotado.bmp",NULL);
                 printEnemigo(enemigo,buffer,ene);
                 derrotado=1;
                 puntaje+=100;
            }
            else if(disparos[cont].y==ene2.y)
            {
                enemigo2=load_bitmap("derrotado.bmp",NULL);
                printEnemigo(enemigo2,buffer,ene2);
            }



            if(disparos[cont].y>ALTO||disparos[cont].y<0||disparos[cont].x>ANCHO||disparos[cont].x<0)
            {
                disparos[cont]=disparos[nav.ndisparos];
                nav.ndisparos--;
                if(nav.ndisparos<0) nav.ndisparos=0;
            }
        }

    }

    if(derrotado==0)
    {
        if(ene.ndisparos<maxdisp)
           {
                ene.ndisparos++;
           disparosEne[ene.ndisparos].x=ene.x+20;
           disparosEne[ene.ndisparos].y=ene.y;

           disparos[ene.ndisparos].dx=0;
           disparos[ene.ndisparos].dy=3;
           //dsw=1;
           }
           guardarPosiciones(pf,nav.x,nav.y,nav.dir,nav.ndisparos);

           /*if(contt++>4)
           {
               dsw=0;
               contt=0;
           }*/

          for(int cont=1;cont<=ene.ndisparos;cont++)
           {
            disparosEne[cont].x+=disparosEne[cont].dx;
            disparosEne[cont].y+=disparosEne[cont].dy;

            //pintar bala
           printBalaEnemigo(bala,buffer,disparosEne[cont],cont);

            if(disparosEne[cont].y==nav.y&&nav.x<=disparosEne[cont].x-30||nav.x>=disparosEne[cont].x+30)
               // nave=load_bitmap("derrotado.bmp",NULL);
            //printEnemigo(enemigo,buffer,nav);

            if(disparos[cont].y>ALTO||disparos[cont].y<0||disparos[cont].x>ANCHO||disparos[cont].x<0)
            {
                disparos[cont]=disparos[nav.ndisparos];
                nav.ndisparos--;
                if(nav.ndisparos<0) nav.ndisparos=0;
            }
          }

    }



    if(ene.y>10)
        ene.y--;

       blit(buffer,screen,0,0,0,0,500,450);
       if(cuenta++%5000==0&&velocidad>0)
       {
           velocidad--;
       }
       textprintf_centre_ex(screen, fuente, 400, 0,makecol(0, 100, 243), NULL,
                           "PUNTAJE: %d",
                           puntaje);

         //rest(velocidad);
        enemigo=aparecer(enemigo,j);
        enemigo2=aparecer(enemigo2,j);
        enemigo3=aparecer(enemigo3,j);
        j++;

    }

    }

    guardarPuntaje(pf,puntaje);


    destroy_bitmap(buffer);
    destroy_bitmap(nave);
    destroy_bitmap(nube);

      allegro_exit();
    menuInicio();
}END_OF_FUNCTION();


//funciones nuevas
void pedirDatos()
{
	FILE *pf;
	char a;
	printf("Ingresa una letra: ");
	scanf("%c",&a);
	guardarNombre(pf,a);

}

void guardarNombre(FILE *pf,char a)
{
	pf=fopen("letraScore.txt","a");

	if(pf==NULL)
        printf("error:\n");

	fprintf(pf, "%c ", a);
	fclose(pf);

}



