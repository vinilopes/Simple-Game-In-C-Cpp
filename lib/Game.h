#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gameconfig.h"
#include "print.h"
#include "gameStats.h"
#include "Background.h"
#include "Carro.h"
#include "Player.h"



void StartGame(){
    char tecla='a';
    int move_diretion=10,pause=0, num;
    
    GameStats *gameStats = (GameStats *)malloc(sizeof(GameStats));
    Car *carEnemy = (Car *)malloc(sizeof(Car));
    
    /* Scene elements */
    CreateBoundary();
    CreateScoreBoundary();
    
    /* Player */
    Player *player = InicializePlayer();
    InicializeScore(gameStats);

    srand(time(NULL));

        while(tecla!='s')
        {
            while(tecla!='s' && !(tecla=kbhit()))
            {
                pause = VerifyPause(pause);
                MovePlayer(player, move_diretion);
                SendScore(gameStats);

                if(Spanwtime(gameStats)){//spanwtime
                    num =1;
                    if(gameStats->speedEnemy<90)
                        num=2;
                    if(gameStats->speedEnemy<50)
                      num=3;
                    
                    CreateEnemyCar(carEnemy,num);
                    AtualizeScore(gameStats);
                }else{
                    MoveEnemyCar(carEnemy);
                }
                if(VerifyColision(player, carEnemy)){
                    tecla = 's';
                }else{
                    
                }

                move_diretion=10;
                Sleep(gameStats->speedEnemy);//framerate

           }
           //check which key is pressed 
            if(tecla!='s')tecla=getch();
            if(tecla=='K')move_diretion=0;//left
            if(tecla=='M')move_diretion=2;//right
            if(tecla==27)pause=1;//right
        } 
        Sleep(200);
        clear();
        //SaveScore(gameStats);     
        //ShowScore();
        free(player);
        free(carEnemy);
        free(gameStats);
       
}
