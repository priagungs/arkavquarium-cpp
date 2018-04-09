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
		bendaMati(double, double);

		//Setter Getter
		double getX();
		double getY();
		double getSpeed();
		void setX(double X);
		void setY(double Y);


        //Prosedur untuk move lurus kebawah
		void move(double,double);
	protected :
		double x; //Absis entitas
		double y; //Ordinat entitas
		static const double speed = 50;
};

#endif
