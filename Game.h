#include <iostream>
#include <string>
#include <atlstr.h>
#include "Object.h"
#include "Define.h"

using namespace std;

class Game
{
public:
	Game();
	//~Game();

	void Init(int i); //초기화
	
	int GetSlimeX(int i); //슬라임의 x좌표
	int GetSlimeY(int i); //슬라임의 y좌표
	int GetSlimeColor(int i); //슬라임의 색상
	int GetSlimeNum(); //총 몇마리의 슬라임이 등장할 수 있는지
	int GetSlimeWord(int i); //슬라임이 가진 단어가 단어장에서 몇번째 단어인지
	int GetSlimeLanguage(int i); //슬라임이 가진 단어의 언어
	void SetSlimeDie(int i); //슬라임 죽음

	int GetBombX(); //폭탄의 x좌표
	int GetBombY(); //폭탄의 y좌표
	int GetBombWord(); //폭탄이 가진 단어가 단어장에서 몇번째 단어인지
	int GetBombLanguage(); //폭탄이 가진 단어의 언어
	void SetBombDie(); //폭탄 죽음
	
	int GetFishX(); //물고기의 x좌표
	int GetFishY(); //물고기의 y좌표
	int GetFishWord(); //물고기가 가진 단어가 단어장에서 몇번째 단어인지
	int GetFishLanguage(); //물고기가 가진 단어의 언어
	void SetFishDie(); //물고기 죽음

	int GetTimeX(); //시계의 x좌표
	int GetTimeY(); //시계의 y좌표
	int GetTimeWord(); //시계가 가진 단어가 단어장에서 몇번째 단어인지
	int GetTimeLanguage(); //시계가 가진 단어의 언어
	void SetTimeDie(); //시계 죽음
	
	int GetStage(); //게임 스테이지
	int GetLife(); //목숨이 얼마나 남았는지
	bool isDie(); //객체가 죽었나 확인
	int CheckGame(); //게임이 끝났나 확인
	void CheckState(); //객체가 화면 밖으로 나가거나 죽으면 초기화

private:
	int stage, dieSlime, slimeNum,life;

	string enterWord;

	Object *slime; //슬라임 객체(동적할당)
	Object *pSlime; //슬라임 해제 할때 사용할 포인터
	Object *bomb_i; //폭탄 아이템 객체
	Object *fish_i; //물고기 아이템객체
	Object *time_i; //시간 아이템 객체
};