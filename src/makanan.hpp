#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef MAKANAN_HPP
#define MAKANAN_HPP

class makanan : public bendaMati{
	public:
	    //Ctor
		makanan();
		//getter setter
		bool isEdible();
		void setEdible(bool);

    private:
        bool edible; //Untuk
};

#endif
