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
extern int headX;
extern int headY;
extern PtWidget_t *snakeBody[300];


void grow(){
		int nextMoveX = 0;
		int nextMoveY = 0;
		if (curD == 1){
			nextMoveY = -1;
		}
		
		else if (curD == 2){
			nextMoveX = 1;
		}
		
		else if (curD == 3){
			nextMoveY = 1;
		}
		
		else{
			nextMoveX = -1;
		}
		int i;
		for(i =1; i< length; i++){
				if ((headX + nextMoveX) == moveX[counter- i] && (headY +nextMoveY) == moveY[counter -i]){
					clearAll();
			}
		}
		for(i = 0; i < 10; i++){
			if ((headX + nextMoveX) == obsX[i] && (headY +nextMoveY) == obsY[i]){
				clearAll();
			}
		}

		if ((headX + nextMoveX) == foodX && (headY +nextMoveY) == foodY){
				level +=1;
				PtArg_t 	args[4];
				char buffer[50];
				char str[20] = "Level: ";
				char * levelLabel = strcat(str, itoa(level,buffer,10) );
				PtSetArg(&args[0],Pt_ARG_TEXT_STRING,levelLabel, 0);
				PtSetResources(ABW_LevelText, 1, args);
			
				PtSetArg(&args[0], Pt_ARG_TIMER_INITIAL, 0, 0);
				PtSetResources(ABW_FoodTimer, 1, args);
				PtSetArg(&args[0], Pt_ARG_TIMER_REPEAT, 0, 0);
				PtSetResources(ABW_FoodTimer, 1, args);
				PtSetArg(&args[0], Pt_ARG_TIMER_INITIAL, 10000, 0);
				PtSetResources(ABW_FoodTimer, 1, args);
				PtSetArg(&args[0], Pt_ARG_TIMER_REPEAT, 10000, 0);
				PtSetResources(ABW_FoodTimer, 1, args);
				if (snakeSpeed > 300){
					snakeSpeed-=50;
				}
				PtSetArg(&args[0], Pt_ARG_TIMER_INITIAL, 0, 0);
				PtSetResources(ABW_SnakeTimer, 1, args);
				PtSetArg(&args[0], Pt_ARG_TIMER_INITIAL, snakeSpeed, 0);
				PtSetResources(ABW_SnakeTimer, 1, args);
				PtSetArg(&args[0], Pt_ARG_TIMER_REPEAT,snakeSpeed , 0);
				PtSetResources(ABW_SnakeTimer, 1, args);
				
			
				moveFood();
				//Add snakebody 
				PtArg_t 	argsSnake[4];
				PtSetArg(&argsSnake[0], Pt_ARG_FILL_COLOR, Pg_YELLOW, 0);
    			PhPoint_t pos1 = {xAxis[moveX[counter-length]], yAxis[moveY[counter-length]]};
				PtSetArg(&argsSnake[1], Pt_ARG_POS, &pos1, 0);
				PtSetArg(&argsSnake[2], Pt_ARG_HEIGHT, 17, 0);
				PtSetArg(&argsSnake[3], Pt_ARG_WIDTH, 20, 0);
				snakeBody[length] = PtCreateWidget( PtRect, ABW_gBkgd, 4, argsSnake);
				PtRealizeWidget(snakeBody[length]);
				length++;
		}		
}
#/** PhEDIT attribute block
#-11:16777215
#0:2641:default:-3:-3:0
#2641:2711:default:-3:-3:2
#2711:2772:default:-3:-3:0
#**  PhEDIT attribute block ends (-0000167)**/
