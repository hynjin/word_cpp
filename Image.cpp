#include "Image.h"
#include "Voca.h"

Voca* voca;
Image :: Image()
{
	voca = Voca::getVocaInstance();
	gameState = ING;
	slime = new CImage[game.GetSlimeNum()];
	logo.Load(_T("img\\7day.bmp"));
	background.Load(_T("img\\background.bmp"));
	card.Load(_T("img\\card.bmp"));
	scrollcard.Load(_T("img\\scrollCard.bmp"));
	cat.Load(_T("img\\Over_c.bmp"));
	goWord_b[0].Load(_T("img\\goWord.bmp"));
	goGame_b[0].Load(_T("img\\goGame.bmp"));
	choose.Load(_T("img\\choose.bmp"));
	home_b[0].Load(_T("img\\home.bmp"));
	home_b[1].Load(_T("img\\home_p.bmp"));
	day[0][0].Load(_T("img\\day1.bmp"));
	day[0][1].Load(_T("img\\day2.bmp"));
	day[0][2].Load(_T("img\\day3.bmp"));
	day[0][3].Load(_T("img\\day4.bmp"));
	day[0][4].Load(_T("img\\day5.bmp"));
	day[0][5].Load(_T("img\\day6.bmp"));
	day[0][6].Load( _T("img\\day7.bmp"));
	back_b[0].Load(_T("img\\back.bmp"));
	enter_b[0].Load(_T("img\\enter.bmp"));
	change_b[0].Load(_T("img\\change.bmp"));
	ccat[0].Load(_T("img\\cat0.bmp"));
	dish[0].Load(_T("img\\dish0.bmp"));
	dish[1].Load(_T("img\\dish1.bmp"));
	dish[2].Load(_T("img\\dish2.bmp"));
	dish[3].Load(_T("img\\dish3.bmp"));
	dish[4].Load(_T("img\\dish4.bmp"));
	dish[5].Load(_T("img\\dish5.bmp"));
	dish[6].Load(_T("img\\dish6.bmp"));
	cslime[0][0].Load(_T("img\\slime1-1.bmp"));
	cslime[0][1].Load(_T("img\\slime1-2.bmp"));
	cslime[0][2].Load(_T("img\\slime1-3.bmp"));
	cslime[1][0].Load(_T("img\\slime2-1.bmp"));
	cslime[1][1].Load(_T("img\\slime2-2.bmp"));
	cslime[1][2].Load(_T("img\\slime2-3.bmp"));
	cslime[2][0].Load(_T("img\\slime3-1.bmp"));
	cslime[2][1].Load(_T("img\\slime3-2.bmp"));
	cslime[2][2].Load(_T("img\\slime3-3.bmp"));
	bomb[0].Load(_T("img\\bomb0.bmp"));
	bomb[1].Load(_T("img\\bomb1.bmp"));
	bomb[2].Load(_T("img\\bomb2.bmp"));
	fish[0].Load(_T("img\\fish0.bmp"));
	fish[1].Load(_T("img\\fish1.bmp"));
	fish[2].Load(_T("img\\fish2.bmp"));
	time[0].Load(_T("img\\time0.bmp"));
	time[1].Load(_T("img\\time1.bmp"));
	time[2].Load(_T("img\\time2.bmp"));
	game_s[0].Load(_T("img\\gameClear.bmp"));
	game_s[1].Load(_T("img\\gameOver.bmp")); 
	clear[0].Load(_T("img\\Clear1.bmp"));  
	clear[1].Load(_T("img\\Clear1.bmp"));  
	clear[2].Load(_T("img\\Clear2.bmp"));  
	clear[3].Load(_T("img\\Clear.bmp")); 
	over.Load(_T("img\\Over.bmp")); 
	movMain_b.Load(_T("img\\gomain.bmp"));
	nextStage_b[0].Load(_T("img\\nextStage.bmp"));
	replay_b[0].Load(_T("img\\replay.bmp"));
	next_b.Load(_T("img\\next.bmp"));
	prev_b.Load(_T("img\\prev.bmp"));
	enter_bp.Load(_T("img\\enter_bp.bmp"));
	home_bp.Load(_T("img\\home_bp.bmp"));
}

