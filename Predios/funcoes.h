#ifndef FUNCOES;
    #define FUNCOES;
    int altura_predio, largura_predio, width_game, height_game;
        //função pra limite da tela

        //função pra construir o predio
        void predio(){
        altura_predio = 10;

        int height_game, width_game, start_y, start_x;
    height_game = 20;
    width_game = 160;
    start_x = 0;
    start_y = 10;


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



}
        //função da posição do macaco

#endif // FUNCOES
