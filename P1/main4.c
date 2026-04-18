#include <stdio.h>
#include "mi_io.h"

int main(){

    int i;
    unsigned char modo;

    setvideomode(4);

    for(i = 0; i < 100; i++){
        pixel(100+i,100,1);
        pixel(100,100+i,2);
    }

    for(i = 0; i < 100; i++){
        pixel(50+i,50+i,3);
    }

    getche();

    modo = getvideomode();

    setvideomode(3);
    clrscr();

    gotoxy(5,5);
    printf("Modo de video inicial: %d", modo);

    modo = getvideomode();

    gotoxy(5,7);
    printf("Modo de video actual (texto): %d", modo);

    gotoxy(5,9);
    printf("Pulsa una tecla para salir...");

    getche();

    return 0;
}