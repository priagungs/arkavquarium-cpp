#include "entitas.hpp"
#include <iostream>
using namespace std;

#ifndef BENDAMATI_HPP
#define BENDAMATI_HPP

class bendaMati : public entitas {
//Child class dari kelas entitas
//Berisi method untuk bergerak lurus ke bawah

	public:
	    //Ctor
		bendaMati();
		bendaMati(int, int);
		
		//Setter Getter
		int getX();
		int getY();
		void setX(int X);
		void setY(int Y);

        //Prosedur untuk move lurus kebawah
		void move(int,int);
	protected :
		int x; //Absis entitas
		int y; //Ordinat entitas
};

#endif
