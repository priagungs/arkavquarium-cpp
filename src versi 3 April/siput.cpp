#include "siput.hpp"
#include "bendaHidup.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//Ctor
siput::siput() : bendaHidup(/*25,50, "kanan"*/)  {}

//Override moveTowardsTarget (Kecepatan berbeda dari bendaHidup lain)
void siput::moveTowardsTarget(int x, int y) {
	if (x > getX()) {
		if (x-getX() <= /*MaxMove*/) {
			setX(x);
		} else {
			setX(/*MaxMove*/);
		}
	} else {
		setDirection("kiri");
		if (getX()-x <= /*MaxMove*/) {
			setX(x);
		} else {
			setX(/*MaxMove*/);
		}
	}
	
}
