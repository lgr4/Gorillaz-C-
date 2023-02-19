#include <stdio.h>
#include <string.h>
#include <curses.h>

int main()
{
    initscr();
    keypad(stdscr, true); //Para o programa reconhecer as setas do teclado.

    char menu[3][100] = {"Jogo", "Dificuldades", "Sair"}; //Criando o menu.

    char difficulties[3][100] = {"Easy", "Intermediate", "Hard"}; //Criando as opções de dificuldades.

    int y, x, j, opcao, opcao1, marcador = 0, marcador1 = 0, fim = 0, pontos = 0;

    char macaco = '@';

    getmaxyx(stdscr, y, x);

    do{

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

                //Jogo:

                /*

                switch (marcador1) {
                    case 1: //Dificuldade fácil:
                }

                //O codigo do jogo a seguir deve ser colocado em cada switch: case 1 = nivel facil, case 2 = medio, ...

                WINDOW * jogowin = newwin(y, x, 0, 0);
                refresh();

                //Cria o espaço do jogo.

                box(jogowin, 0, 0);

                mvwprintw(jogowin, y/2 + 9, 4, "@");
                mvwprintw(jogowin, y/2 + 9, x-6, "@");

                mvwprintw(jogowin, y/2 + 10, 3, "%s", macaco);
                mvwprintw(jogowin, y/2 + 10, x-5, "%s", macaco);

                wrefresh(jogowin);

                //Lançamento da primeira banana.

                do{

                    wclear(jogowin);

                    x1 += 1;
                    y1 -= 1;

                    box(jogowin, 0, 0);

                    mvwprintw(jogowin, y/2 + 10, 3, "%s", macacoD);
                    mvwprintw(jogowin, y/2 + 10, x-5, "%s", macacoD);

                    mvwprintw(jogowin, y/2 + 9 + y1, x1, "%@");
                    mvwprintw(jogowin, y/2 + 9, x - 6, "%@");


                    wrefresh(jogowin);

                    t += 1;

                    getch();

                } while (t < 10);

                //Pontuação do primeiro lancamento:

                if((x1 == x - 5 && y1 = y/2 +10) || (x1 == x - 6 && y1 = y/2 +9)){
                    pontos += 100;
                }



                //Pontuação do segundo lancamento:

                if((x1 == 3 && y1 == y/2 +10) || (x1 == 4 && y1 == y/2 +9)){
                    pontos -= 100;
                }

                getch();*/

                break;
            case 1:
                clear();

                do{
                    for(j = 0; j < 3; j++){
                        if(j == marcador1){
                            attron(A_REVERSE);
                        }
                        mvprintw(y/2 - 1 + j, x/2 - strlen(difficulties[j])/2, "%s", difficulties[j]);
                        attroff(A_REVERSE);
                    }

                    opcao1 = getch();

                    if (opcao1 == KEY_UP){
                        marcador1--;
                    } else if (opcao1 == KEY_DOWN){
                        marcador1++;
                    }

                    if(marcador1 == -1){
                        marcador1 = 2;
                    } else if(marcador1 == 3){
                        marcador1 = 0;
                    }

                }while(opcao1 != 10);

                clear(); //Limpando a tela.

                break;

            case 2:
                clear();
                fim += 1;
                break;
        }

    } while(fim != 1);

    getch();
    endwin();
}
