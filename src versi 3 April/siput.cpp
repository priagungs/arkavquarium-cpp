#include "siput.hpp"
#include "oop.hpp"
#include "bendaHidup.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//Ctor
siput::siput() : bendaHidup(SCREEN_WIDTH/2, SCREEN_HEIGHT, 0)  {}

void siput::move(double,double) {
}


//Override moveTowardsTarget (Kecepatan berbeda dari bendaHidup lain)
void siput::moveTowardsTarget(double x, double y) {
	//if (x > getX()) {
		//if (x-getX() <= /* MaxMove */) {
			//setX(x);
		//} else {
			//setX(/*MaxMove*/);
	//	}
	//} else {
		//setDirection("kiri");
		//if (getX()-x <= /*MaxMove*/) {
			//setX(x);
		//} else {
		//	setX(/*MaxMove*/);
		//}
	//}
}
