#include <stdio.h>
#include "mi_io.h"

int main(){

    setvideomode(3);
    clrscr();

    printf("Cursor normal");
    setcursortype(1);
    getche();

    printf("\nCursor grueso");
    setcursortype(2);
    getche();

    printf("\nCursor invisible");
    setcursortype(0);
    getche();

    setcursortype(1);

    return 0;
}