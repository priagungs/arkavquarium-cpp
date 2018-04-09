#include "piranha.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "piranha.hpp"
#include "List.hpp"
#include "koin.hpp"
#include <iostream>
#include <math.h>
using namespace std;

piranha::piranha() : ikan(), bendaHidup() {};
piranha::piranha(double X, double Y) : ikan(), bendaHidup(X, Y) {};


void piranha::move(double time){ // gerak arah random selama time
    if(moveCounter == 1){
        decCounter();
        direction = rand() % 7;
    }
    this->x += speed*cos(direction)*time;
    this->y += speed*sin(direction)*time;
}

void piranha::moveTowardsTarget(double x, double y, double time){ //gerak arah x selama time
    direction = atan2(y-this->y, x-this->x);
    this->x += speed*cos(direction)*time;
    this->y += speed*sin(direction)*time;
}

bool piranha::operator==(piranha p) {
	return (getX() == p.getX() && getY() == p.getY() 
			&& getDirection() == p.getDirection() 
			&& getHunger() == p.getHunger() 
			&& getTahap() == p.getTahap() 
			&& getfoodCounter() == p.getfoodCounter());
}
bool piranha::operator!=(piranha p) {
	return (getX() != p.getX() || getY() != p.getY() 
			|| getDirection() != p.getDirection() 
			|| getHunger() != p.getHunger() 
			|| getTahap() != p.getTahap() 
			|| getfoodCounter() != p.getfoodCounter());

}

