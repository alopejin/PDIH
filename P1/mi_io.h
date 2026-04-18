#ifndef MI_IO_H
#define MI_IO_H

#include <stdio.h>
#include <conio.h>


void gotoxy(int x, int y);
void setcursortype(int tipo);
void setvideomode(unsigned char modo);
unsigned char getvideomode(void);
void textcolor(int color);
void textbackground(int color);
void clrscr(void);
void cputchar(char c);
int getche(void);
void pixel(int x, int y, unsigned char color);
void recuadro(int x1, int y1, int x2, int y2);

#endif