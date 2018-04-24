/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
extern int legnth;
extern int foodX;
extern int foodY;
extern PtWidget_t *snakeBody[300];
extern PtWidget_t *snakeObs[10];
extern int tempCurD;
void clearAll(){
	PtArg_t 	argsClear[4];
	PtSetArg(&argsClear[0], Pt_ARG_TIMER_INITIAL, 0, 0);

	PtSetResources(ABW_SnakeTimer, 1, argsClear);	
	PtSetArg(&argsClear[0], Pt_ARG_TIMER_INITIAL, 0, 0);
	PtSetResources(ABW_FoodTimer, 1, argsClear);

	curD = 1;		
	tempCurD = 1;
	int i = 0;
	
	for (i = 0; i < counter; i++){
			moveX[i] = 0;
			moveY[i] = 0;
	}
	if (snakeObs[0] != NULL){
		for (i = 0; i < 10; i++){
			PtUnrealizeWidget(snakeObs[i]);	
		}
	}
	counter = 0;
	
	PtArg_t 	argsSnakeHide[4];
	PhPoint_t posHide = {-10000, -10000};
	PtSetArg(&argsSnakeHide[0], Pt_ARG_POS, &posHide, 0);

	for(i = 0; i < length; i++){
		PtUnrealizeWidget(snakeBody[i]);	
		PtSetResources(snakeBody[i], 1, argsSnakeHide);
		//PtRealizeWidget(snakeBody[i]);
	}
	PtUnrealizeWidget(ABW_SnakeFood);
	PtRealizeWidget(ABW_gameOver);
}