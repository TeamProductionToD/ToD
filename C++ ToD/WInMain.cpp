#include "Dxlib.h"
#include "Main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow){
	SetGraphMode( _SCREEN_SIZE_X, _SCREEN_SIZE_Y, 16);
	ChangeWindowMode( TRUE );	//�E�C���h�E���[�h�ŋN��
	if(DxLib_Init() == -1){// DX���C�u��������������
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK); //�`����ʂ����Z�b�g
	SetBackgroundColor(0,0,40); //�w�i�H��ݒ�	

	//Game_Transition.Change_Flag( FLAG_GAME_MAIN );
	Game_Transition.Initialization();

	while( ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();		//���Clear

		Game_Transition.Transition();

		if(CheckHitKey(KEY_INPUT_LEFT) == 1) Game_Transition.Change_Flag( FLAG_GAME_MAIN );
		else if( CheckHitKey(KEY_INPUT_RIGHT) == 1 )Game_Transition.Change_Flag( FLAG_TITLE );
		else if(CheckHitKey(KEY_INPUT_UP) == 1 )Game_Transition.Change_Flag( FLAG_HELP );
		else if(CheckHitKey(KEY_INPUT_DOWN) == 1 )Game_Transition.Change_Flag( FLAG_OPTION );

		ScreenFlip();		//��ʃt���b�v
	}

	DxLib_End();	//DX���C�u�����g�p�I������

	return 0; //�\�t�g�I��
}
