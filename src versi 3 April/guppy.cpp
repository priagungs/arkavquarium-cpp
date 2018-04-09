#include "guppy.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
#include <math.h>
using namespace std;

//Ctor
guppy::guppy() : ikan(), bendaHidup() {
}

guppy::guppy(double X, double Y) : ikan(), bendaHidup(X, Y) {
}

void guppy::move(double time){ // gerak arah random selama time
    if(moveCounter == 1){
        decCounter();
        direction = rand() % 7;
    }
    this->x += speed*cos(direction)*time;
    this->y += speed*sin(direction)*time;
}

void guppy::moveTowardsTarget(double x, double y, double time){ //gerak arah x selama time
    direction = atan2(y-this->y, x-this->x);
    this->x += speed*cos(direction)*time;
    this->y += speed*sin(direction)*time;
}

bool guppy::operator==(guppy g) {
	return (getX() == g.getX() && getY() == g.getY() 
			&& getDirection() == g.getDirection() 
			&& getHunger() == g.getHunger() 
			&& getTahap() == g.getTahap() 
			&& getfoodCounter() == g.getfoodCounter());
}
bool guppy::operator!=(guppy g) {
	return (getX() != g.getX() || getY() != g.getY() 
			|| getDirection() != g.getDirection() 
			|| getHunger() != g.getHunger() 
			|| getTahap() != g.getTahap() 
			|| getfoodCounter() != g.getfoodCounter());

}

