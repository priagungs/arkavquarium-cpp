#include "ikan.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

ikan::ikan() {
	hunger = 50; //BERAPAAAA? EDIT LAGI INI
	tahap = 1;
	foodCounter = 0;
	moveCounter = 0;
	period = rand() % 10;
	mati = false;
}

//SetterGetter
int ikan::getHunger() {return hunger;}
int ikan::getTahap() {return tahap;}
int ikan::getfoodCounter() {return foodCounter;}
bool ikan::isMati() {return mati;}
void ikan::setHunger(int N) {hunger = N;}
void ikan::setTahap(int N) {tahap =N;}
void ikan::setFoodCounter(int N) {foodCounter = N;}
void ikan::setMati(bool B) {mati = B;}
void ikan::incCounter(){
	moveCounter++;
}
void ikan::resetPeriod(){
	if(moveCounter == period){
		moveCounter = 0;
		period = rand() % 10;
	}
}
