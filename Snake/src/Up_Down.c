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
#include "globals.h"

extern int yPos;
extern int xPos;
extern int curD;
extern int counter;
extern int moveX[10000];
extern int moveY[10000];
extern int yAxis[16];
extern int xAxis[15];
extern int tempCurD;
int 
Up_Down( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
	{


		if(cbinfo->reason_subtype == UPDOWN_TOP)
		{
			if (curD != 3 && tempCurD != 3){
				tempCurD = 1;
			}
			/* If the up arrow is pressed */
		
		}
		
     	else if(cbinfo->reason_subtype == UPDOWN_BOTTOM)
     	{
     		if (curD != 1 && tempCurD != 1){
				tempCurD = 3;
			}

		}

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );
}
 