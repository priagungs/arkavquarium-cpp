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
	public:
	    //Ctor
		guppy();
		//
		void makan(List<makanan>&);
		//Menambahkan koin baru pada List<koin>
		void generateKoin(List<koin>&);
};

#endif
