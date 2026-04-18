#include <stdio.h>
#include "mi_io.h"

int main(){

    setvideomode(3);
    clrscr();

    gotoxy(10,5);
    printf("Pulsa una tecla: ");

    char c = getche();

    gotoxy(10,7);
    printf("Has pulsado: ");

    cputchar(c);
    cputchar('\n');

    printf("\nPulsa otra tecla para salir...")
    getche();

    return 0;
}