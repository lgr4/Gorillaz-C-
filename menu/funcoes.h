#ifndef FUNCOES;
    #define FUNCOES;
    int altura_predio, largura_predio, width_game, height_game;
    int y, x, position_monkeyA, height_game, width_game, start_y, start_x;
        //função pra limite da tela

        //função pra construir o predio
        void predio(){
        ;


        int y, x, position_monkeyA, height_game, width_game, start_y, start_x,largura_predioA, largura_predioB;
        altura_predio = 10;
    getmaxyx(stdscr, y, x);
    height_game = y;
    width_game = 160;
    start_x = 0;
    start_y = 10;
    WINDOW * jogowin = newwin(y, x, 0, 0);
                            refresh();
    position_monkeyA = y/2 + 10;

        //predio 1
        do{
        for(largura_predio = 0; largura_predio <= width_game; largura_predio++){
            //mvprintw(linha, coluna, argumento)
            mvwprintw(jogowin,position_monkeyA, largura_predio, "P");


            }
        position_monkeyA+=1;


        }while(altura_predio<=y);



}
        //função de não saber como resolver problema
        void gambiarra(){
        //char array[] = {"P", "|"};
        WINDOW * jogowin = newwin(y, x, 0, 0);
                            refresh();
        int largura_predio, altura_predio;
        altura_predio = y/2;
        for(altura_predio=y/2; altura_predio<=y;altura_predio+=1){

            mvwprintw(jogowin,altura_predio, 1, "%s", "PPPPPPPPPPPPPPPPPPPP");
            mvwprintw(jogowin,altura_predio, x-4, "%s", "PPPPPPPPPPPPPPPPPPPP");
        };


        };

#endif // FUNCOES
