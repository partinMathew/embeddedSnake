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
extern int moveX[10000];
extern int moveY[10000];
extern int yAxis[16];
extern int xAxis[15];
extern int tempCurD;

int
Left_Right( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )

	{
	if (cbinfo->reason_subtype == UPDOWN_LEFT){
	
		if (curD != 2 && tempCurD != 2){
			tempCurD = 4;
		}
	
	}
		else if(cbinfo->reason_subtype == UPDOWN_RIGHT)
		{
		if (curD != 4 && tempCurD != 4){
			tempCurD = 2;
		}
		
		}
		
	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );

	}

