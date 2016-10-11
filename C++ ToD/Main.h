#ifndef __MAIN_H__
#define __MAIN_H__

#define _SCREEN_SIZE_X 1200
#define _SCREEN_SIZE_Y 600
#define _MENU_IMAGE_NUM 3

#define BIT_FLAG_TITLE		(1 << 0) // 2�i�� : (0000 0000 0000 0001)
#define BIT_FLAG_GAME_MAIN  (1 << 1) // 2�i�� : (0000 0000 0000 0010)
#define BIT_FLAG_HELP		(1 << 2) // 2�i�� : (0000 0000 0000 0100)
#define BIT_FLAG_OPTION		(1 << 3) // 2�i�� : (0000 0000 0000 1000)
//#define BIT_FLAG_E (1 << 4) // 2�i�� : (0000 0000 0001 0000)
//#define BIT_FLAG_F (1 << 5) // 2�i�� : (0000 0000 0010 0000)
//#define BIT_FLAG_G (1 << 6) // 2�i�� : (0000 0000 0100 0000)
//#define BIT_FLAG_H (1 << 7) // 2�i�� : (0000 0000 1000 0000)

enum BIT_FLAG{
	FLAG_TITLE = 0,
	FLAG_GAME_MAIN,
	FLAG_HELP,
	FLAG_OPTION
};

class GAME_TRANSITION { //�Q�[���J��
private:
	char Flag; //
	int MenuImage[_MENU_IMAGE_NUM];

public:
	GAME_TRANSITION() { Flag = BIT_FLAG_TITLE; }
	void Initialization();
	void Update();
	void Drawing();
	bool Change_Flag( int BitFlag ); //�V�[���ؑ֗p�BBitFlag�񋓑̂������ɓ����
	void Transition(); //

	void ImageLoad();
};

extern GAME_TRANSITION Game_Transition;

#endif //