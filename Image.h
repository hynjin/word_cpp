#include <atlimage.h>
#include <iostream>
#include <string>
#include "Game.h"
#include "Define.h"
using namespace std;


class Image
{
public:
	Image();
	~Image();
	
	void MainDraw(HDC hdc); //���� ȭ�� �׸���
	void DayDraw(HDC hdc); //��¥ ȭ�� �׸���
	void WordDraw(HDC hdc,HWND hWnd); //�ܾ��� ȭ�� �׸���
	void GameDraw(HWND hWndMain,HBITMAP& hBit); //���� ȭ�� �׸���
	void GameEndDraw(HDC hdc,int i); //���� ���� ȭ�� �׸���

	void SetEnterWord(LPWSTR str);//�ܾ �޾ƿ�
	void SetDay(int i); //�о�� �ܾ��� ��¥�� ����

	int GetGameState(); //���� ���� Ȯ��

	void callBackground(HDC hdc); //��� ȭ�� �ҷ���
	
	//�� ��ư �̹����� �о��(Button.h���� ���)
	HBITMAP GetMainB();
	HBITMAP GetWordB();
	HBITMAP GetGameB();
	HBITMAP GetBackB();
	HBITMAP GetEnterB();
	HBITMAP GetChangeB();
	HBITMAP GetDayB(int day);
	HBITMAP GetNextB();
	HBITMAP GetPrevB();
	HBITMAP GetGoMainB();
	HBITMAP GetNextStageB();
	HBITMAP GetReplayB();

	int getVocaNumber(); //�ܾ� �о��
	
private:
	int gameState; //���� ����
	Game game; //���� Ŭ���� ����

	CString enterWord; //�Է¹��� �ܾ�

	CImage home_b[2]; //Ȩ �̵� ��ư
	CImage day[2][7]; //��¥ ��ư
	CImage change_b[2]; //��� ��ȯ ��ư
	CImage enter_b[2]; //Ȯ�� ��ư
	CImage goGame_b[2]; //�����̵� ��ư
	CImage goMain_b[2]; //�����̵� ��ư
	CImage goWord_b[2]; //�ܾ��̵� ��ư
	CImage back_b[2]; //�ڷΰ��� ��ư
	CImage logo; //���α׷� �ΰ�
	CImage background; //���� ���
	CImage card; //�ܾ��� ī�� ���
	CImage scrollcard; //��ũ�� ��� ī��
	CImage ccat[4]; //����� �̹���
	CImage cat;
	CImage *slime; //������ ���� ����
	CImage cslime[3][9]; //������ 3����
	CImage fish[4]; //����� ������
	CImage bomb[4]; //��ź ������
	CImage time[4]; //�ð� ������
	CImage dish[6]; //����
	CImage choose; //���� �ΰ�
	CImage game_s[2]; //����Ŭ����, ���ӿ��� ���
	CImage clear[4]; //���� Ŭ���� �ΰ�(all,stage1,2,3)
	CImage over; //���ӿ��� �ΰ�
	CImage movMain_b;
	CImage nextStage_b[2]; //���� �ܰ� �̵� ��ư
	CImage replay_b[2]; //���� ����� ��ư
	CImage prev_b; //�ܾ� �����̵� ��ư
	CImage next_b; //�ܾ� �����̵� ��ư

	CImage enter_bp; // ��ư �������� �����ϱ� ���� �̹���
	CImage home_bp;  // ��ư �������� �����ϱ� ���� �̹���

	HFONT font, oldfont;//Ahn 

};