Image :: ~Image()
{
	logo.Destroy();
	background.Destroy();
	card.Destroy();
	scrollcard.Destroy();
	cat.Destroy();
	goWord_b[0].Destroy();
	goGame_b[0].Destroy();
	choose.Destroy();
	home_b[0].Destroy();
	home_b[1].Destroy();
	day[0][0].Destroy();
	day[0][1].Destroy();
	day[0][2].Destroy();
	day[0][3].Destroy();
	day[0][4].Destroy();
	day[0][5].Destroy();
	day[0][6].Destroy();
	back_b[0].Destroy();
	enter_b[0].Destroy();
	change_b[0].Destroy();
	ccat[0].Destroy();
	dish[0].Destroy();
	dish[1].Destroy();
	dish[2].Destroy();
	dish[3].Destroy();
	dish[4].Destroy();
	dish[5].Destroy();
	dish[6].Destroy();
	cslime[0][0].Destroy();
	cslime[0][1].Destroy();
	cslime[0][2].Destroy();
	cslime[1][0].Destroy();
	cslime[1][1].Destroy();
	cslime[1][2].Destroy();
	cslime[2][0].Destroy();
	cslime[2][1].Destroy();
	cslime[2][2].Destroy();
	bomb[0].Destroy();
	bomb[1].Destroy();
	bomb[2].Destroy();
	fish[0].Destroy();
	fish[1].Destroy();
	fish[2].Destroy();
	time[0].Destroy();
	time[1].Destroy();
	time[2].Destroy();
	game_s[0].Destroy();
	game_s[1].Destroy();
	clear[0].Destroy();
	clear[1].Destroy();
	clear[2].Destroy();
	clear[3].Destroy();
	over.Destroy();
	movMain_b.Destroy();
	nextStage_b[0].Destroy();
	replay_b[0].Destroy();
	next_b.Destroy();
	prev_b.Destroy();
}

HBITMAP Image :: GetMainB(){return home_b[0].Detach();} //�����̵� ��ư�� ���� �̹���
HBITMAP Image :: GetWordB(){return goWord_b[0].Detach();} //�ܾ��� �̵� ��ư�� ���� �̹���
HBITMAP Image :: GetGameB(){return goGame_b[0].Detach();} //���� �̵� ��ư�� ���� �̹���
HBITMAP Image :: GetBackB(){return back_b[0].Detach();} //�ڷ� �̵� ��ư�� ���� �̹���
HBITMAP Image :: GetEnterB(){return enter_b[0].Detach();} //Ȯ�� ��ư�� ���� �̹���
HBITMAP Image :: GetChangeB(){return change_b[0].Detach();} //��ȯ ��ư�� ���� �̹���
HBITMAP Image :: GetDayB(int d){return day[0][d].Detach();} //��¥ ��ư�� ���� �̹���
HBITMAP Image :: GetNextB(){ return next_b.Detach(); } //���� ��ư�� ���� �̹���
HBITMAP Image :: GetPrevB(){ return prev_b.Detach(); } //���� ��ư�� ���� �̹���
HBITMAP Image :: GetGoMainB(){	return movMain_b.Detach();} //�����̵� ��ư�� ���� �̹���
HBITMAP Image :: GetNextStageB(){ return nextStage_b[0].Detach(); } //���� �ܰ� ��ư�� ���� �̹���
HBITMAP Image :: GetReplayB(){ return replay_b[0].Detach(); } //�ٽ��ϱ� ��ư�� ���� �̹���

