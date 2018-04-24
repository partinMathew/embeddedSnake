/* Import (extern) header for application - AppBuilder 2.03  */

#include "abdefine.h"

extern ApWindowLink_t base;
extern ApWidget_t AbWidgets[ 11 ];


#ifdef __cplusplus
extern "C" {
#endif
int Up_Down( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int Left_Right( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int StartUp( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int NewGamePressed( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int SnakeActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
int FoodActivate( PtWidget_t *widget, ApInfo_t *data, PtCallbackInfo_t *cbinfo );
#ifdef __cplusplus
}
#endif
