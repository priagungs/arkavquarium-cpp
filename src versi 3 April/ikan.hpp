#include <iostream>
using namespace std;

#ifndef IKAN_HPP
#define IKAN_HPP

class ikan{
//Berisi hunger, tahap pertumbuhan, jumlah makanan yang dimakan, dan status mati/hidup

	public:
	    //Ctor
		ikan();
		ikan(int, int, int, bool);

		//SetterGetter
		int getHunger();
		int getTahap();
		int getfoodCounter();
		bool isMati();
		void setHunger(int N);
		void setTahap(int N);
		void setFoodCounter(int N);
		void setMati(bool B);
		int moveCounter;

	protected:
		int hunger; //Nilai Kelaparan ikan
		int tahap; //Tahap perkembangan ikan
		int foodCounter; //Jumlah makanan yang pernah dimakan
		bool mati; //Indikasi apakah ikan sudah mati atau tidak
};

#endif
