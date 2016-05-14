/**
*cartesian position
*/
void mgotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);

}

/**
*clean the display
*/
void clear(){
    int x,y;
    for (x = 0; x < 80; x++)
    {
        for (y = 0; y < 60; y++)
        {
            mgotoxy(x,y);
            printf(" ");
        }
    }
}