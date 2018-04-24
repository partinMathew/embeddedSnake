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
extern int level;
extern int score;

int
SnakeActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo ){
curD = tempCurD;
	score += level * 10;
	moveX[counter] = xPos;	// Save Heads Xposition into the Array for future body Parts
	moveY[counter] = yPos;  // Save Heads Yposition into the Array for future body Parts
	headX = xPos;
	headY = yPos;
	counter++;
	PtArg_t 	args[4];
	char buffer[50];
	char str[20] = "Score: ";
	char * scoreLabel = strcat(str, itoa(score,buffer,10) );
	PtSetArg(&args[0],Pt_ARG_TEXT_STRING,scoreLabel, 0);
	PtSetResources(ABW_ScoreText, 1, args);
	
	// Moves Snake Up one Space
	if (curD == 1){
		 if (curD == 1 && yPos == 0){
				clearAll();
		 }
		
		if (yPos > 0  && curD != 3){ // Cannot Go down if currently going up
				yPos--;
			}
	}
	if (curD == 2){
		if (curD == 2 && xPos == 14){
			clearAll();
	
		}
		if(xPos < 14 && curD != 4){		
				xPos++;	
			}
	}
	if (curD == 3){
		 if (curD == 3 && yPos == 15){
				clearAll();
		 }
		
	   	if(yPos < 15 && curD != 1){
				yPos++;
			}
	}
	if (curD == 4){
		 if (curD == 4 && xPos == 0){
				clearAll();
		 }
	
		  if (xPos > 0 && curD != 2){				
				xPos--;
			}		
	}
		
	PhPoint_t pos = {xAxis[xPos], yAxis[yPos]};
	PtSetArg(&args[0], Pt_ARG_POS, &pos, 0);
	PtSetResources(snakeBody[0], 1, args);
	
	// Moves the snake body based off the movements of the head
	int i;
	PtArg_t 	argsSnake[4];
	for (i = 1; i < length; i++){
		PhPoint_t pos1 = {xAxis[moveX[counter-i]], yAxis[moveY[counter-i]]}; // Reads 'Length' number of indexes back in the array tracking the head movements
		PtSetArg(&argsSnake[0], Pt_ARG_POS, &pos1, 0);
		PtSetResources(snakeBody[i], 1, argsSnake);	// Loops through each snake body and moves it
	}
	grow();	// Grows Snake when conditions are met
	
	
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );

}
