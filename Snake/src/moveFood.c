#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "globals.h"

extern int yPos;
extern int xPos;
extern int curD;
extern int counter;
extern int moveX[10000];
extern int moveY[10000];
extern int yAxis[16];
extern int xAxis[15];
extern int length;
extern int obsX[10];
extern int obsY[10];

void moveFood(){

	PtUnrealizeWidget(ABW_SnakeFood);
	srand(time(NULL));
	int validFood;
	int i;
	do{
		validFood = 1;
		foodX = rand() % 15;
		foodY = rand() % 16;
		for(i = 0;  i < length; i++){
			if (foodX == moveX[counter - i] && foodY == moveY[counter - i]){
				validFood = 0;
				break;
			}
		}
		for(i = 0; i < 10; i++){
			if (foodX == obsX[i] && foodY == obsY[i]){
				validFood = 0;
				break;
			}
		}
		
		
	}while ( validFood == 0 );
	PtArg_t 	args[4];	
	PhPoint_t pos = {xAxis[foodX], yAxis[foodY]};
	PtSetArg(&args[0], Pt_ARG_POS, &pos, 0);
	PtSetResources(ABW_SnakeFood, 1, args);
	PtRealizeWidget(ABW_SnakeFood);


}


