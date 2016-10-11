#include "Dxlib.h"
#include "Main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow){
	SetGraphMode( _SCREEN_SIZE_X, _SCREEN_SIZE_Y, 16);
	ChangeWindowMode( TRUE );	//ウインドウモードで起動
	if(DxLib_Init() == -1){// DXライブラリ初期化処理
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK); //描画先画面をリセット
	SetBackgroundColor(0,0,40); //背景食を設定	

	//Game_Transition.Change_Flag( FLAG_GAME_MAIN );
	Game_Transition.Initialization();

	while( ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();		//画面Clear

		Game_Transition.Transition();

		if(CheckHitKey(KEY_INPUT_LEFT) == 1) Game_Transition.Change_Flag( FLAG_GAME_MAIN );
		else if( CheckHitKey(KEY_INPUT_RIGHT) == 1 )Game_Transition.Change_Flag( FLAG_TITLE );
		else if(CheckHitKey(KEY_INPUT_UP) == 1 )Game_Transition.Change_Flag( FLAG_HELP );
		else if(CheckHitKey(KEY_INPUT_DOWN) == 1 )Game_Transition.Change_Flag( FLAG_OPTION );

		ScreenFlip();		//画面フリップ
	}

	DxLib_End();	//DXライブラリ使用終了処理

	return 0; //ソフト終了
}
