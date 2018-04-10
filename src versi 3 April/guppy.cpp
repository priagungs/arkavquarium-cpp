#include "guppy.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
#include <math.h>
#include <ctime>
#include "oop.hpp"
using namespace std;

//Ctor
guppy::guppy() : ikan(), bendaHidup(0,0) {
}

guppy::guppy(double X, double Y) : ikan(), bendaHidup(X, Y) {
}

void guppy::move(double times){ // gerak arah random selama time
  decCounter();
  if(moveCounter == 1){
      direction = rand()*M_PI*2/double(RAND_MAX) ;
  }
  this->x += speed*cos(direction* 3.14159265 / 180.0)*times;
  this->y += speed*sin(direction* 3.14159265 / 180.0)*times;
}

void guppy::moveTowardsTarget(double x, double y, double times){ //gerak arah x selama time
    direction = atan2(y-this->y, x-this->x);
    this->x += speed*cos(direction)*times;
    this->y += speed*sin(direction)*times;
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
