#pragma once
#include"Icons.h"

class Icon_NextBlack : public Icons
{
public:
	void Initialize()
	{

		string pic_temp[8] = {
			"  �Z�d�e�d�b  ��    ",
			"  �����i�i�i�g���@  ",
			"�����o�i�~���i�o����",
			"  �l�l�o �� �k���k��",
			"  �l�m�o�����k�g��  ",
			"  �p�p�c�g�g���l    ",
			"      ���i�i��      ",
			"        �f�f        "
		};
		unsigned short background_color_temp[8][20] =
		{
			{ BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY },
			{ BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_BLACK,BG_BLACK,BG_BLUE,BG_BLUE,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY },
			{ BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_BLUE,BG_BLUE,BG_LIGHTGREY,BG_LIGHTGREY,BG_BLUE,BG_BLUE,BG_BLUE,BG_BLUE,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY ,BG_LIGHTGREY },
			{ BG_LIGHTGREY,BG_LIGHTGREY, BG_LIGHTGREY ,BG_LIGHTGREY ,BG_BLUE ,BG_BLUE ,BG_WHITE ,BG_WHITE ,	BG_BLUE ,BG_BLUE ,BG_BLUE ,BG_BLUE ,BG_BLUE ,BG_BLUE ,BG_BLUE ,BG_BLUE ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY },
			{ BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_BLUE ,BG_BLUE ,BG_WHITE ,BG_WHITE ,BG_LIGHTBLUE ,BG_LIGHTBLUE,BG_LIGHTBLUE ,BG_LIGHTBLUE ,BG_LIGHTBLUE ,BG_LIGHTBLUE ,BG_LIGHTBLUE ,BG_LIGHTBLUE ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY },
			{ BG_LIGHTGREY,BG_LIGHTGREY,BG_BLACK,BG_BLACK,BG_LIGHTBLUE,BG_LIGHTBLUE,BG_LIGHTBLUE,BG_LIGHTBLUE,BG_WHITE,BG_WHITE,BG_WHITE ,BG_WHITE ,BG_BLUE ,BG_BLUE ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY },	
			{ BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTBLUE,BG_LIGHTBLUE,		BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,	BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY },
			{ BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTBLUE,BG_LIGHTBLUE,BG_LIGHTBLUE,BG_LIGHTBLUE,BG_LIGHTGREY,BG_LIGHTGREY,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY ,BG_LIGHTGREY }
		};
		





		unsigned short word_color_temp[8][20] =
		{
			{ WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK,WORD_BLACK },
			{ WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,	WORD_BLUE ,WORD_BLUE ,WORD_BLUE ,WORD_BLUE ,WORD_BLUE ,WORD_BLUE ,	WORD_BLUE ,WORD_BLUE ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK },
			{ WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,	WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_BLUE ,WORD_BLUE ,	WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_BLUE ,WORD_BLUE ,WORD_BLUE ,WORD_BLUE ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK },
			{ WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_BLACK ,WORD_BLACK ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_BLUE ,WORD_BLUE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,	WORD_WHITE ,WORD_WHITE ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK },
			{ WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,	WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,	WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_WHITE ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK ,WORD_BLACK },
			{ WORD_BLACK ,WORD_BLACK ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,		WORD_WHITE ,WORD_WHITE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,		WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY },
			{ WORD_LIGHTGREY ,WORD_LIGHTGREY,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,	WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,WORD_LIGHTBLUE ,			WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY },
			
			{ WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY,WORD_LIGHTGREY,WORD_LIGHTGREY,WORD_LIGHTGREY,WORD_LIGHTGREY,		WORD_LIGHTGREY,WORD_LIGHTGREY,WORD_LIGHTGREY,WORD_LIGHTGREY,
			WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY ,WORD_LIGHTGREY }
		};


	


		for (int i = 0; i < 8; i++)
		{
			pic[i] = pic_temp[i];
			for (int j = 0; j < 20; j++)
			{
				background_color[i][j] = background_color_temp[i][j];
				word_color[i][j] = word_color_temp[i][j];
			}

		}
	}
	Icon_NextBlack()
	{
		Initialize();
	}

};