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
		void move(double time); // gerak arah random selama time
		void moveTowardsTarget(double x, double y, double time); //gerak arah x selama time
		bool operator==(guppy g);
		bool operator!=(guppy g);
	
	private:
		const static int speed = 20; //bisa diubah value nya
};

#endif
