#include "Voca.h"
using namespace std;

Voca* Voca::vocaAdress = NULL;

Voca::Voca(){
	vocaIndex[0] = vocaIndex[1] = 0;
	vocaMode = 0;
	scrollPos = 0;
}

Voca::~Voca(){
	if(vocaAdress!=NULL)delete vocaAdress;
}

string Voca::getVoca(int voca, int offset){
	return dayVoca[voca][offset];
}

void Voca::setVocaIndex(int vocaNumber){
	vocaIndex[0] = vocaNumber;
}

void Voca::setScrollPos(int pos){
	scrollPos = pos;
}
void Voca::filp(int x, int y){
	if (isInWordPenal(x, y))vocaIndex[1] = (vocaIndex[1] + 1) % 2;
}

void Voca::next(){
	if (vocaIndex[0] < 29)++vocaIndex[0];
	//cout << "VocaNumber:" << vocaIndex[0] << endl;
}

void Voca::prev(){
	if (vocaIndex[0] > 0)--vocaIndex[0];
}

void Voca::init(){
	vocaIndex[0] = 0;
	vocaIndex[1] = 0;
	vocaMode = 0;
	scrollPos = 0;
}

void Voca::changeMode(){
	vocaMode = (vocaMode + 1) % 2;
}

void Voca::setVoca(int day){
	ifstream vocaFile;
	string address = "word\\day";

	address += ('1' + (day - 1)); //주소를 지정
	address += ".txt";
	cout << address << endl;

	vocaFile.open(address);

	if (vocaFile.is_open())
	{
		for (int i = 0; i < 30; ++i){
			getline(vocaFile, dayVoca[i][0]);
			//cout << "dayVoca[" << i << "][0]: " << dayVoca[i][0]<<endl;
			getline(vocaFile, dayVoca[i][1]);
			//cout << "dayVoca[" << i << "][0]: " << dayVoca[i][1] << endl;
		}
	}
	vocaFile.close();
}

Voca* Voca::getVocaInstance() {
	if (vocaAdress == NULL) vocaAdress = new Voca();
	return vocaAdress;
}

int Voca::getVocaNumber(){
	return vocaIndex[0];
}
int Voca::getVocaFilp(){
	return vocaIndex[1];
}

int Voca::getVocaMode(){
	return vocaMode;
}

int Voca::getScrollPos(){
	return scrollPos;
}

bool Voca::isInWordPenal(int x, int y){
	bool res;
	if (getVocaMode() == 0)res = ((200 < x && 840 > x) && (180 < y&&y < 530));
	else  res = false;


	return res;
}

string Voca::charToString(char* word){
	string res="";
	for (int i = 0; i < 128; i++){
		if (word[i] == '\0') break;
		else res += word[i];
	}
	
	return  res;
}