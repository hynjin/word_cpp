#include <cstdlib>
#include <time.h>
#include "Define.h"
using namespace std;

typedef struct object
{
	int x; //x��ǥ
	int y; //y��ǥ
	int mov; //�̵��Ÿ�
	int line; //���° ���ο� ��������
	int show_time; //���� ��������
	int word_num; //��� �ܾ ������
	int word_index; //� �ܾ ������
	int language; //��� ���ε� �ܾ ������
	int color; //������ � �� ������
	bool die; //��ü ���翩��
	bool over_line;//�� ���� ��������
}object;

class Object
{
public:
	Object()
	{
		srand((unsigned int)time(NULL)*rand()%10000); //����
		obj.mov = rand()%4 + 1; //1~4 �߿� �������� ����
		obj.line = rand()%4; //0~3 �߿� ����
		obj.show_time = rand()%700 + 1500; //1500~1500+1000 �߿� ����
		obj.word_num = rand()%2 +1; //1Ȥ 2 ����
		obj.word_index = rand()%30; //0~29 �߿� ���� //���߿� 30���� ���ľ���
		obj.language = rand()%2; //0 �Ǵ� 1 ����
		obj.color = rand()%3; //0~2 �߿� ����
		obj.x = obj.show_time; //������ ȭ�� �ۿ� ��ü�� ��ġ
		obj.y = (140*obj.line)+40; //�������� ���ο� ��ġ
		obj.die = false; //����
		obj.over_line = false; //�� �Ѿ ����
	}
	//~Object();
	
	int GetObjX(){	return obj.x -= obj.mov;} //���ϴ� x��ǥ
	int GetObjY(){	return obj.y;} //������ y��ǥ
	int GetObjWordSize(){	return obj.word_num;} //�ܾ��
	int GetObjWord(){		return obj.word_index;} //���° �ܾ�
	int GetObjLanguage(){	return obj.language;} //�ѿ�
	int GetObjColor(){	return obj.color;} //������ ����
	
	bool IsOut(){	return (obj.x < -350)?true:false;} //��ü�� ȭ�� ������ �Ѿ��°�
	bool IsIn(){	return (obj.x < WINSIZE_X)?true:false;}; //��ü�� ȭ�� �ȿ� �ִ°�
	bool IsOverLine(){	return (obj.x < 220)?true:false;} //��ü�� ���� �Ѿ��°�
	bool IsDie(){	return obj.die;} //��ü�� �׾��°�
	bool IsOver(){	return obj.over_line;} //��ü�� ���� �Ѿ �����ΰ�

	void SetDie(){	obj.die = true;} //��ü ����
	void SetOver(){	obj.over_line = true;} //��ü �� �Ѿ ����
	void SetSlow(){	obj.mov = 1;} //��ü �̵� �ӵ� 1

	
private:
	object obj; 
	
};