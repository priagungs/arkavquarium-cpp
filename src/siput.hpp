#include "bendaHidup.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef SIPUT_HPP
#define SIPUT_HPP

class siput : public bendaHidup{
	public:
	    //Ctor
		siput();

		//Overide moveTowardsTarget (Kecepatan berbeda dari bendaHidup lain)
        void moveTowardsTarget(int x, int y);
};

#endif
