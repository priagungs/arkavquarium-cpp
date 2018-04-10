#include "ikan.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

ikan::ikan() {
	hunger = 1000; //BERAPAAAA? EDIT LAGI INI
	tahap = 1;
	foodCounter = 0;
	moveCounter = rand() % 10000;
	mati = false;
	hungerState = false;
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
void ikan::decCounter(){
	moveCounter--;
	if(moveCounter <= 0){
		moveCounter = rand() % 10000;
	}
}
bool ikan::getHungerState(){
	return hungerState;
}
void ikan::setHungerState(){
	hunger--;
	if(hunger < 10){ //bisa disesuaikan angka nya
		hungerState = true;
	}
	else{
		hungerState = false;
	}
}
