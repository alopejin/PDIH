#include <stdio.h>
#include "mi_io.h"

int main(){

    setvideomode(3);
    clrscr();

    textcolor(14);

    gotoxy(30,5);
    printf("  /\\_/\\  ");

    gotoxy(30,6);
    printf(" ( o.o ) ");

    gotoxy(30,7);
    printf("  > ^ <  ");

    gotoxy(25,10);
    textcolor(11);
    printf("Gato");

    printf("\nPulsa una tecla para salir...")
    getche();

    return 0;
}