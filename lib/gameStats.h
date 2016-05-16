typedef struct{
	int score;
    int speed;
	int speedEnemy;
    int spanwtime;
}GameStats;

void InicializeScore(GameStats *gameStatics){

    gameStatics->speed = 1;
	gameStatics->speedEnemy = 100;
    gameStatics->score = 0;
	gameStatics->spanwtime = 13;

}

void AtualizeScore(GameStats *gameStatics){
	if(gameStatics->speedEnemy > 35){
        gameStatics->speedEnemy--;
        gameStatics->speed += 1;
    }
    
	gameStatics->score += 10;
}

int Spanwtime(GameStats *gameStatics){
    if(gameStatics->spanwtime==13){
        gameStatics->spanwtime = 0;
        return(1);
    }else{
        gameStatics->spanwtime++;
        return(0);
    }
}

void SaveScore(GameStats *gameStats){
    char user[45];
    char url_file[] = "leaderboards.txt";

    FILE *leaderboards = fopen(url_file, "a");

    for (int i = 0; i < 3; i++)
    {
        mgotoxy(30,20);
        printf ("NEW RECORD!");
        Sleep(350);
        mgotoxy(30,20);
        printf ("            ");
        Sleep(350);
    }
    mgotoxy(30,20);
    printf ("NEW RECORD!");
    mgotoxy(31,22);
    printf ("%d POINTS",gameStats->score);
    mgotoxy(28,26);
    printf("YOUR FIRST NAME: \n");
    mgotoxy(33,28);

    //gravar pontuação no arquivo txt    
    if (leaderboards == NULL) {
       printf ("Houve um erro ao abrir o arquivo.\n");
    }
    else
    {   

        scanf("%s", user);

        fprintf(leaderboards, "\n%s %d", user, gameStats->score);
        printf("Registrado com Sucesso!");
        fclose(leaderboards);
    }
}



void ShowLeaderboards(){

}