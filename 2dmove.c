#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <termios.h>

#define X 9
#define Y X

int posx = (X/2)+1;
int posy = (Y/2)+1;

char grid[Y][X];

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void boardInit(){
	for (int i=0; i<=X-1; i++) {
		for (int j=0; j<=Y-1; j++) {
			grid[i][j]='#';
		}
	}
}

void boardRefresh(){
	for (int i=0; i<=X-1; i++) {
		for (int j=0; j<=Y-1; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void controls( char input ){
	switch (input){
		case 'w':
			posy--;
			grid[posy][posx-1]='#';
			break;

		case 's':
			grid[posy-1][posx-1]='#';
			posy++;
			break;

		case 'a':
			posx--;
			grid[posy-1][posx]='#';
			break;

		case 'd':
			grid[posy-1][posx-1]='#';
			posx++;
			break;
	}
}

void mainLoop(){
	char r;
	grid[posy-1][posx-1]='X';
	boardRefresh();
	scanf("%c", &r);
	controls(r);
	delay(5);
	system("clear");
	mainLoop();
}

int main(){
	boardInit();
	mainLoop();
}
