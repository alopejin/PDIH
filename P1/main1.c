#include <stdio.h>
#include "mi_io.h"

int main(){

    setvideomode(3);
    clrscr();

    textcolor(10);     
    textbackground(4);    

    gotoxy(10,5);
    printf("Texto en verde con fondo rojo");

    printf("\nPulsa una tecla para salir...");
    getche();

    return 0;
}