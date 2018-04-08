#include "bendaMati.hpp"
#include "entitas.hpp"
#include <iostream>
using namespace std;

//Ctor
bendaMati::bendaMati() : entitas() {
	x = 0;
	y = 0;
}
bendaMati::bendaMati(int X, int Y) {
	x = X;
	y = Y;
}

//Setter Getter
int bendaMati::getX() {return x;}
int bendaMati::getY() {return y;}
void bendaMati::setX(int X) {x = X;}
void bendaMati::setY(int Y) {y = Y;}


//Prosedur untuk move lurus kebawah
void bendaMati::move() {

}
