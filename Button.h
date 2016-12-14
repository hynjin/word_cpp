#include <windows.h>
#include <atlimage.h>
#include "Image.h"
#include "Define.h"

class Button
{
public:
	Button(HWND hWnd, HINSTANCE g_hInst) //버튼 생성 & 버튼 이미지 씌움
	{
		main_b = CreateWindow(TEXT("button"),TEXT("MAIN"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,10,10,54,54,hWnd,(HMENU)MAIN,g_hInst,NULL);//메인버튼
		SendMessage(main_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetMainB());
		voca_b = CreateWindow(TEXT("button"),TEXT("WORD"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,330,550,180,80,hWnd,(HMENU)VOCA,g_hInst,NULL);//단어장버튼
		SendMessage(voca_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetWordB());
		game_b = CreateWindow(TEXT("button"),TEXT("GAME"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,540,550,180,80,hWnd,(HMENU)GAME,g_hInst,NULL);//게임버튼
		SendMessage(game_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetGameB());
		back_b = CreateWindow(TEXT("button"),TEXT("BACK"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,74,10,54,54,hWnd,(HMENU)BACK,g_hInst,NULL);//뒤로버튼
		SendMessage(back_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetBackB());
		enter_b = CreateWindow(TEXT("button"),TEXT("ENTER"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,620,650,70,40,hWnd,(HMENU)ENTER,g_hInst,NULL);//확인버튼
		SendMessage(enter_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetEnterB());
		change_b = CreateWindow(TEXT("button"),TEXT("CHANGE"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,964,10,54,54,hWnd,(HMENU)CHANGE,g_hInst,NULL);//전환버튼
		SendMessage(change_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetChangeB());
		day_b[0] = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 180, 290, 110, 110, hWnd, (HMENU)DAY1_NUMBER, g_hInst, NULL);
		day_b[1] = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 360, 290, 110, 110, hWnd, (HMENU)DAY2_NUMBER, g_hInst, NULL);
		day_b[2] = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 540, 290, 110, 110, hWnd, (HMENU)DAY3_NUMBER, g_hInst, NULL);
		day_b[3] = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 720, 290, 110, 110, hWnd, (HMENU)DAY4_NUMBER, g_hInst, NULL);
		day_b[4] = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 280, 490, 110, 110, hWnd, (HMENU)DAY5_NUMBER, g_hInst, NULL);
		day_b[5] = CreateWindow(TEXT("button"), TEXT("6"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 460, 490, 110, 110, hWnd, (HMENU)DAY6_NUMBER, g_hInst, NULL);
		day_b[6] = CreateWindow(TEXT("button"), TEXT("7"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 640, 490, 110, 110, hWnd, (HMENU)DAY7_NUMBER, g_hInst, NULL);
		for(int i=0;i<7;i++)
			SendMessage(day_b[i], BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetDayB(i));
		prev_b = CreateWindow(TEXT("button"), TEXT("prev"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 88, 348, 62, 55, hWnd, (HMENU)PREV, g_hInst, NULL);
		SendMessage(prev_b, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)img.GetPrevB());
		next_b = CreateWindow(TEXT("button"), TEXT("next"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_BITMAP, 890, 348, 62, 55, hWnd, (HMENU)NEXT, g_hInst, NULL);
		SendMessage(next_b, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)img.GetNextB());
		goMain_b = CreateWindow(TEXT("button"),TEXT("MAIN"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,330,580,180,80,hWnd,(HMENU)MAIN,g_hInst,NULL);//메인버튼
		SendMessage(goMain_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetGoMainB());
		nextStage_b = CreateWindow(TEXT("button"),TEXT("NEXT"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,540,580,180,80,hWnd,(HMENU)NEXT_STAGE,g_hInst,NULL);//다음단계버튼
		SendMessage(nextStage_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetNextStageB());
		replay_b = CreateWindow(TEXT("button"),TEXT("REPLAY"),WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON |BS_BITMAP,540,580,180,80,hWnd,(HMENU)REPLAY,g_hInst,NULL);//재시작버튼
		SendMessage(replay_b, BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)img.GetReplayB());
	
		nextBool = true;
		prevBool = false;
	
	}

	int Show(int state) //상태에 맞는 버튼 띄움
	{
		switch(state)
		{
		case MAIN:	MainShow();	break;
		case DAY:	DayShow();	break;
		case VOCA:	VocaShow();	break;
		case GAME:	GameShow();	break;
		case GAME_CLEAR:
		case ALL_CLEAR:
		case GAME_OVER:
			GameEndShow(state);
			break;
		}
		return 0;
	}

	void MainShow() //메인 화면 버튼
	{
		ShowWindow(main_b,false);
		ShowWindow(voca_b,true);
		ShowWindow(game_b,true);
		ShowWindow(back_b,false);
		ShowWindow(enter_b,false);
		ShowWindow(change_b,false);
		ShowWindow(next_b, false);
		ShowWindow(prev_b, false);
		ShowWindow(goMain_b,false);
		ShowWindow(nextStage_b,false);
		ShowWindow(replay_b,false);
		for(int i=0;i<7;i++)
			ShowWindow(day_b[i],false);
	}
	void DayShow() //날짜 화면 버튼
	{
		ShowWindow(main_b,true);
		ShowWindow(voca_b,false);
		ShowWindow(game_b,false);
		ShowWindow(back_b,true);
		ShowWindow(enter_b,false);
		ShowWindow(change_b,false);
		ShowWindow(next_b, false);
		ShowWindow(prev_b, false);
		ShowWindow(goMain_b,false);
		ShowWindow(nextStage_b,false);
		ShowWindow(replay_b,false);
		for(int i=0;i<7;i++)
			ShowWindow(day_b[i],true);
	}
	void VocaShow() //단어장 화면 버튼
	{
		ShowWindow(main_b,true);
		ShowWindow(voca_b,false);
		ShowWindow(game_b,false);
		ShowWindow(back_b,true);
		ShowWindow(enter_b,false);
		ShowWindow(change_b,true);
		ShowWindow(next_b, nextBool);
		ShowWindow(prev_b, prevBool);
		ShowWindow(goMain_b,false);
		ShowWindow(nextStage_b,false);
		ShowWindow(replay_b,false);
		for(int i=0;i<7;i++)
			ShowWindow(day_b[i],false);
	}
	void GameShow() //게임 화면 버튼
	{
		ShowWindow(main_b,true);
		ShowWindow(voca_b,false);
		ShowWindow(game_b,false);
		ShowWindow(back_b,false);
		ShowWindow(enter_b,true);
		ShowWindow(change_b,false);
		ShowWindow(next_b, false);
		ShowWindow(prev_b, false);
		ShowWindow(goMain_b,false);
		ShowWindow(nextStage_b,false);
		ShowWindow(replay_b,false);
		for(int i=0;i<7;i++)
			ShowWindow(day_b[i],false);
	}
	void GameEndShow(int i) //게임 종료 화면 버튼
	{
		ShowWindow(main_b,false);
		ShowWindow(voca_b,false);
		ShowWindow(game_b,false);
		ShowWindow(back_b,false);
		ShowWindow(enter_b,false);
		ShowWindow(change_b,false);
		ShowWindow(next_b, false);
		ShowWindow(prev_b, false);
		ShowWindow(goMain_b,true);
		if(i == GAME_CLEAR)
		{	
			ShowWindow(nextStage_b,true);
			ShowWindow(replay_b,false);
		}
		else if (i == GAME_OVER || i == ALL_CLEAR)
		{
			ShowWindow(nextStage_b,false);
			ShowWindow(replay_b,true);
		}
		for(int i=0;i<7;i++)
			ShowWindow(day_b[i],false);

	}

	void arrowConditon(int vocaNumber, int mode){ //단어장 화살표 버튼 상태
		if (!mode){
			prevBool = nextBool = true;
			if (vocaNumber>28) nextBool = false;
			else if (vocaNumber == 28)nextBool = true;
			else if (vocaNumber == 1)  prevBool = true;
			else if (vocaNumber < 1)prevBool = false;
		}
		else{
			nextBool = false;
			prevBool = false;
		}
	}


private:
	Image img; //버튼에 씌울 이미지
	
	HWND main_b, voca_b,game_b,back_b,enter_b,change_b,day_b[7],next_b,prev_b,goMain_b,nextStage_b,replay_b; //버튼

	bool nextBool, prevBool; //단어장 화살표 상태
};