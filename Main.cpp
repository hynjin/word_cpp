#include <windows.h>
#include <atlimage.h>
#include "Button.h"
#include "Voca.h"
#include "Define.h"

#pragma comment(lib, "msimg32.lib") 
#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")//�ܼ�â�� ���� �ֵ���

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
	static HWND hEdit; //���ڿ� �Է� ���� ����Ʈ
	PAINTSTRUCT ps;
	static Image img;
	static int day,back;//���α׷� ����static int vocaDay;//�ܾ��� ��¥
	static int vocaDay;//�ܾ��� ��¥

	CString str;
	string stringEnter;

	RECT vocaRect = { 200, 180, 840, 530 };//AHN
	RECT fullRect = { 0, 0, 1040, 750 };//AHN
	char enterVoca[128]; //�Է¹��� �ܾ�

	RECT crt;//double Buffer
	HDC hMemDC;
	HBITMAP OldBit;

	switch(iMessage) {
	case WM_CREATE: //������
		state = MAIN;//�ʱ� ���´� ����
		back = MAIN; //�ڷ� �����ϸ� ��������
		hEdit = CreateWindow(TEXT("edit"),NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,350,650,250,40,hWnd,(HMENU)EDIT,g_hInst,NULL); //����Ʈ �ڽ�

		scroll = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | SBS_VERT, 840, 180, 20, 350, hWnd, (HMENU)100, g_hInst, NULL); //��ũ��
		SetScrollRange(scroll, SB_CTL, 0, 1000, TRUE);
		SetScrollPos(scroll, SB_CTL, 0, TRUE);
	
		return 0;

	case  WM_LBUTTONUP: //������ ��ư ������ ���
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


	case WM_COMMAND://��ư�� ������ ���
		 //ȭ����ȯ�� ���� �ʱ�ȭ 
		if(state!=GAME)InvalidateRect(hWnd, NULL, TRUE);
		switch(LOWORD(wParam))
		{
		case MAIN: //���� ��ư�� ������ ���
			InvalidateRect(hWnd, NULL, TRUE);
			state = MAIN; //���¸� ��¥ �������� �ٲ�
			KillTimer(hWnd,1);
			break;
		case VOCA://�ܾ��� ��ư�� ������ ���
			day = VOCA;
			state = DAY; //���¸� ��¥ ������ �ٲ�
			break;
		case GAME: //���� ��ư�� ������ ���
			day = GAME;
			state += DAY; //���¸� ��¥ �������� �ٲ�
			break;
		case BACK: //�ڷ� ���� ��ư�� ������ ���
			if (state == VOCA)ShowWindow(scroll, false);
			state = back;
			break;
		case CHANGE: //�ܾ��� ��ȯ ��ư�� ������ ���
			voca.changeMode();
			button->arrowConditon(voca.getVocaNumber(), voca.getVocaMode());
			break;
		case NEXT: //�ܾ��� ���� ȭ��ǥ�� ������ ���
			voca.next();
			button->arrowConditon(voca.getVocaNumber(), voca.getVocaMode());
			break;
		case PREV: //�ܾ��� ���� ȭ��ǥ�� ������ ���
			voca.prev();
			button->arrowConditon(voca.getVocaNumber(), voca.getVocaMode());
			break;
		case ENTER: //���� Ȯ�� ��ư�� ������ ���
			GetWindowText(hEdit, (LPTSTR)enterVoca, WM_GETTEXTLENGTH);
			img.SetEnterWord((LPWSTR)enterVoca);
			SetDlgItemText(hWnd, EDIT, _T(""));
			break;
		case NEXT_STAGE: //���� ���� ���� �ܰ� ��ư�� ������ ���
		case REPLAY: //���� ���� �ٽ��ϱ⸦ ������ ���
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
	case WM_PAINT: //ȭ�� �׸���
		hdc = BeginPaint(hWnd, &ps);
		switch (state)
		{
		case MAIN: //���� ȭ��
			ShowWindow(hEdit, false);
			ShowWindow(scroll, false);
			img.MainDraw(hdc);
			break;
		case DAY: //��¥ ���� ȭ��
			back = MAIN;
			ShowWindow(hEdit, false);
			ShowWindow(scroll, false);
			img.DayDraw(hdc);
			break;
		case VOCA: //�ܾ��� ȭ��
			back = DAY;
			ShowWindow(hEdit, false);
			img.WordDraw(hdc, scroll);
			break;
		case GAME://���� ȭ��
			ShowWindow(hEdit, true);
			GetClientRect(hWnd, &crt);//double buffer
			hMemDC = CreateCompatibleDC(hdc);
			OldBit = (HBITMAP)SelectObject(hMemDC, hBit);//double buffer
			BitBlt(hdc, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY);

			if (GetAsyncKeyState(VK_RETURN) & 0x0001)//���� �Է����� ���
				enterFlag = true;
			
			if (timerFlag){
			state = img.GetGameState();
			timerFlag = false;
			}

			SelectObject(hMemDC, OldBit);//doubleBuffer
			DeleteDC(hMemDC);

			break;
		case GAME_CLEAR: //���� Ŭ���� ȭ��
		case ALL_CLEAR: //��ü ���� Ŭ���� ȭ��
		case GAME_OVER: //���� ���� ȭ��
			ShowWindow(hEdit,false);
			SetTimer(hWnd,1,1,NULL);
			img.GameEndDraw(hdc,state);
			KillTimer(hWnd,1);
			break;
		}
		
		EndPaint(hWnd, &ps);
		return 0;
	case WM_TIMER: //Ÿ�̸� �۵�
		
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
	case WM_DESTROY: //���α׷� ����
		KillTimer(hWnd,1);
		PostQuitMessage(0);
		if (hBit) {
			DeleteObject(hBit);
		}
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}