#include "Game.h"


void GameOptionsMenu(){
    int option;
    
    option = CreateGameMenu();

    switch(option){

        case 1:
            StartGame();

            break;

        case 2:
            //ShowLeaderboards(gameStats);
            break;

        case 3:
            exit(0);
            system("exit");
        break;

    }

    GameOptionsMenu();
}





        
          







