
typedef struct{
	int cx[5];
	int cy[5];
}Player;

void PrintPlayer(Player * player){

    mgotoxy(player->cx[1],player->cy[1]);
    printf("%c",219);
    mgotoxy(player->cx[2],player->cy[2]);
    printf("%c",219);
    mgotoxy(player->cx[3],player->cy[3]);
    printf("%c",219);
    mgotoxy(player->cx[4],player->cy[4]);
    printf("%c",219);
    mgotoxy(player->cx[5],player->cy[5]);
    printf("%c",219);
}


void InicializePlayer(Player * player){
	
	player->cx[1] = 15;
    player->cy[1] = 50;
    player->cx[2] = 17;
    player->cy[2] = 50;
    player->cx[3] = 16;
    player->cy[3] = 49;
    player->cx[4] = 15;
    player->cy[4] = 48;
    player->cx[5] = 17;
    player->cy[5] = 48;

    PrintPlayer(player);
}

void EraseLastPositionPlayer(Player * player){
	    mgotoxy(player->cx[1],player->cy[1]);
		printf(" ");
		mgotoxy(player->cx[2],player->cy[2]);
		printf(" ");
		mgotoxy(player->cx[3],player->cy[3]);
		printf(" ");
		mgotoxy(player->cx[4],player->cy[4]);
		printf(" ");
		mgotoxy(player->cx[5],player->cy[5]);
		printf(" ");
}

void MovePlayer(Player * player, int move_direction){

    if((move_direction == 0 &&  player->cx[1] > 1) || (move_direction == 2 &&  player->cx[1] < 27)){

	    if(move_direction==0){
	     	move_direction = -1;
	 	}else{ 
	 	 	move_direction = 1;
	 	}
	    
	 	EraseLastPositionPlayer(player);

	    player->cx[1] += move_direction;
	    player->cx[2] += move_direction;
	    player->cx[3] += move_direction;
	    player->cx[4] += move_direction;
	    player->cx[5] += move_direction;
	    
	    

	}

	PrintPlayer(player);
}


int VerifyColision(Player * player, Car * car){
	int i,z;

	for(i=1;i<=car->cont_cars;i++){
		if(car->carCordY[i]>47 && car->carCordY[i]<51){
			for(z=1;z<=5;z++){
				if(car->carCordX[i]==player->cx[z]){
					return (1);
				}
			}
		}
	}

	return (0);


}
