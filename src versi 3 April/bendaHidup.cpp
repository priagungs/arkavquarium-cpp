#include "bendaHidup.hpp"
#include "entitas.hpp"
#include "oop.hpp"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

//Ctor
bendaHidup::bendaHidup() {
	srand(time(NULL));
	x = rand()%(SCREEN_WIDTH-1) +1;
	y = rand()%(SCREEN_HEIGHT-50) + 1;
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
