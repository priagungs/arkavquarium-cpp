#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef GUPPY_HPP
#define GUPPY_HPP

class guppy : public ikan, public bendaHidup{
//Child class dari kelas ikan dan bendaHidup (multiple inheritance)
//Berisi method untuk makan makanan dan menghasilkan koin

	public:
	    //Ctor
	  	guppy();
		guppy(double, double);
		//Mengubah salah satu isi makanan edible pada list menjadi non edible
		void move(double, double);
		void moveTowardsTarget(double, double);
		const static int speed = 2; //bisa diubah value nya
};

#endif
