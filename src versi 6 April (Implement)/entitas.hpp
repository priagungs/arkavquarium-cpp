#include <iostream>
using namespace std;

#ifndef ENTITAS_HPP
#define ENTITAS_HPP

class entitas {
//Sebagai Interface untuk entitas-entitas dalam aquarium
//Memiliki pure virtual function move()

	public:
	    //Prosedur untuk bergerak
		virtual void move(int,int)=0;
};

#endif
