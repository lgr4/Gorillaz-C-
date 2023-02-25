#include <string.h>
#include <curses.h>
#include <math.h>

void main()
{
    initscr();
    keypad(stdscr, true); //Para o programa reconhecer as setas do teclado.

    char menu[4][100] = {"Jogo", "Dificuldades", "Ranking", "Sair"}; //Criando o menu.

    char continuar[2][100] = {"Continuar", "Sair"};

    char difficulties[2][100] = {"Easy", "Hard"}; //Criando as opções de dificuldades.

    int y, x, j, opcao, opcao1, marcador = 0, marcador1 = 0, fim = 0, opcao2, marcador2 = 0;

    char macaco = '@';

    char jogadores[6][100];
    int pontuacao[6];
    int contadores = 0;

    int x1,x2,y1,y2, t = 0;

    getmaxyx(stdscr, y, x);

    do{

        do{
            for(j = 0; j < 4; j++){
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
            } else if(marcador == 4){
                marcador = 0;
            }

        }while(opcao != 10);

        clear(); //Limpando a tela.

        switch(marcador){
            case 0: //Jogo

                switch(marcador1){
                    case 0:

                        mvprintw(y/2, x/2 - 11, "Digite seu nome: ");
                        scanw("%s", &jogadores[contadores]);
                        pontuacao[contadores] = 0;

                        clear();

                        do {

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

                            mvprintw(1, x/2 - strlen("Points")/2, "Points: %d", pontuacao[contadores]);

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

                            WINDOW * facilwin = newwin(y-3, x, 3, 0);
                            refresh();

                            box(facilwin, 0, 0);

                            mvwprintw(facilwin, y/2 + 10, 3, "%c", macaco);
                            mvwprintw(facilwin, y/2 + 10, x-4, "%c", macaco);

                            mvwprintw(facilwin, y/2 + 9, 4, "B");
                            mvwprintw(facilwin, y/2 + 9, x - 5, "B");


                            wrefresh(facilwin);

                            //Solicita as informações ao usuário.
                            int vel1, ang1, vel2, ang2;

                            mvwscanw(vel1win, 1,12, "%d", &vel1);
                            mvwscanw(ang1win, 1, 9, "%d", &ang1);
                            mvwscanw(vel2win, 1,12, "%d", &vel2);
                            mvwscanw(ang2win, 1, 9, "%d", &ang2);

                            float rad1, rad2;

                            rad1 = (3.1415*ang1)/180;
                            rad2 = (3.1415*ang2)/180;

                            clear();

                            WINDOW * jogowin = newwin(y, x, 0, 0);
                            refresh();

                            do{


                                x1 = 4 + floor(t*vel1*cos(rad1));
                                y1 = y/2 + 9 - floor(t*vel1*cos(rad1)/2) + floor(3*t*t/2);

                                box(jogowin, 0, 0);

                                mvwprintw(jogowin, y/2 + 10, 3, "%c", macaco);
                                mvwprintw(jogowin, y/2 + 10, x-4, "%c", macaco);

                                mvwprintw(jogowin, y1, x1, "B");
                                mvwprintw(jogowin, y/2 + 9, x - 5, "B");

                                wrefresh(jogowin);

                                sleep(1);


                                if (x1 >= x-4 || y1 > y){
                                    t = 0;
                                    break;
                                }

                                t++;

                                wclear(jogowin);

                            } while(true);

                            if(x1 == x - 5 && y1 == y/2 +10){
                                pontuacao[contadores] += 100;
                            } else if (x1 == x - 6 && y1 == y/2 +9){
                                pontuacao[contadores] += 100;
                            }

                            do{

                                x2 = x - 5 - floor(t*vel2*cos(rad2));
                                y2 = y/2 + 9 - floor(t*vel2*cos(rad2)/2) + floor(3*t*t/2);

                                box(jogowin, 0, 0);

                                mvwprintw(jogowin, y/2 + 10, 3, "%c", macaco);
                                mvwprintw(jogowin, y/2 + 10, x-4, "%c", macaco);

                                mvwprintw(jogowin, y/2 + 9, 4, "B");
                                mvwprintw(jogowin, y2, x2, "B");

                                wrefresh(jogowin);

                                sleep(1);


                                if (x2 <= 4 || y2 >= y){
                                    t = 0;
                                    break;
                                }

                                t++;

                                wclear(jogowin);

                            } while(true);

                            //Pontuação do segundo lancamento:

                            if(x1 == 3 && y1 == y/2 +10){
                                pontuacao[contadores] -= 100;
                            } else if (x1 == 4 && y1 == y/2 +9) {
                                pontuacao[contadores] -= 100;
                            }

                            endwin();

                            clear();

                            do{
                                for(j = 0; j < 2; j++){
                                    if(j == marcador2){
                                        attron(A_REVERSE);
                                    }
                                    mvprintw(y/2  + j, x/2 - strlen(continuar[j])/2, "%s", continuar[j]);
                                    attroff(A_REVERSE);
                                }

                                opcao2 = getch();

                                if (opcao2 == KEY_UP){
                                    marcador2--;
                                } else if (opcao2 == KEY_DOWN){
                                    marcador2++;
                                }

                                if(marcador2 == -1){
                                    marcador2 = 1;
                                } else if(marcador2 == 2){
                                    marcador2 = 0;
                                }

                            }while(opcao2 != 10);

                            clear(); //Limpando a tela.

                        } while (marcador2 != 1);

                        contadores++;

                        break;

                    case 1:

                        mvprintw(y/2, x/2 - 11, "Digite seu nome: ");
                        scanw("%s", &jogadores[contadores]);
                        pontuacao[contadores] = 0;

                        clear();

                        do {

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

                            mvprintw(1, x/2 - strlen("Points")/2, "Points: %d", pontuacao[contadores]);

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

                            //Solicita as informações ao usuário.
                            int vel1, ang1, vel2, ang2;

                            mvwscanw(vel1win, 1,12, "%d", &vel1);
                            mvwscanw(ang1win, 1, 9, "%d", &ang1);
                            mvwscanw(vel2win, 1,12, "%d", &vel2);
                            mvwscanw(ang2win, 1, 9, "%d", &ang2);

                            float rad1, rad2;

                            rad1 = (3.1415*ang1)/180;
                            rad2 = (3.1415*ang2)/180;

                            clear();

                            WINDOW * jogowin = newwin(y, x, 0, 0);
                            refresh();

                            do{


                                x1 = 4 + floor(t*vel1*cos(rad1));
                                y1 = y/2 + 9 - floor(t*vel1*cos(rad1)/2) + floor(3*t*t/2);

                                box(jogowin, 0, 0);

                                mvwprintw(jogowin, y/2 + 10, 3, "%c", macaco);
                                mvwprintw(jogowin, y/2 + 10, x-4, "%c", macaco);

                                mvwprintw(jogowin, y1, x1, "B");
                                mvwprintw(jogowin, y/2 + 9, x - 5, "B");

                                wrefresh(jogowin);

                                sleep(1);


                                if (x1 >= x-4 || y1 > y){
                                    t = 0;
                                    break;
                                }

                                t++;

                                wclear(jogowin);

                            } while(true);

                            if(x1 == x - 5 && y1 == y/2 +10){
                                pontuacao[contadores] += 100;
                            } else if (x1 == x - 6 && y1 == y/2 +9){
                                pontuacao[contadores] += 100;
                            }

                            do{

                                x2 = x - 5 - floor(t*vel2*cos(rad2));
                                y2 = y/2 + 9 - floor(t*vel2*cos(rad2)/2) + floor(3*t*t/2);

                                box(jogowin, 0, 0);

                                mvwprintw(jogowin, y/2 + 10, 3, "%c", macaco);
                                mvwprintw(jogowin, y/2 + 10, x-4, "%c", macaco);

                                mvwprintw(jogowin, y/2 + 9, 4, "B");
                                mvwprintw(jogowin, y2, x2, "B");

                                wrefresh(jogowin);

                                sleep(1);


                                if (x2 <= 4 || y2 >= y){
                                    t = 0;
                                    break;
                                }

                                t++;

                                wclear(jogowin);

                            } while(true);

                            //Pontuação do segundo lancamento:

                            if(x1 == 3 && y1 == y/2 +10){
                                pontuacao[contadores] -= 100;
                            } else if (x1 == 4 && y1 == y/2 +9) {
                                pontuacao[contadores] -= 100;
                            }

                            endwin();

                            clear();

                            do{
                                for(j = 0; j < 2; j++){
                                    if(j == marcador2){
                                        attron(A_REVERSE);
                                    }
                                    mvprintw(y/2  + j, x/2 - strlen(continuar[j])/2, "%s", continuar[j]);
                                    attroff(A_REVERSE);
                                }

                                opcao2 = getch();

                                if (opcao2 == KEY_UP){
                                    marcador2--;
                                } else if (opcao2 == KEY_DOWN){
                                    marcador2++;
                                }

                                if(marcador2 == -1){
                                    marcador2 = 1;
                                } else if(marcador2 == 2){
                                    marcador2 = 0;
                                }

                            }while(opcao2 != 10);

                            clear(); //Limpando a tela.

                        } while (marcador2 != 1);

                        contadores++;

                        break;
                }

                break;


            case 1:
                clear();

                do{
                    for(j = 0; j < 2; j++){
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
                        marcador1 = 1;
                    } else if(marcador1 == 2){
                        marcador1 = 0;
                    }

                }while(opcao1 != 10);

                clear(); //Limpando a tela.

                break;

            case 2:
                clear();

                mvprintw(y/2 - 3, x/2 - 10, "Jogador: (...) pontos.");

                //Falta montar o codigo que organiza a pontuacao em ordem decrescente.

                for(j = 0; j < contadores; j++){
                    mvprintw(y/2 - 2 + j, x/2 - 10, "%s: %d pontos.", jogadores[j], pontuacao);
                }

                getch();

                clear();

                break;

            case 3:
                clear();
                fim += 1;
                break;
        }

    } while(fim != 1);

    getch();
    endwin();
}