void Image :: SetEnterWord(LPWSTR str){	enterWord = str;} //�Էµ� �ܾ� �޾ƿ�
void Image :: SetDay(int i){	voca->setVoca(i);} //�ܾ����� �ܾ� ����

int Image :: GetGameState(){	return game.CheckGame();} //���� ���� �о��

void Image :: MainDraw(HDC hdc)
{
	game.Init(1);//����ȭ�鿡�� �������� �̵��� ��� �������̴� ���� �ʱ�ȭ
	logo.TransparentBlt( hdc, 280,100, logo.GetWidth(), logo.GetHeight(),RGB(255,255,255) );
	cat.TransparentBlt( hdc, 190,270, cat.GetWidth(), cat.GetHeight(),RGB(255,255,255) );
}

void Image :: DayDraw(HDC hdc)
{
	choose.TransparentBlt( hdc, 200,80, choose.GetWidth(), choose.GetHeight(),RGB(255,255,255) );
}

void Image :: WordDraw(HDC hdc, HWND hWnd)
{
	int vocaNumber, vocaFlip, scrollPos;
	string vocaPos;
	CString temp;
	SetTextAlign(hdc, TA_CENTER); //�߾�����

	if (!voca->getVocaMode()){

		font = CreateFont(100, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
		oldfont = (HFONT)SelectObject(hdc, font);
		vocaNumber = voca->getVocaNumber();
		vocaFlip = voca->getVocaFilp();

		if (vocaNumber < 9);
		else if (vocaNumber < 19)vocaPos = '1';
		else if (vocaNumber < 29)vocaPos = '2';
		else vocaPos = '3';

		vocaPos += '0' + (vocaNumber + 1) % 10;
		vocaPos += "/30";

		ShowWindow(hWnd, false);
		Rectangle(hdc, 200, 180, 840, 530);
		temp = voca->getVoca(vocaNumber, vocaFlip).c_str();
		TextOut(hdc, 520, 300, temp, temp.GetLength());

		DeleteObject(font);
		font = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
		SelectObject(hdc, font);
		temp = vocaPos.c_str();
		TextOut(hdc, 760, 200, temp, vocaPos.length());
		cout << vocaPos << endl;
		cout << voca->getVoca(vocaNumber, vocaFlip) << endl;
		SelectObject(hdc, oldfont);//��Ʈ ����
		DeleteObject(font);// ���� ���� ��Ʈ ����
	}
	else{
		ShowWindow(hWnd, true);

		font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
		oldfont = (HFONT)SelectObject(hdc, font);
		scrollPos = voca->getScrollPos();

		Rectangle(hdc, 200, 180, 840, 530);
		vocaFlip = voca->getVocaFilp();
		temp = voca->getVoca(scrollPos / 100, 0).c_str();
		TextOut(hdc, 360, 213, temp, temp.GetLength());
		temp = voca->getVoca(scrollPos / 100, 1).c_str();
		TextOut(hdc, 680, 213, temp, temp.GetLength());
		temp = voca->getVoca(scrollPos / 100 + 1, 0).c_str();
		TextOut(hdc, 360, 330, temp, temp.GetLength());
		temp = voca->getVoca(scrollPos / 100 + 1, 1).c_str();
		TextOut(hdc, 680, 330, temp, temp.GetLength());
		temp = voca->getVoca(scrollPos / 100 + 2, 0).c_str();
		TextOut(hdc, 360, 446, temp, temp.GetLength());
		temp = voca->getVoca(scrollPos / 100 + 2, 1).c_str();
		TextOut(hdc, 680, 446, temp, temp.GetLength());

		SelectObject(hdc, oldfont);//��Ʈ ����
		DeleteObject(font);// ���� ���� ��Ʈ ����

	}
}

void Image::GameDraw(HWND hWndMain,HBITMAP& hBit)
{
	RECT crt; //double buffer
	HDC hdc, hMemDC;
	HBITMAP OldBit;
	static int ani; //��ü �ִϸ��̼ǿ� ���� ����
	CString temp; //��µǴ� �ܾ�� �ݴ��� ���� �� �ܾ�

	GetClientRect(hWndMain, &crt);
	hdc = GetDC(hWndMain);
	if (hBit == NULL) {
		hBit = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);
	}
	hMemDC = CreateCompatibleDC(hdc);
	OldBit = (HBITMAP)SelectObject(hMemDC, hBit);

	HFONT font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 3, 2, 1, VARIABLE_PITCH | FF_ROMAN, _T("����")); //�ܾ� ��Ʈ ����
	HFONT oldfont = (HFONT)SelectObject(hMemDC, font); //������ ��Ʈ

	background.TransparentBlt(hMemDC, 0, 0, background.GetWidth(), background.GetHeight(), RGB(255, 255, 255)); //��� �׸���
	home_bp.TransparentBlt(hMemDC, 10, 10, home_bp.GetWidth(), home_bp.GetHeight(), RGB(255, 255, 255)); //Ȩ ��ư �׸���
	enter_bp.TransparentBlt(hMemDC, 620, 650, enter_bp.GetWidth(), enter_bp.GetHeight(), RGB(255, 255, 255)); //Ȯ�� ��ư �׸���
	
	game.CheckState(); //���� ���� Ȯ��
	dish[game.GetLife()].TransparentBlt(hMemDC, 40, 250, dish[game.GetLife()].GetWidth(), dish[game.GetLife()].GetHeight(), RGB(255, 255, 255));//�����̹���
	
	for(int i=0;i<game.GetSlimeNum();i++)
	{
		CString str = voca->getVoca(game.GetSlimeWord(i),game.GetSlimeLanguage(i)).c_str(); //�������� ������ �ִ� �ܾ�
		temp = voca->getVoca(game.GetSlimeWord(i),(game.GetSlimeLanguage(i)+1)%2).c_str(); //�������� �ܾ��� �ݴ� ���
		
		if(enterWord == temp) //�Է��� �ܾ�� ������ �ܾ��� �ݴ� ��� �ܾ�� ���ٸ�
		{
			game.SetSlimeDie(i); //������ ����
			enterWord = " "; //�Էµ� �ܾ� �ʱ�ȭ
		}
		slime[i] = cslime[game.GetSlimeColor(i)][(ani+1)%3]; //�������� ����� �ִϸ��̼� �޾ƿ�

		slime[i].TransparentBlt(hMemDC, game.GetSlimeX(i), game.GetSlimeY(i), slime[i].GetWidth(), slime[i].GetHeight(), RGB(255, 255, 255)); //������ �׸�
		TextOut(hMemDC, game.GetSlimeX(i) + 35, game.GetSlimeY(i) + 100, str, str.GetLength()); //�������� �ܾ� �׸�
		
	}

	bomb[(ani + 1) % 3].TransparentBlt(hMemDC, game.GetBombX(), game.GetBombY(), bomb[0].GetWidth(), bomb[0].GetHeight(), RGB(255, 255, 255)); //��ź �׸�
	CString b = voca->getVoca(game.GetBombWord(), game.GetBombLanguage()).c_str();//��ź �ܾ�
		temp = voca->getVoca(game.GetBombWord(), (game.GetBombLanguage() + 1) % 2).c_str(); //��ź �ܾ��� �ݴ� ���
	if(enterWord == temp) //��ź�� ��� �ִ� �ܾ��� ���̳� ��� �Է�
	{
		game.SetBombDie(); //��ź ����
		enterWord = " "; //�Էµ� �ܾ� �ʱ�ȭ
	}
	TextOut(hMemDC, game.GetBombX() + 105, game.GetBombY() + 100, b, b.GetLength()); //��ź �ܾ� ���
	
	fish[(ani + 2) % 3].TransparentBlt(hMemDC, game.GetFishX(), game.GetFishY(), fish[0].GetWidth(), fish[0].GetHeight(), RGB(255, 255, 255)); //����� �׸�
	CString f = voca->getVoca(game.GetFishWord(), game.GetFishLanguage()).c_str(); //����� �ܾ�
	temp = voca->getVoca(game.GetFishWord(), (game.GetFishLanguage() + 1) % 2).c_str(); //����� �ܾ��� �ݴ� ���
	if(enterWord == temp) //����� �ܾ��� ���̳� ��� �Է�
	{
		game.SetFishDie(); //����� ����
		enterWord = " "; //�Էµ� �ܾ� �ʱ�ȭ
	}
	TextOut(hMemDC, game.GetFishX() + 105, game.GetFishY() + 100, f, f.GetLength()); //����� �ܾ� ���
	
	time[(ani + 3) % 3].TransparentBlt(hMemDC, game.GetTimeX(), game.GetTimeY(), time[0].GetWidth(), time[0].GetHeight(), RGB(255, 255, 255)); //�ð� �׸�
	CString t = voca->getVoca(game.GetTimeWord(),game.GetTimeLanguage()).c_str(); //�ð� �ܾ�
	temp = voca->getVoca(game.GetTimeWord(),(game.GetTimeLanguage()+1)%2).c_str(); //�ð� �ܾ��� �ݴ� ���
	if(enterWord == temp) //�ð� �ܾ��� ���̳� ��� �Է�
	{
		game.SetTimeDie(); //�ð� ����
		enterWord = " "; //�Էµ� �ܾ� �ʱ�ȭ
	}
	TextOut(hMemDC, game.GetTimeX() + 105, game.GetTimeY() + 100, t, t.GetLength()); //�ð� �ܾ� ���

	ani = (ani++)%3; //�ִϸ��̼� �ٲ�

	ccat[0].TransparentBlt(hMemDC, 50, 530, ccat[0].GetWidth(), ccat[0].GetHeight(), RGB(255, 255, 255)); //����� �׸�
	
	
	SelectObject(hMemDC, oldfont); //���� ��Ʈ ����
	DeleteObject(font); //��Ʈ ����


	SelectObject(hMemDC, OldBit);//double buffer
	DeleteDC(hMemDC);
	ReleaseDC(hWndMain, hdc);
	InvalidateRect(hWndMain, NULL, FALSE);

}
void Image :: GameEndDraw(HDC hdc,int i)
{
	if(i == GAME_CLEAR) //���� ���°� clear��� Ŭ���� ȭ�� ���
	{
		game_s[0].TransparentBlt( hdc, 0,0, game_s[0].GetWidth(), game_s[0].GetHeight(),RGB(255,255,255) );
		clear[game.GetStage()-1].TransparentBlt( hdc, 180,100, clear[game.GetStage()-1].GetWidth(), clear[game.GetStage()-1].GetHeight(),RGB(255,255,255) );
	}
	else if(i == ALL_CLEAR)
	{
		game_s[0].TransparentBlt( hdc, 0,0, game_s[0].GetWidth(), game_s[0].GetHeight(),RGB(255,255,255) );
		clear[3].TransparentBlt( hdc, 180,100, clear[3].GetWidth(), clear[3].GetHeight(),RGB(255,255,255) );
	}
	else if(i == GAME_OVER) //���� ���°� over��� ���� ȭ�� ���
	{
		game_s[1].TransparentBlt( hdc, 0,0, game_s[1].GetWidth(), game_s[1].GetHeight(),RGB(255,255,255) );
		over.TransparentBlt( hdc, 230,100, over.GetWidth(), over.GetHeight(),RGB(255,255,255) );
	}
}

int Image::getVocaNumber(){
	return voca->getVocaNumber();
}

void Image::callBackground(HDC hdc){
	background.TransparentBlt(hdc, 0, 70, 1040, 500, RGB(255, 255, 255));
}