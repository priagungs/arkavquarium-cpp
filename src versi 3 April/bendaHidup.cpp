#include "bendaHidup.hpp"
#include "entitas.hpp"
#include "oop.hpp"
#include <string>
#include <iostream>
using namespace std;

//Ctor
bendaHidup::bendaHidup() {
	x = rand()%SCREEN_WIDTH;
	y = rand()%SCREEN_HEIGHT;
	direction = rand()*M_PI*2/double(RAND_MAX);
}

bendaHidup::bendaHidup(double X, double Y) {
	x = X;
	y = Y;
	direction = rand()*M_PI*2/double(RAND_MAX);
}


//Setter Getter
double bendaHidup::getX() {return x;}
double bendaHidup::getY() {return y;}
double bendaHidup::getDirection() {return direction;}

void bendaHidup::setX(double X) {x = X;}
void bendaHidup::setY(double Y) {y = Y;}
void bendaHidup::setDirection(double d) {direction = d;}
