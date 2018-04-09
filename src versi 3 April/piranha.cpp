#include "piranha.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "guppy.hpp"
#include "List.hpp"
#include "koin.hpp"
#include <iostream>
using namespace std;

piranha::piranha() : ikan(), bendaHidup() {};
piranha::piranha(double X, double Y) : ikan(), bendaHidup(X, Y, 0) {};


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
