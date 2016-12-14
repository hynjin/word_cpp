#include "Game.h"

Game :: Game()
{
	Init(1); //처음 스테이지는 1
}
void Game :: Init(int i)
{
	stage = i;
	life = LIFE_NUM; //처음 생명은 5
	dieSlime = 0; //처음 죽은 슬라임 갯수는 0
	slimeNum = stage*3; //한 화면에 최대 몇마리의 슬라임이 등장하는지
	slime = new Object[slimeNum]; //슬라임 최대 갯수만큼 동적 할당
	pSlime = new Object; //슬라임 동적할당
	bomb_i = new Object; //폭탄 동적할당
	fish_i = new Object; //물고기 동적할당
	time_i = new Object; //시계 동적할당
}

int Game :: GetSlimeWord(int i)		{	return slime[i].GetObjWord();}
int Game :: GetSlimeLanguage(int i)	{	return slime[i].GetObjLanguage();}
int Game :: GetBombWord()			{	return bomb_i->GetObjWord();}
int Game :: GetBombLanguage()		{	return bomb_i->GetObjLanguage();}
int Game :: GetFishWord()			{	return fish_i->GetObjWord();}
int Game :: GetFishLanguage()		{	return fish_i->GetObjLanguage();}
int Game :: GetTimeWord()			{	return time_i->GetObjWord();}
int Game :: GetTimeLanguage()		{	return time_i->GetObjLanguage();}

int Game :: GetStage(){	return stage;}
int Game :: GetLife(){	return life;}

int Game :: CheckGame()
{	
	if(life == 0) //남은 생명이 없다면
	{
		Init(1); //스테이지1로 초기화
		return GAME_OVER; //게임 상태를 over로 리턴
	}
	else if(dieSlime == slimeNum) //죽인 슬라임이 stage*3과 같다면
	{
		stage ++; //스테이지 증가
		if(stage != 4)
			Init(stage); //증가한 스테이지로 초기화
		else //마지막 스테이지 클리어
			Init(1); //스테이지 1로 초기화
		return (stage != 1)?GAME_CLEAR:ALL_CLEAR; //게임 상태를 clear로 리턴
	}
	else //게임 진행
		return ING;
}

void Game :: CheckState()
{
	for(int i=0;i<slimeNum;i++)
	{
		if(slime[i].IsOverLine() && !slime[i].IsOver()) //슬라임이 선을 넘은 순간만 체크
		{
			slime[i].SetOver();//한번 넘는 순간 true로 설정
			life--; //생명 감소
		}
		if(slime[i].IsOut() || slime[i].IsDie()) //슬라임이 화면 밖으로 나가거나 죽었을 경우
		{
			pSlime = new Object; //동적할당
			slime[i] = *pSlime; //죽은 슬라임 대신 새로운 슬라임
		}
		delete(pSlime); 
		pSlime = new Object;
	}
	if(bomb_i->IsOut() || bomb_i->IsDie()) //폭탄이 화면 밖으로 나가거나 죽었을 경우
	{
		delete(bomb_i);
		bomb_i = new Object;
	}
	if(fish_i->IsOut() || fish_i->IsDie()) //물고기가 화면 밖으로 나가거나 죽었을 경우
	{
		delete(fish_i);
		fish_i = new Object;
	}
	if(time_i->IsOut() || time_i->IsDie()) //시계가 화면 밖으로 나가거나 죽었을 경우
	{
		delete(time_i);
		time_i = new Object;
	}
	printf("%d\t%d\t%d\n",dieSlime,life,slimeNum);
}

int Game :: GetSlimeX(int i){	return slime[i].GetObjX();}
int Game :: GetSlimeY(int i){	return slime[i].GetObjY();}
int Game :: GetSlimeColor(int i){	return slime[i].GetObjColor();}
int Game :: GetSlimeNum(){	return slimeNum;}
void Game :: SetSlimeDie(int i)
{
		printf("%s\n",enterWord);
	if(!slime[i].IsOverLine() && slime[i].IsIn()) //슬라임이 선을 넘지 않고 화면 안에 있을 경우
	{
		dieSlime++; //죽은 슬라임 갯수 증가
		slime[i].SetDie(); //슬라임 죽음
	}
}

int Game :: GetBombX(){	return bomb_i->GetObjX();}
int Game :: GetBombY(){	return bomb_i->GetObjY();}
void Game :: SetBombDie()
{	
		printf("%s\n",enterWord);
	if(!bomb_i->IsOverLine() && bomb_i->IsIn()) //폭탄이 선을 넘지 않고 화면 안에 있을 경우
	{
		for(int i = 0;i<slimeNum; i++) 
		{
			 if(slime[i].IsIn()) //화면안에 있는 슬라임들
				slime[i].SetDie(); //죽임
		}
	}
	bomb_i->SetDie(); //폭탄 죽음
}

int Game :: GetFishX(){	return fish_i->GetObjX();}
int Game :: GetFishY(){	return fish_i->GetObjY();}
void Game :: SetFishDie()
{
		printf("%s\n",enterWord);
	if(!fish_i->IsOverLine() && fish_i->IsIn() && life < 5) //물고기가 선을 넘지 않고 화면 안에 있고 생명이 5보다 작을 경우
		life ++; //생명 1 증가
	fish_i->SetDie(); //물고기 죽음
}

int Game :: GetTimeX(){	return time_i->GetObjX();}
int Game :: GetTimeY(){	return time_i->GetObjY();}
void Game :: SetTimeDie()
{	
		printf("%s\n",enterWord);
	if(!time_i->IsOverLine() && time_i->IsIn()) //시계가 선을 넘지 않고 화면 안에 있을 경우
	{
		for(int i = 0;i<slimeNum; i++)
		{
			if(slime[i].IsIn()) //화면안에 있는 슬라임들
				slime[i].SetSlow(); //느려짐
		}
		if(bomb_i->IsIn()) //화면 안에 있는 폭탄
			bomb_i->SetSlow(); //느려짐
		if(fish_i->IsIn()) //화면 안에 있는 물고기
			fish_i->SetSlow(); //느려짐
	}
	time_i->SetDie(); //시계 죽음
}
