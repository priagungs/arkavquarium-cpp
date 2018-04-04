#include <iostream>
using namespace std;

#ifndef ENTITAS_HPP
#define ENTITAS_HPP

class entitas {
	public:
	    //Prosedur untuk bergerak
		virtual void move()=0;

		//setter getter
		int getX();
		int getY();
		void setX(int X);
		void setY(int Y);

  protected:
    int x; //Absis entitas
    int y; //Ordinat entitas
};

#endif
