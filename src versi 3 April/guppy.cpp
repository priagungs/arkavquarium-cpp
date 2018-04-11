#include "guppy.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "konstanta.hpp"
#include "List.hpp"
#include <iostream>
#include <math.h>
#include <ctime>
#include "oop.hpp"
using namespace std;

//Ctor
guppy::guppy() : ikan(), bendaHidup() {
  koinCounter = PERIODE_KOIN;
}

guppy::guppy(double X, double Y) : ikan(), bendaHidup(X, Y) {
  koinCounter = PERIODE_KOIN;
}

void guppy::move(double times){ // gerak arah random selama time
  decCounter();
  if(moveCounter == 1){
      srand((unsigned)time(NULL));
      int x = rand() % 10;
      for (int i = 0; i < x; i++){
        direction = rand()*M_PI*2/double(RAND_MAX) ;
      }
  }
  this->x += speed*cos(direction)*times;
  this->y += speed*sin(direction)*times;
  koinCounter--;
}

void guppy::moveTowardsTarget(double x, double y, double times){ //gerak arah x selama time
    direction = atan2(y-this->y, x-this->x);
    this->x += speed*cos(direction)*times;
    this->y += speed*sin(direction)*times;
    koinCounter--;
}

void guppy::setKoinCounter(int N){
  koinCounter = N;
}
int guppy::getKoinCounter(){
  return koinCounter;
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
