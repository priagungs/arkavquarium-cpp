#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef KOIN_HPP
#define KOIN_HPP

class koin : public bendaMati{
//Child class dari kelas bendaMati
//Berisi nilai dari koin

	public:
	    //ctor
		koin();
		koin(double, double);
		koin(double, double, int);
		//setter getter
		int getNilai();
		void setNilai(int n);
		bool operator==(koin k);
		bool operator!=(koin k);

	private:
		int nilai; //Nilai koin
};

#endif
