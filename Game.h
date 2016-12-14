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

	void Init(int i); //�ʱ�ȭ
	
	int GetSlimeX(int i); //�������� x��ǥ
	int GetSlimeY(int i); //�������� y��ǥ
	int GetSlimeColor(int i); //�������� ����
	int GetSlimeNum(); //�� ����� �������� ������ �� �ִ���
	int GetSlimeWord(int i); //�������� ���� �ܾ �ܾ��忡�� ���° �ܾ�����
	int GetSlimeLanguage(int i); //�������� ���� �ܾ��� ���
	void SetSlimeDie(int i); //������ ����

	int GetBombX(); //��ź�� x��ǥ
	int GetBombY(); //��ź�� y��ǥ
	int GetBombWord(); //��ź�� ���� �ܾ �ܾ��忡�� ���° �ܾ�����
	int GetBombLanguage(); //��ź�� ���� �ܾ��� ���
	void SetBombDie(); //��ź ����
	
	int GetFishX(); //������� x��ǥ
	int GetFishY(); //������� y��ǥ
	int GetFishWord(); //����Ⱑ ���� �ܾ �ܾ��忡�� ���° �ܾ�����
	int GetFishLanguage(); //����Ⱑ ���� �ܾ��� ���
	void SetFishDie(); //����� ����

	int GetTimeX(); //�ð��� x��ǥ
	int GetTimeY(); //�ð��� y��ǥ
	int GetTimeWord(); //�ð谡 ���� �ܾ �ܾ��忡�� ���° �ܾ�����
	int GetTimeLanguage(); //�ð谡 ���� �ܾ��� ���
	void SetTimeDie(); //�ð� ����
	
	int GetStage(); //���� ��������
	int GetLife(); //����� �󸶳� ���Ҵ���
	bool isDie(); //��ü�� �׾��� Ȯ��
	int CheckGame(); //������ ������ Ȯ��
	void CheckState(); //��ü�� ȭ�� ������ �����ų� ������ �ʱ�ȭ

private:
	int stage, dieSlime, slimeNum,life;

	string enterWord;

	Object *slime; //������ ��ü(�����Ҵ�)
	Object *pSlime; //������ ���� �Ҷ� ����� ������
	Object *bomb_i; //��ź ������ ��ü
	Object *fish_i; //����� �����۰�ü
	Object *time_i; //�ð� ������ ��ü
};