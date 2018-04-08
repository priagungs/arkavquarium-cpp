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
		//Mengubah salah satu isi makanan edible pada list menjadi non edible
		void makan(List<makanan>&);
		//Menambahkan koin baru pada List<koin>
		void generateKoin(List<koin>&);
		void move(int x, int y);
		void moveTowardsTarget(int x, int y);
};

#endif
