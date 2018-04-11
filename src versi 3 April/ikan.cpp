#include "ikan.hpp"
#include "konstanta.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

ikan::ikan() {
	hunger = GUPPY_HUNGER;
	tahap = 1;
	foodCounter = 0;
	srand((unsigned)time(NULL));
	moveCounter = rand() % MAX_MOVE_COUNTER;
	mati = false;
	hungerState = false;
}

//SetterGetter
int ikan::getHunger() {return hunger;}
int ikan::getTahap() {return tahap;}
int ikan::getfoodCounter() {return foodCounter;}
int ikan::getMoveCounter() {return moveCounter;}
bool ikan::isMati() {return mati;}
void ikan::setHunger(int N) {hunger = N;}
void ikan::setTahap(int N) {tahap =N;}
void ikan::setFoodCounter(int N) {foodCounter = N;}
void ikan::setMati(bool B) {mati = B;}
void ikan::decCounter(){
	moveCounter--;
	if(moveCounter <= 0){
		srand((unsigned)time(NULL));
		moveCounter = rand() % MAX_MOVE_COUNTER;
	}
}
bool ikan::getHungerState(){
	return hungerState;
}
void ikan::setHungerState(){
	hunger--;
	if(hunger < GUPPY_MIN_HUNGER_STATE){ //bisa disesuaikan angka nya
		hungerState = true;
	}
	else{
		hungerState = false;
	}
}
