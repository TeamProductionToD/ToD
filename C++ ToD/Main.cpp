#include "Main.h"
#include "DxLib.h"

GAME_TRANSITION Game_Transition;

bool GAME_TRANSITION::Change_Flag( int BitFlag ){
	Flag |= TRUE << BitFlag; //ビットフラグを立てる
	Flag &= TRUE << BitFlag; //立てたビット以外のフラグを折る

	return (Flag & TRUE << BitFlag) != 0 ? true : false;
}

void GAME_TRANSITION::Transition(){
	switch (Flag)
	{
		case BIT_FLAG_TITLE:
			DrawString(10,10,"Title", 0x0000ff, 0xff0000);
			DrawBox( 400, 120, 800, 240, 0xff0000, false);
			DrawBox( 500, 420, 700, 460, 0x00ff00, false);
			break;
		case BIT_FLAG_GAME_MAIN:
			DrawString(10,10,"GameMain", 0x0000ff, 0xff0000);
			DrawBox( 400, 120, 800, 240, 0x0000ff, false);
			break;
		case BIT_FLAG_HELP:
			DrawString(10,10,"Help", 0x0000ff, 0xff0000);
			break;
		case BIT_FLAG_OPTION:
			DrawString(10,10,"Option", 0x0000ff, 0xff0000);
			break;
	}
}

void GAME_TRANSITION::Initialization(){
	ImageLoad();
}

void GAME_TRANSITION::ImageLoad(){
	MenuImage[0] = LoadGraph("Image\\StartButton.png");
	MenuImage[1] = LoadGraph("Image\\HelpButton.png");
	MenuImage[2] = LoadGraph("Image\\OptionButton.png");
}