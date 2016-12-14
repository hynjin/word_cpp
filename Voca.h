#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Voca{
	string dayVoca[30][2];
	int vocaIndex[2];
	int vocaMode;
	int scrollPos;
	static Voca* vocaAdress;


public:
	Voca();
	~Voca();

	void setVoca(int day);
	void setVocaIndex(int vocaNumber);
	void setScrollPos(int);
	void filp(int x, int y);
	void prev();
	void next();
	void init();
	void changeMode();
	string getVoca(int voca, int offset);
	static Voca* getVocaInstance();
	int getVocaNumber();
	int getVocaFilp();
	int getVocaMode();
	int getScrollPos();
	bool isInWordPenal(int x, int y);
	string charToString(char* voca);

private:

};