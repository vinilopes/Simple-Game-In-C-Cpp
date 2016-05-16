
void showIntro(){
	int x,y;
	for ( x = 0; x < 80; x++)
	{
		for (y = 25; y < 30; y++)
		{
			mgotoxy(x,y);
			printf("0");
		}
		for (y = 26; y < 31; y++)
		{
			if( ((x-1)== 2 )&& ((y-1)==27 ) )continue;
			mgotoxy(x-1,y-1);
			printf(" ");
		}
		

		 Sleep(50);
	}
	for ( y = 26; y < 31; y++)
		{

			mgotoxy(x,y);
			printf(" ");
		}

}


/**
*Defines the boundary of the set
*/
void CreateBoundary(){
	int x;
	
	/* vertical left */
	for(x=0;x<51;x++)
	{
	    mgotoxy(0,x);
	    printf("%c",219);
	}

	/* horizontal top */
	for(x=0;x<30;x++)
	{
	    mgotoxy(x,0);
	    printf("%c",219);
	}

	/* vertical right */
	for(x=0;x<51;x++)
	{
	    mgotoxy(30,x);
	    printf("%c",219);
	}

	/* horizontal bottom */
	for(x=0;x<31;x++)
	{
	    mgotoxy(x,51);
	    printf("%c",219);
	}
}

/**
*Defines the design of the score
*/
void CreateScoreBoundary(){

    mgotoxy(50,5);
    printf("%c DEATH RACE %c",197,197);  
    mgotoxy(31,9);
	printf("-------------------------------------------------");
	mgotoxy(52,10);
    printf("KEYS");
    mgotoxy(31,11);
	printf("-------------------------------------------------");
	mgotoxy(35,13);
    printf("-> Right    Esc Pause ");
    mgotoxy(35,15);
    printf("<- Left ");
    mgotoxy(31,17);
	printf("-------------------------------------------------");
    mgotoxy(52,18);
    printf("RULES");
    mgotoxy(31,19);
	printf("-------------------------------------------------");
    mgotoxy(35,21);
    printf("1. Dodge cars");
    mgotoxy(31,23);
	printf("-------------------------------------------------");
    mgotoxy(52,24);
    printf("SCORE");
    mgotoxy(31,25);
	printf("-------------------------------------------------");
  
}

/**
*Defines the menu of the game
*/
int option=0;

int CreateGameMenu(){
	char tecla=	1;
	int pos=1,x,y;
	
	if(option!=0)
	  clear();

	mgotoxy(0,5);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	mgotoxy(33,7);
	printf("DEATH RUNNER");
	 mgotoxy(38,8);
    printf("%c",197);
	mgotoxy(53,51);
	printf("Produced by Vinicius Lopes");
	mgotoxy(0,10);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	mgotoxy(35,22);
    printf("START GAME");
    mgotoxy(34,24);
    printf("LEADERBOARDS");
    mgotoxy(38,26);
    printf("EXIT");


    while(tecla!=13){
    	 while(tecla!=13 && !(tecla=kbhit())){
	    	
    	 	if(pos==1){
	    		x=33;y=22;
	    	}
	    	if(pos==2){
	    		x=32;y=24;
	    	}
	    	if(pos==3){
	    		x=36;y=26;
	    	}
	    	mgotoxy(x,y);
	    	printf(">");
	    	Sleep(350);
	    	mgotoxy(x,y);
	    	printf(" ");
	    	Sleep(350);
	    }
	     if(tecla!=13)tecla=getch();
         if((tecla==72 || tecla=='w') && pos != 1) pos--;
         if((tecla==80 || tecla=='s')&& pos != 3) pos++;

    }

    option = pos;
	clear();

    return option;
}

/**
*Defines the score and speed of the game
*/
void  SendScore(GameStats *gameStatics){
    mgotoxy(35,27);
    printf("POINTS:    %d",gameStatics->score);
    mgotoxy(35,29);
    printf("VELOCITY:  %d",gameStatics->speed);
}

/**
*Pause the game
*/
int VerifyPause(int option){
	char tecla='a';

	if (option==1)
	{
		while(tecla!=32 && !(tecla=kbhit()))
        {
			mgotoxy(45,33);
	    	printf("Press any key to continue");
	    	Sleep(350);
	    	mgotoxy(45,33);
	    	printf("                           ");
	    	Sleep(350);
		}		
           
	}
	return 0;
}
