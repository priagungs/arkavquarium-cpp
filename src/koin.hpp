#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef KOIN_HPP
#define KOIN_HPP

class koin : public bendaMati{
	public:
	    //ctor
		koin();
		koin(int);
		//setter getter
		int getNilai();
		void setNilai();

	private:
		int nilai; //Nilai koin
};

#endif
