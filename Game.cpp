#include "Game.h"

Game :: Game()
{
	Init(1); //ó�� ���������� 1
}
void Game :: Init(int i)
{
	stage = i;
	life = LIFE_NUM; //ó�� ������ 5
	dieSlime = 0; //ó�� ���� ������ ������ 0
	slimeNum = stage*3; //�� ȭ�鿡 �ִ� ����� �������� �����ϴ���
	slime = new Object[slimeNum]; //������ �ִ� ������ŭ ���� �Ҵ�
	pSlime = new Object; //������ �����Ҵ�
	bomb_i = new Object; //��ź �����Ҵ�
	fish_i = new Object; //����� �����Ҵ�
	time_i = new Object; //�ð� �����Ҵ�
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
	if(life == 0) //���� ������ ���ٸ�
	{
		Init(1); //��������1�� �ʱ�ȭ
		return GAME_OVER; //���� ���¸� over�� ����
	}
	else if(dieSlime == slimeNum) //���� �������� stage*3�� ���ٸ�
	{
		stage ++; //�������� ����
		if(stage != 4)
			Init(stage); //������ ���������� �ʱ�ȭ
		else //������ �������� Ŭ����
			Init(1); //�������� 1�� �ʱ�ȭ
		return (stage != 1)?GAME_CLEAR:ALL_CLEAR; //���� ���¸� clear�� ����
	}
	else //���� ����
		return ING;
}

void Game :: CheckState()
{
	for(int i=0;i<slimeNum;i++)
	{
		if(slime[i].IsOverLine() && !slime[i].IsOver()) //�������� ���� ���� ������ üũ
		{
			slime[i].SetOver();//�ѹ� �Ѵ� ���� true�� ����
			life--; //���� ����
		}
		if(slime[i].IsOut() || slime[i].IsDie()) //�������� ȭ�� ������ �����ų� �׾��� ���
		{
			pSlime = new Object; //�����Ҵ�
			slime[i] = *pSlime; //���� ������ ��� ���ο� ������
		}
		delete(pSlime); 
		pSlime = new Object;
	}
	if(bomb_i->IsOut() || bomb_i->IsDie()) //��ź�� ȭ�� ������ �����ų� �׾��� ���
	{
		delete(bomb_i);
		bomb_i = new Object;
	}
	if(fish_i->IsOut() || fish_i->IsDie()) //����Ⱑ ȭ�� ������ �����ų� �׾��� ���
	{
		delete(fish_i);
		fish_i = new Object;
	}
	if(time_i->IsOut() || time_i->IsDie()) //�ð谡 ȭ�� ������ �����ų� �׾��� ���
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
	if(!slime[i].IsOverLine() && slime[i].IsIn()) //�������� ���� ���� �ʰ� ȭ�� �ȿ� ���� ���
	{
		dieSlime++; //���� ������ ���� ����
		slime[i].SetDie(); //������ ����
	}
}

int Game :: GetBombX(){	return bomb_i->GetObjX();}
int Game :: GetBombY(){	return bomb_i->GetObjY();}
void Game :: SetBombDie()
{	
		printf("%s\n",enterWord);
	if(!bomb_i->IsOverLine() && bomb_i->IsIn()) //��ź�� ���� ���� �ʰ� ȭ�� �ȿ� ���� ���
	{
		for(int i = 0;i<slimeNum; i++) 
		{
			 if(slime[i].IsIn()) //ȭ��ȿ� �ִ� �����ӵ�
				slime[i].SetDie(); //����
		}
	}
	bomb_i->SetDie(); //��ź ����
}

int Game :: GetFishX(){	return fish_i->GetObjX();}
int Game :: GetFishY(){	return fish_i->GetObjY();}
void Game :: SetFishDie()
{
		printf("%s\n",enterWord);
	if(!fish_i->IsOverLine() && fish_i->IsIn() && life < 5) //����Ⱑ ���� ���� �ʰ� ȭ�� �ȿ� �ְ� ������ 5���� ���� ���
		life ++; //���� 1 ����
	fish_i->SetDie(); //����� ����
}

int Game :: GetTimeX(){	return time_i->GetObjX();}
int Game :: GetTimeY(){	return time_i->GetObjY();}
void Game :: SetTimeDie()
{	
		printf("%s\n",enterWord);
	if(!time_i->IsOverLine() && time_i->IsIn()) //�ð谡 ���� ���� �ʰ� ȭ�� �ȿ� ���� ���
	{
		for(int i = 0;i<slimeNum; i++)
		{
			if(slime[i].IsIn()) //ȭ��ȿ� �ִ� �����ӵ�
				slime[i].SetSlow(); //������
		}
		if(bomb_i->IsIn()) //ȭ�� �ȿ� �ִ� ��ź
			bomb_i->SetSlow(); //������
		if(fish_i->IsIn()) //ȭ�� �ȿ� �ִ� �����
			fish_i->SetSlow(); //������
	}
	time_i->SetDie(); //�ð� ����
}
