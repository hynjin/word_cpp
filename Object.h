#include <cstdlib>
#include <time.h>
#include "Define.h"
using namespace std;

typedef struct object
{
	int x; //x좌표
	int y; //y좌표
	int mov; //이동거리
	int line; //몇번째 라인에 등장할지
	int show_time; //언제 등장할지
	int word_num; //몇개의 단어를 가질지
	int word_index; //어떤 단어를 가질지
	int language; //어느 언어로된 단어를 가질지
	int color; //슬라임 어떤 색 가질지
	bool die; //객체 생사여부
	bool over_line;//선 넘은 상태인지
}object;

class Object
{
public:
	Object()
	{
		srand((unsigned int)time(NULL)*rand()%10000); //랜덤
		obj.mov = rand()%4 + 1; //1~4 중에 랜덤으로 결정
		obj.line = rand()%4; //0~3 중에 랜덤
		obj.show_time = rand()%700 + 1500; //1500~1500+1000 중에 랜덤
		obj.word_num = rand()%2 +1; //1혹 2 랜덤
		obj.word_index = rand()%30; //0~29 중에 랜덤 //나중에 30으로 고쳐야함
		obj.language = rand()%2; //0 또는 1 랜덤
		obj.color = rand()%3; //0~2 중에 랜덤
		obj.x = obj.show_time; //윈도우 화면 밖에 객체가 위치
		obj.y = (140*obj.line)+40; //랜덤으로 라인에 위치
		obj.die = false; //생사
		obj.over_line = false; //선 넘어간 상태
	}
	//~Object();
	
	int GetObjX(){	return obj.x -= obj.mov;} //변하는 x좌표
	int GetObjY(){	return obj.y;} //고정된 y좌표
	int GetObjWordSize(){	return obj.word_num;} //단어갯수
	int GetObjWord(){		return obj.word_index;} //몇번째 단어
	int GetObjLanguage(){	return obj.language;} //한영
	int GetObjColor(){	return obj.color;} //슬라임 색상
	
	bool IsOut(){	return (obj.x < -350)?true:false;} //객체가 화면 밖으로 넘었는가
	bool IsIn(){	return (obj.x < WINSIZE_X)?true:false;}; //객체가 화면 안에 있는가
	bool IsOverLine(){	return (obj.x < 220)?true:false;} //객체가 선을 넘었는가
	bool IsDie(){	return obj.die;} //객체가 죽었는가
	bool IsOver(){	return obj.over_line;} //객체가 선을 넘어간 상태인가

	void SetDie(){	obj.die = true;} //객체 죽음
	void SetOver(){	obj.over_line = true;} //객체 선 넘어간 상태
	void SetSlow(){	obj.mov = 1;} //객체 이동 속도 1

	
private:
	object obj; 
	
};