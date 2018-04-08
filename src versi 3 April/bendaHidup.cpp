#include "bendaHidup.hpp"
#include "entitas.hpp"
#include <string>
#include <iostream>
using namespace std;

//Ctor
bendaHidup::bendaHidup() {
	x = 0;
	y = 0;
	direction = 0;
}

bendaHidup::bendaHidup(double X, double Y, double dir) {
	x = X;
	y = Y;
	direction = dir;
}


//Setter Getter
double bendaHidup::getX() {return x;}
double bendaHidup::getY() {return y;}
double bendaHidup::getDirection() {return direction;}

void bendaHidup::setX(double X) {x = X;}
void bendaHidup::setY(double Y) {y = Y;}
void bendaHidup::setDirection(double d) {direction = d;}
