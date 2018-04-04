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

		void makan(List<guppy>&); //Membuat salah satu guppy hidup pada list menjadi mati
		void generateKoin(List<koin>&); //Membuat koin baru dan menambahkannya ke List<koin>
};

#endif
