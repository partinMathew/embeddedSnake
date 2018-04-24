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
#include "abdefine.h"

extern int yPos;
extern int xPos;
extern int counter;
extern int yAxis[16]; 
extern int	xAxis[15]; 


int
StartUp( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{
	yAxis[0] = 0;
	yAxis[1] = 17;
	yAxis[2] = 34;
	yAxis[3] = 51;
	yAxis[4] = 68;
	yAxis[5] = 85;
	yAxis[6] = 102;
	yAxis[7] = 119;
	yAxis[8] = 136;
	yAxis[9] = 153;
	yAxis[10] = 170;
	yAxis[11] = 187;
	yAxis[12] = 204;
	yAxis[13] = 221;
	yAxis[14] = 238;
	yAxis[15] = 255;
	xAxis[0] = 0;
	xAxis[1] = 20;
	xAxis[2] = 40;
	xAxis[3] = 60;
	xAxis[4] = 80;
	xAxis[5] = 100;
	xAxis[6] = 120;
	xAxis[7] = 140;
	xAxis[8] = 160;
	xAxis[9] = 180;
	xAxis[10] = 200;
	xAxis[11] = 220;
	xAxis[12] = 240;
	xAxis[13] = 260;
	xAxis[14] = 280;
	PtUnrealizeWidget(ABW_SnakeFood);
	PtUnrealizeWidget(ABW_gameOver);
	counter = 0;
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;
 	
 	xPos = 1;
	yPos = 8;
	PtArg_t 	args[4];
	PhPoint_t pos = {20, 136};
	PtSetArg(&args[0], Pt_ARG_POS, &pos, 0);
	
	return( Pt_CONTINUE );

	}

