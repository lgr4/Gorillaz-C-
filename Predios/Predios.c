#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funcoes.h"

void main(){
    // começa o curses
    initscr();
    keypad(stdscr, true); //Para o programa reconhecer as setas do teclado.
    //define o y e o x da tela
    int y, x, yMax, xMax;


    getyx(stdscr, y, x);
    //pega o bvalor máximo de x e y da janela
    getmaxyx(stdscr, yMax, xMax);
    printf(AlturaAleatoria)



    endwin();
    return 0;
}

