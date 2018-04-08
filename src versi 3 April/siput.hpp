#include "bendaHidup.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef SIPUT_HPP
#define SIPUT_HPP

class siput : public bendaHidup{
//Child class dari kelas bendaHidup
//Berisi method Override moveTowardsTarget

	public:
	    //Ctor
		siput();

		//Override moveTowardsTarget (Kecepatan berbeda dari bendaHidup lain)
		void move(double,double);
        void moveTowardsTarget(double, double);
};

#endif
