#include "entitas.hpp"
#include <iostream>
using namespace std;

#ifndef BENDAMATI_HPP
#define BENDAMATI_HPP

class bendaMati : public entitas {
	public:
	    //Ctor
		bendaMati();

        //Prosedur untuk move lurus kebawah
		void move();
};

#endif
