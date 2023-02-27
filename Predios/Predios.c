#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include "funcoes.h"

int y, x, largura_predio,altura_predio;
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
    width_game = 160;
    start_x = 0;
    start_y = 10;

    WINDOW * win = newwin(height_game, width_game, start_y, start_x);
    refresh();




    box(win, 0, 0); //os numeros nessa função são os unicode pra os simbolos, 0 é um traço.
    wrefresh(win);

    altura_predio = 10;



        //predio 1
        do{
        for(largura_predio = 0; largura_predio <= width_game; largura_predio++){
            //mvprintw(linha, coluna, argumento)
            mvprintw(altura_predio, largura_predio, "P");
            refresh();

            }
        altura_predio+=1;
        refresh();

        }while(altura_predio<=height_game);








    wrefresh(win);


    refresh();

    int c = getch();
    endwin();
return ;
}


