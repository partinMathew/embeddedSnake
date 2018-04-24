/* Define header for application - AppBuilder 2.03  */

/* 'base' Window link */
extern const int ABN_base;
#define ABW_base                             AbGetABW( ABN_base )
extern const int ABN_gBkgd;
#define ABW_gBkgd                            AbGetABW( ABN_gBkgd )
extern const int ABN_SnakeFood;
#define ABW_SnakeFood                        AbGetABW( ABN_SnakeFood )
extern const int ABN_SnakeTimer;
#define ABW_SnakeTimer                       AbGetABW( ABN_SnakeTimer )
extern const int ABN_FoodTimer;
#define ABW_FoodTimer                        AbGetABW( ABN_FoodTimer )
extern const int ABN_gameOver;
#define ABW_gameOver                         AbGetABW( ABN_gameOver )
extern const int ABN_PtNewGameButton;
#define ABW_PtNewGameButton                  AbGetABW( ABN_PtNewGameButton )
extern const int ABN_LevelText;
#define ABW_LevelText                        AbGetABW( ABN_LevelText )
extern const int ABN_ScoreText;
#define ABW_ScoreText                        AbGetABW( ABN_ScoreText )
extern const int ABN_PtLeft_Right;
#define ABW_PtLeft_Right                     AbGetABW( ABN_PtLeft_Right )
extern const int ABN_PtUp_Down;
#define ABW_PtUp_Down                        AbGetABW( ABN_PtUp_Down )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"
