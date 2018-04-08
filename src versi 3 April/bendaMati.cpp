#include "bendaMati.hpp"
#include "entitas.hpp"
#include <iostream>
using namespace std;

//Ctor
bendaMati::bendaMati() {
	x = 0;
	y = 0;
}
bendaMati::bendaMati(double X, double Y) {
	x = X;
	y = Y;
}

//Setter Getter
double bendaMati::getX() {return x;}
double bendaMati::getY() {return y;}
double bendaMati::getSpeed() {return speed;}
void bendaMati::setX(double X) {x = X;}
void bendaMati::setY(double Y) {y = Y;}


//Prosedur untuk move lurus kebawah
void bendaMati::move(double, double) {
    y += speed;
}
