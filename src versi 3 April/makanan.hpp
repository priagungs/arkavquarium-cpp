#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef MAKANAN_HPP
#define MAKANAN_HPP

class makanan : public bendaMati{
//Child class dari kelas bendaMati
//Berisi atribut edible(yang menyatakan makanan bisa dimakan atau tidak)

	public:
	    //Ctor
		makanan(int x);
		//getter setter
		bool isEdible();
		void setEdible(bool);

    private:
        bool edible; //Untuk menyatakan apakah makanan bisa dimakan atau tidak
};

#endif
