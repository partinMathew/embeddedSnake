/* Y o u r   D e s c r i p t i o n                       */
/*                            AppBuilder Photon Code Lib */
/*                                         Version 2.03  */

/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

/* Local headers */
#include "ablibs.h"
#include "abimport.h"
#include "proto.h"
#include "globals.h"

extern int yPos;
extern int xPos;
extern int curD;
extern int foodX;
extern int foodY;
extern int counter;
extern int moveX[10000];
extern int moveY[10000];
extern int yAxis[16];
extern int xAxis[15];
extern int level;
extern int score;


int
FoodActivate( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{
	score = floor(score *.9);
	PtArg_t 	args[4];
	char buffer[50];
	char str[20] = "Score: ";
	char * scoreLabel = strcat(str, itoa(score,buffer,10) );
	PtSetArg(&args[0],Pt_ARG_TEXT_STRING,scoreLabel, 0);
	PtSetResources(ABW_ScoreText, 1, args);
	//do{
		moveFood();
//	}while(foodX != moveX[counter] && foodY != moveY[counter]);
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );

	}

