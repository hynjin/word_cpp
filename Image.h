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
	
	void MainDraw(HDC hdc); //메인 화면 그리기
	void DayDraw(HDC hdc); //날짜 화면 그리기
	void WordDraw(HDC hdc,HWND hWnd); //단어장 화면 그리기
	void GameDraw(HWND hWndMain,HBITMAP& hBit); //게임 화면 그리기
	void GameEndDraw(HDC hdc,int i); //게임 종료 화면 그리기

	void SetEnterWord(LPWSTR str);//단어를 받아옴
	void SetDay(int i); //읽어올 단어장 날짜를 세팅

	int GetGameState(); //게임 상태 확인

	void callBackground(HDC hdc); //배경 화면 불러옴
	
	//각 버튼 이미지를 읽어옴(Button.h에서 사용)
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

	int getVocaNumber(); //단어 읽어옴
	
private:
	int gameState; //게임 상태
	Game game; //게임 클래스 변수

	CString enterWord; //입력받은 단어

	CImage home_b[2]; //홈 이동 버튼
	CImage day[2][7]; //날짜 버튼
	CImage change_b[2]; //모드 전환 버튼
	CImage enter_b[2]; //확인 버튼
	CImage goGame_b[2]; //게임이동 버튼
	CImage goMain_b[2]; //메인이동 버튼
	CImage goWord_b[2]; //단어이동 버튼
	CImage back_b[2]; //뒤로가기 버튼
	CImage logo; //프로그램 로고
	CImage background; //게임 배경
	CImage card; //단어장 카드 모양
	CImage scrollcard; //스크롤 모드 카드
	CImage ccat[4]; //고양이 이미지
	CImage cat;
	CImage *slime; //슬라임 갯수 미정
	CImage cslime[3][9]; //슬라임 3가지
	CImage fish[4]; //물고기 아이템
	CImage bomb[4]; //폭탄 아이템
	CImage time[4]; //시계 아이템
	CImage dish[6]; //접시
	CImage choose; //선택 로고
	CImage game_s[2]; //게임클리어, 게임오버 배경
	CImage clear[4]; //게임 클리어 로고(all,stage1,2,3)
	CImage over; //게임오버 로고
	CImage movMain_b;
	CImage nextStage_b[2]; //다음 단계 이동 버튼
	CImage replay_b[2]; //게임 재실행 버튼
	CImage prev_b; //단어 이전이동 버튼
	CImage next_b; //단어 다음이동 버튼

	CImage enter_bp; // 버튼 깜빡임을 방지하기 위한 이미지
	CImage home_bp;  // 버튼 깜빡임을 방지하기 위한 이미지

	HFONT font, oldfont;//Ahn 

};