#include <stdio.h>
#define _CRT_WARNING
#define SIZE 25

void printFloor(int floor[SIZE][SIZE], int turtlePosition[], int direction);
void moveForward(int floor[SIZE][SIZE], int moves, int penPosition, int turtlePosition[], int direction);
int turnLeft(int direction);
int turnRight(int direction);
//void makeCircle(int floor[SIZE][SIZE], int turtlePosition[], int direction, int radius);

void main(void) {

	static int floor[SIZE][SIZE] = { {0} };
	int turtlePosition[] = { 0,0 };
	static int penPosition = 0;
	int moves = 0;
	int direction = 1;
	int command;

	
	do {
		printf("Enter your command: ");
		scanf_s("%d", &command);
			switch (command) {
			case 1: //Pen UP
				penPosition = 0;
				break;
			case 2://Ped DOWN
				penPosition = 1;
				break;
			case 3://Turn RIGHT
				direction = turnRight(direction);
				break;
			case 4://Turn LEFT
				direction = turnLeft(direction);
				break;
			case 5://MOVE forward, x number of spaces
				printf("How many spaces forward: ");
				scanf_s("%d", &moves);
				moveForward(floor, moves, penPosition, turtlePosition, direction);
				break;
			case 6://PRINT FLOOR
				printFloor(floor, turtlePosition, direction);
				break;
			}
			printFloor(floor, turtlePosition, direction);
	} while (command != 9);
	
}

int turnRight(int direction) {
	if (direction == 4) {
		return direction = 1;
	}
	else {
		return direction+=1;
	}
}

int turnLeft(int direction) {
	if (direction == 1) {
		return direction = 4;
	}
	else {
		return direction-=1;
	}
}
	
void moveForward(int floor[SIZE][SIZE], int moves, int penPosition, int turtlePosition[], int direction) {

	for (int i = 0; i < moves; i++) {

		if (penPosition) {
			floor[turtlePosition[0]][turtlePosition[1]] = 1;
			switch (direction) {
				case 1:
					turtlePosition[1] = turtlePosition[1] + 1; //column of the turtle is increased by 1
					break;
				case 2:
					turtlePosition[0] = turtlePosition[0] + 1; //row of turtle is increased by 1
					break;
				case 3:
					turtlePosition[1] = turtlePosition[1] - 1; //column of the turtle is decreased by 1
					break;
				case 4:
					turtlePosition[0] = turtlePosition[0] - 1; //row of turtle is decreased by 1
					break;
			}
		}
		
		else {
			switch (direction) {
				case 1:
					turtlePosition[1] = turtlePosition[1] + 1;
					break;
				case 2:
					turtlePosition[0] = turtlePosition[0] + 1;
					break;
				case 3:
					turtlePosition[1] = turtlePosition[1] - 1;
					break;
				case 4:
					turtlePosition[0] = turtlePosition[0] - 1;
					break;
			}
		}			
	}
}

void printFloor(int floor[SIZE][SIZE], int turtlePosition[], int direction) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if ((i == turtlePosition[0]) && (j == turtlePosition[1])) {
				if (floor[i][j] == 1) {
					printf("%-2s", "o");
				}
				else {
					printf("%-2s", "_");
				}
				continue;
			}
				
			if (floor[i][j] == 0) {
				printf("  ");
			}
			else if (floor[i][j] == 1) {
				printf("* ");

			}
		}
		puts("");
	}
	switch (direction) {
	case 1:
		printf(">");
		break;
	case 2:
		printf("V");
		break;
	case 3:
		printf("<");
		break;
	case 4:
		printf("^");
		break;
	}
	puts("");
}

//void makeCircle(int floor[SIZE][SIZE], int turtlePosition[], int direction, int radius) {
	//direction = 1;
	//2,5,3,1,3,5,1,2,5,1





//
//      * * *
//    *       *
//  *           *
//*               *
//*               *
//*               *
//  *           *
//    *       *
//      * * *
//

