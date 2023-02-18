#include <stdio.h>
#include <string.h>
#include <curses.h>

int main()
{
    initscr();
    keypad(stdscr, true); //Para o programa reconhecer as setas do teclado.

    char menu[3][100] = {"Jogo", "Dificuldades", "Sair"}; //Criando o menu.
    int y,x, j, opcao, marcador = 0;

    int pontos = 0; //Variáveis que serão utilizadas no jogo.

    int* janela; //Ponteiros que serão usados para criar janela/janelas.

    getmaxyx(stdscr, y, x);

    do{
        for(j = 0; j < 3; j++){
            if(j == marcador){
                attron(A_REVERSE); //Deixa a cor da ocpao diferente.
            }
            mvprintw(y/2 - 1 + j, x/2 - strlen(menu[j])/2, "%s", menu[j]);
            attroff(A_REVERSE);
        }

        opcao = getch();

        if (opcao == KEY_UP){
            marcador--;
        } else if (opcao == KEY_DOWN){
            marcador++;
        }

        if(marcador == -1){
            marcador = 2;
        } else if(marcador == 3){
            marcador = 0;
        }

    }while(opcao != 10);

    clear(); //Limpando a tela.

    switch(marcador){
        case 0: //Jogo

                getmaxyx(stdscr, y, x);

                WINDOW * vel1win = newwin(3, 20, 0, 0); //Cria os espaços onde o usuário vai digitar as informações.
                refresh();

                box(vel1win, 0, 0);
                mvwprintw(vel1win, 1,2, "Velocity:");
                wrefresh(vel1win);

                WINDOW * ang1win = newwin(3, 15, 0, 22);
                refresh();

                box(ang1win, 0, 0);
                mvwprintw(ang1win, 1,2, "Angle:");
                wrefresh(ang1win);

                mvprintw(1, x/2 - strlen("Points")/2, "Points: %d", pontos);

                WINDOW * ang2win = newwin(3, 15, 0, x-15);
                refresh();

                box(ang2win, 0, 0);
                mvwprintw(ang2win, 1,2, "Angle:");
                wrefresh(ang2win);

                WINDOW * vel2win = newwin(3, 20, 0, x-38);
                refresh();

                box(vel2win, 0, 0);
                mvwprintw(vel2win, 1,2, "Velocity:");
                wrefresh(vel2win);

                int vel1 = mvwscanw(vel1win, 1,12, "%d", &vel1); //Solicita as informações ao usuário.
                int ang1 = mvwscanw(ang1win, 1, 9, "%d", &ang1);
                int vel2 = mvwscanw(vel2win, 1,12, "%d", &vel2);
                int ang2 = mvwscanw(ang2win, 1, 9, "%d", &ang2);

                mvprintw(y/2, x/2 - strlen("Pressione uma tecla para continuar...")/2,"Pressione uma tecla para continuar...");

                getch();

                clear();

                WINDOW * jogowin = newwin(y, x, 0, 0); //Cria o espaço do jogo.
                refresh();

                box(jogowin, 0, 0);
                wrefresh(jogowin);

                getch();

                break;
        case 1:
            clear();
            printw("Voce escolheu Dificuldades!");
            break;

        case 2:
            clear();
            printw("Voce escolheu Sair!");
            break;
    }

    getch();
    endwin();
}
