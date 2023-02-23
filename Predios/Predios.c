#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include "funcoes.h"

int y, x, i,altura_predio;
// x é a largura máxima da tela
// y é a altura maáxima da tela
//i e altura_predio são usadas nas funções de gerar o predio.

void setup(){
    keypad(stdscr, true);
    noecho();
    getmaxyx(stdscr, y, x);
}


void main(){
    initscr();
    setup();
    int height_game, width_game, start_y, start_x;
    height_game = 20;
    width_game = x;
    start_x = 0;
    start_y = 10;

    WINDOW * win = newwin(height_game, width_game, start_y, start_x);
    refresh();


    box(win, 0, 0); //os numeros nessa função são os unicode pra os simbolos, 0 é um traço.
    for(q>15; q < height_game; q++){
        for(i>0; i< width_game; i++){
            mvwprintw(win,q,i, "P");
            wrefresh(win); //faz refresh so da window
        }
    }
    //raw();


    //int linha, coluna;
    //for (linha=0; linha < x; ++linha ){
    //    addch('P');
    //    refresh();
    //}
    //refresh();

    int c = getch();
    endwin();
return ;
}


