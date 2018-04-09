#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "guppy.hpp"
#include "List.hpp"
#include "koin.hpp"
#include <iostream>
using namespace std;

#ifndef PIRANHA_HPP
#define PIRANHA_HPP

class piranha : public ikan, public bendaHidup{
//Child class dari kelas ikan dan bendaHidup (multiple inheritance)
//Berisi method untuk makan guppy dan menghasilkan koin

	public:
	    //Ctor
	    piranha();
		piranha(double, double);

		void moveTowardsTarget(double x,double y, double time);
		void move(double time);

	private:
		const static int speed = 20;
};

#endif
