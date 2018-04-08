#include "bendaHidup.hpp"
#include "entitas.hpp"
#include <string>
#include <iostream>
using namespace std;

//Ctor
bendaHidup::bendaHidup() : entitas() {
	x = 0;
	y = 0;
	direction = "kanan";
}

bendaHidup::bendaHidup(int X, int Y, string dir) {
	x = X;
	y = Y;
	direction = dir;
}


//Setter Getter
int bendaHidup::getX() {return x;}
int bendaHidup::getY() {return y;}
string bendaHidup::getDirection() {return direction;}

void bendaHidup::setX(int X) {x = X;}
void bendaHidup::setY(int Y) {y = Y;}
void bendaHidup::setDirection(string d) {direction = d;}