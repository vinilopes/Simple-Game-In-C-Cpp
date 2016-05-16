#include "lib\GameMenu.h"


int main(){

	/* Game config*/
	SetConsoleTitle("Death Runner");
	SetWindow(80,52); 
	//showIntro();
    system("cls");
	GameOptionsMenu();

	return(0);
}