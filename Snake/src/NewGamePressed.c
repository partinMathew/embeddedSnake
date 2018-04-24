/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "abdefine.h"
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
extern PtWidget_t *snakeBody[300];
extern int headX;
extern int headY;
extern int level;
extern int score;
extern PtWidget_t *snakeObs[10];
extern int obsX[10];
extern int obsY[10];

int
NewGamePressed( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{
	
		clearAll();
	srand(time(NULL));
		int i;
		int createObsX;
		int createObsY;
		PtArg_t 	argsObs[4];
		PtSetArg(&argsObs[0], Pt_ARG_FILL_COLOR, Pg_WHITE, 0);
		PtSetArg(&argsObs[2], Pt_ARG_HEIGHT, 17, 0);
		PtSetArg(&argsObs[3], Pt_ARG_WIDTH, 20, 0);
		for (i = 0; i < 10; i++){
    		createObsX = rand() % 15;
    		createObsY = rand() % 16;
    		obsX[i] = createObsX;
    		obsY[i] = createObsY;
    		
       		PhPoint_t posObs = {xAxis[createObsX], yAxis[createObsY]};
			PtSetArg(&argsObs[1], Pt_ARG_POS, &posObs, 0);

			snakeObs[i] = PtCreateWidget( PtRect, ABW_gBkgd, 4, argsObs);
			PtRealizeWidget(snakeObs[i]);
	}


	PtArg_t 	args[4];
	level = 1;
	score = 0;
	char buffer[50];
	char str[20] = "Score: ";
	char * scoreLabel = strcat(str, itoa(score,buffer,10) );
	PtSetArg(&args[0],Pt_ARG_TEXT_STRING,scoreLabel, 0);
	PtSetResources(ABW_ScoreText, 1, args);

	char str2[20] = "Level: ";
	char * levelLabel = strcat(str2, itoa(level,buffer,10) );
	PtSetArg(&args[0],Pt_ARG_TEXT_STRING,levelLabel, 0);
	PtSetResources(ABW_LevelText, 1, args);
	length = 0;
	counter = 2;
	moveX[0] = 1;
	moveY[0] = 8;

	moveX[1] = 1;
	moveY[1] = 9;	

	xPos = 1;
	yPos = 8;
	snakeSpeed = 1000;
	PtUnrealizeWidget(ABW_gameOver);
	PtSetArg(&args[0], Pt_ARG_TIMER_INITIAL, snakeSpeed, 0);
	PtSetResources(ABW_SnakeTimer, 1, args);	
	PtSetArg(&args[0], Pt_ARG_TIMER_REPEAT, snakeSpeed, 0);
	PtSetResources(ABW_SnakeTimer, 1, args);	
	PtSetArg(&args[0], Pt_ARG_TIMER_INITIAL, 10000, 0);
	PtSetResources(ABW_FoodTimer, 1, args);	
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
	
	//PtSetArg(&args[2], Pt_ARG_HEIGHT, 17, 0);
		PtArg_t 	argsSnake[4]; //Pt_ARG_COLOR, Pt_ARG_POS, Pt_ARG_WIDTH, Pt_ARG_HEIGHT
	
	//SnakeHead
	PtSetArg(&argsSnake[0], Pt_ARG_FILL_COLOR, Pg_GREEN, 0);
    PhPoint_t pos = {20, 136};
    headX = 20;
    headY = 136;
	PtSetArg(&argsSnake[1], Pt_ARG_POS, &pos, 0);
	PtSetArg(&argsSnake[2], Pt_ARG_HEIGHT, 17, 0);
	PtSetArg(&argsSnake[3], Pt_ARG_WIDTH, 20, 0);
	snakeBody[length] = PtCreateWidget( PtRect, ABW_gBkgd, 4, argsSnake);
	PtRealizeWidget(snakeBody[length]);
	length++;
	
	//SnakeBody1
	PtSetArg(&argsSnake[0], Pt_ARG_FILL_COLOR, Pg_YELLOW, 0);
    PhPoint_t pos1 = {20, 153};
	PtSetArg(&argsSnake[1], Pt_ARG_POS, &pos1, 0);
	PtSetArg(&argsSnake[2], Pt_ARG_HEIGHT, 17, 0);
	PtSetArg(&argsSnake[3], Pt_ARG_WIDTH, 20, 0);
	snakeBody[length] = PtCreateWidget( PtRect, ABW_gBkgd, 4, argsSnake);
	PtRealizeWidget(snakeBody[length]);
	length++;
	
	//SnakeBody2
	PtSetArg(&argsSnake[0], Pt_ARG_FILL_COLOR, Pg_YELLOW, 0);
    PhPoint_t pos2 = {20, 170};
	PtSetArg(&argsSnake[1], Pt_ARG_POS, &pos2, 0);
	PtSetArg(&argsSnake[2], Pt_ARG_HEIGHT, 17, 0);
	PtSetArg(&argsSnake[3], Pt_ARG_WIDTH, 20, 0);
	snakeBody[length] = PtCreateWidget( PtRect, ABW_gBkgd, 4, argsSnake);
	PtRealizeWidget(snakeBody[length]);
	length++;
		
	
	moveFood();
	
	return( Pt_CONTINUE );

	}

	
#/** PhEDIT attribute block
#-11:16777215
#0:424:default:-3:-3:0
#424:425:TextFont9a:-3:-3:0
#425:3775:default:-3:-3:0
#3775:3776:default:-3:-3:1
#3776:3807:default:-3:-3:0
#**  PhEDIT attribute block ends (-0000220)**/
