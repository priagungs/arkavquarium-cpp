#include "siput.hpp"
#include "oop.hpp"
#include "bendaHidup.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//Ctor
siput::siput() : bendaHidup(SCREEN_WIDTH/2, SCREEN_HEIGHT-50)  {}

void siput::move(double time) {

}


//Override moveTowardsTarget (Kecepatan berbeda dari bendaHidup lain)
void siput::moveTowardsTarget(double x, double y, double t) {
	if(x > this->x){
		this->x += x*t*speed;
	}
	else if(x < this->x){
		this->x -= x*t*speed;
	}
}
