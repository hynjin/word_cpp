#include <windows.h>
#include <atlimage.h>
#include "Button.h"
#include "Voca.h"
#include "Define.h"

#pragma comment(lib, "msimg32.lib") 
#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")//콘솔창도 띄울수 있도록

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass="Program";
int state;
bool timerFlag;
bool enterFlag;
Button *button;

HWND scroll;

Voca &voca = *Voca::getVocaInstance();

HBITMAP hBit;//double buffer
HWND hWndMain;



int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=CreateSolidBrush(RGB(255,255,230));
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=TEXT("Program");
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(TEXT("Program"),TEXT("Program"),WS_OVERLAPPEDWINDOW,
		  CW_USEDEFAULT,CW_USEDEFAULT,WINSIZE_X,WINSIZE_Y,
		  NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	hWndMain = hWnd;

	Button bu(hWnd,g_hInst);
	button = &bu;

	while(GetMessage(&Message,0,0,0)) {
		bu.Show(state);
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	static HWND main,choose,game,word;
	static HWND hEdit; //문자열 입력 받을 에디트
	PAINTSTRUCT ps;
	static Image img;
	static int day,back;//프로그램 상태static int vocaDay;//단어의 날짜
	static int vocaDay;//단어의 날짜

	CString str;
	string stringEnter;

	RECT vocaRect = { 200, 180, 840, 530 };//AHN
	RECT fullRect = { 0, 0, 1040, 750 };//AHN
	char enterVoca[128]; //입력받은 단어

	RECT crt;//double Buffer
	HDC hMemDC;
	HBITMAP OldBit;

	switch(iMessage) {
	case WM_CREATE: //생성시
		state = MAIN;//초기 상태는 메인
		back = MAIN; //뒤로 가기하면 메인으로
		hEdit = CreateWindow(TEXT("edit"),NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,350,650,250,40,hWnd,(HMENU)EDIT,g_hInst,NULL); //에디트 박스

		scroll = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | SBS_VERT, 840, 180, 20, 350, hWnd, (HMENU)100, g_hInst, NULL); //스크롤
		SetScrollRange(scroll, SB_CTL, 0, 1000, TRUE);
		SetScrollPos(scroll, SB_CTL, 0, TRUE);
	
		return 0;

	case  WM_LBUTTONUP: //오른쪽 버튼 눌렀을 경우
		if (state == VOCA) voca.filp(LOWORD(lParam), HIWORD(lParam));
		RedrawWindow(hWnd, &vocaRect, NULL, RDW_INVALIDATE| RDW_UPDATENOW);
		break;

	case WM_VSCROLL:

		switch (LOWORD(wParam)) {
		case SB_LINEUP:
			voca.setScrollPos(max(0, voca.getScrollPos() - 50));
			break;
		case SB_LINEDOWN:
			voca.setScrollPos(min(1000, voca.getScrollPos() + 50));
			break;
		case SB_PAGEUP:
			voca.setScrollPos(max(0, voca.getScrollPos() - 100));
			break;
		case SB_PAGEDOWN:
			voca.setScrollPos(min(1000, voca.getScrollPos() + 100));
			break;
		case SB_THUMBTRACK:
			voca.setScrollPos(HIWORD(wParam));
			break;
		}

		SetScrollPos((HWND)lParam, SB_CTL, voca.getScrollPos(), TRUE);
		RedrawWindow(hWnd, &fullRect, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
		break;


	case WM_COMMAND://버튼을 눌렀을 경우
		 //화면전환을 위해 초기화 
		if(state!=GAME)InvalidateRect(hWnd, NULL, TRUE);
		switch(LOWORD(wParam))
		{
		case MAIN: //메인 버튼을 눌렀을 경우
			InvalidateRect(hWnd, NULL, TRUE);
			state = MAIN; //상태를 날짜 선택으로 바꿈
			KillTimer(hWnd,1);
			break;
		case VOCA://단어장 버튼을 눌렀을 경우
			day = VOCA;
			state = DAY; //상태를 날짜 선택을 바꿈
			break;
		case GAME: //게임 버튼을 눌렀을 경우
			day = GAME;
			state += DAY; //상태를 날짜 선택으로 바꿈
			break;
		case BACK: //뒤로 가기 버튼을 눌렀을 경우
			if (state == VOCA)ShowWindow(scroll, false);
			state = back;
			break;
		case CHANGE: //단어장 전환 버튼을 눌렀을 경우
			voca.changeMode();
			button->arrowConditon(voca.getVocaNumber(), voca.getVocaMode());
			break;
		case NEXT: //단어장 다음 화살표를 눌렀을 경우
			voca.next();
			button->arrowConditon(voca.getVocaNumber(), voca.getVocaMode());
			break;
		case PREV: //단어장 이전 화살표를 눌렀을 경우
			voca.prev();
			button->arrowConditon(voca.getVocaNumber(), voca.getVocaMode());
			break;
		case ENTER: //게임 확인 버튼을 눌렀을 경우
			GetWindowText(hEdit, (LPTSTR)enterVoca, WM_GETTEXTLENGTH);
			img.SetEnterWord((LPWSTR)enterVoca);
			SetDlgItemText(hWnd, EDIT, _T(""));
			break;
		case NEXT_STAGE: //게임 종료 다음 단게 버튼을 눌렀을 경우
		case REPLAY: //게임 종료 다시하기를 눌렀을 경우
			SetTimer(hWnd, 1, 100, NULL);
			state = GAME;
			break;
		default:
			vocaDay = LOWORD(wParam);

			if (20 < vocaDay && 28 > vocaDay)
			{
				SetScrollPos(scroll, SB_CTL, 0, TRUE);
				voca.init();
				voca.setVoca(vocaDay % 10);
				state = day;
				if (day == GAME)SetTimer(hWnd, 1, 100, NULL);
			}

			break;
		return 0;
		}
	case WM_PAINT: //화면 그리기
		hdc = BeginPaint(hWnd, &ps);
		switch (state)
		{
		case MAIN: //메인 화면
			ShowWindow(hEdit, false);
			ShowWindow(scroll, false);
			img.MainDraw(hdc);
			break;
		case DAY: //날짜 선택 화면
			back = MAIN;
			ShowWindow(hEdit, false);
			ShowWindow(scroll, false);
			img.DayDraw(hdc);
			break;
		case VOCA: //단어장 화면
			back = DAY;
			ShowWindow(hEdit, false);
			img.WordDraw(hdc, scroll);
			break;
		case GAME://게임 화면
			ShowWindow(hEdit, true);
			GetClientRect(hWnd, &crt);//double buffer
			hMemDC = CreateCompatibleDC(hdc);
			OldBit = (HBITMAP)SelectObject(hMemDC, hBit);//double buffer
			BitBlt(hdc, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY);

			if (GetAsyncKeyState(VK_RETURN) & 0x0001)//엔터 입력했을 경우
				enterFlag = true;
			
			if (timerFlag){
			state = img.GetGameState();
			timerFlag = false;
			}

			SelectObject(hMemDC, OldBit);//doubleBuffer
			DeleteDC(hMemDC);

			break;
		case GAME_CLEAR: //게임 클리어 화면
		case ALL_CLEAR: //전체 게임 클리어 화면
		case GAME_OVER: //게임 오버 화면
			ShowWindow(hEdit,false);
			SetTimer(hWnd,1,1,NULL);
			img.GameEndDraw(hdc,state);
			KillTimer(hWnd,1);
			break;
		}
		
		EndPaint(hWnd, &ps);
		return 0;
	case WM_TIMER: //타이머 작동
		
		timerFlag = true;
		img.GameDraw(hWndMain, hBit);
		
		if (enterFlag){
			GetWindowText(hEdit, (LPWSTR)enterVoca, 128);
			//cout << enterVoca << endl;
			stringEnter = voca.charToString(enterVoca);
			img.SetEnterWord((LPWSTR)enterVoca);
			SetDlgItemText(hWnd, EDIT, _T(""));
			enterFlag = false;
		}

		return 0;
	case WM_DESTROY: //프로그램 종료
		KillTimer(hWnd,1);
		PostQuitMessage(0);
		if (hBit) {
			DeleteObject(hBit);
		}
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}