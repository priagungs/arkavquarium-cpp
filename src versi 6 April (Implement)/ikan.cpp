#include "ikan.hpp"
#include <iostream>
using namespace std;

ikan::ikan() {
	hunger = 10; //BERAPAAAA? EDIT LAGI INI
	tahap = 1;
	foodCounter = 0;
	mati = false;
}
ikan::ikan(int h, int t, int f, bool m) {
	hunger = h;
	tahap = t;
	foodCounter = 0;
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