# Galaga_Game
## My version of galaga game made in c++ with allegro library for the graphical interface:
### Menu

First there's a menu with four different options:

* Inicio (start)
* Continuar (Continue)
* Puntajes (Score)
* Salir (exit)

![GitHub Logo](/Sample/1.png)

So for the continue option I created some text files with boolean flags, last position of character and enemies so it could be possible to do a checkpoint.
# Score
For the score option I implemented 'Bubble-sort', according to my professor I couldn't use functions like sort so I could implement my own sorting algorithm, I chosed this one, because I knew that I would'n save a lot of scores so even when it is O(n^2) it wouldn't be reflected.

``` c++
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

```


# Exit
By putting the mouse pointer upon the exit button it left the game, but after pressing it shows a different image that makes a more beautiful menu.
![GitHub Logo](/Sample/3.png)

# Start

Now the interesting part of the game:

By clicking over this button, it left the menu so you can play.
You can move by pressing the arrow buttons, up, left, down and right.
and to shoot just press the space button.

![GitHub Logo](/Sample/5.png)
![GitHub Logo](/Sample/6.png)

The first time that you get to kill an enemy, you will be able to see your score in the top left corner in blue.

![GitHub Logo](/Sample/7.png)
![GitHub Logo](/Sample/8.png)