#include <dos.h>
#include "mi_io.h"

unsigned char attr = 7;


void gotoxy(int x, int y){
    union REGS r;
    r.h.ah = 0x02;
    r.h.bh = 0;
    r.h.dl = x;
    r.h.dh = y;
    int86(0x10, &r, &r);
}

void setcursortype(int tipo){
    union REGS r;
    r.h.ah = 0x01;

    if(tipo == 0){
        r.h.ch = 0x20;
        r.h.cl = 0x00;
    }
    else if(tipo == 1){
        r.h.ch = 0x06;
        r.h.cl = 0x07;
    }
    else{
        r.h.ch = 0x00;
        r.h.cl = 0x0F;
    }

    int86(0x10, &r, &r);
}

void setvideomode(unsigned char modo){
    union REGS r;
    r.h.ah = 0x00;
    r.h.al = modo;
    int86(0x10, &r, &r);
}


unsigned char getvideomode(){
    union REGS r;
    r.h.ah = 0x0F;
    int86(0x10, &r, &r);
    return r.h.al;
}

void textcolor(int color){
    attr = (attr & 0xF0) | (color & 0x0F);
}

void textbackground(int color){
    attr = (attr & 0x0F) | (color << 4);
}

void clrscr(){
    union REGS r;

    r.h.ah = 0x06;
    r.h.al = 0;
    r.h.bh = attr;
    r.h.ch = 0;
    r.h.cl = 0;
    r.h.dh = 24;
    r.h.dl = 79;

    int86(0x10, &r, &r);

    gotoxy(0,0);
}

void cputchar(char c){
    union REGS r;

    r.h.ah = 0x09;
    r.h.al = c;
    r.h.bh = 0;
    r.h.bl = attr;
    r.x.cx = 1;

    int86(0x10, &r, &r);
}

int getche(void){
    union REGS r;

    r.h.ah = 0x00;
    int86(0x21, &r, &r);

    return r.h.al;
}

void pixel(int x, int y, unsigned char color){
    union REGS r;

    r.h.ah = 0x0C;
    r.h.al = color;
    r.x.cx = x;
    r.x.dx = y;

    int86(0x10, &r, &r);
}

void recuadro(int x1, int y1, int x2, int y2){
    int i;

    for(i = x1; i <= x2; i++){
        gotoxy(i,y1); cputchar('-');
        gotoxy(i,y2); cputchar('-');
    }

    for(i = y1; i <= y2; i++){
        gotoxy(x1,i); cputchar('|');
        gotoxy(x2,i); cputchar('|');
    }
}