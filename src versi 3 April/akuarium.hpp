#include "petak.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

#ifndef AKUARIUM_HPP
#define AKUARIUM_HPP

class akuarium {
//Menjalankan kehidupan di ArkavQuarium
//Dibuat sebagai matriks of petak

	public:
	    //Ctor Dtor
		akuarium(int x, int y);
		~akuarium();

		//Getter
		int getX();
		int getY();
		int getGuppyPeriod();
		int getPiranhaPeriod();
		petak getPetak(int x, int y); //Mengambil petak dari matriks[x,y]
		//Mengambil suatu list dari suatu petak dari matriks[x,y]
        List<makanan> getListMakanan(int x, int y);
        List<guppy> getListGuppy(int x, int y);
        List<piranha> getListPiranha(int x, int y);
        List<koin> getListKoin(int x, int y);
        List<siput> getListSiput(int x, int y);

        //Prosedur menjalankan kehidupan di akuarium
        //Mengiterasi semua entitas dari semua petak untuk melakukan aksinya move/eat
        void processAkuarium();

        //prosedur untuk mengenerate posisi (x y) random dan menciptakan entitas pada posisi tersebut
		void randomGuppy();
		void randomPiranha();
		void randomMakanan();

		//Searcher
		petak searchMakanan(int x, int y); //Mengembalikan petak terdekat dari x y yang terdapat makanan
		petak searchGuppy(int x, int y);  //Mengembalikan petak terdekat dari x y yang terdapat Guppy
		petak searchKoin(int x, int y); //Mengembalikan petak terdekat dari x y yang terdapat Koin
	private:
		int ukuranX; //Menyimpan ukuran panjang akuarium
		int ukuranY; //Menyimpan ukuran lebar akuarium
		int guppyPeriod; //Sebagai timer untuk melahirkan guppy baru
		int piranhaPeriod; //Sebagai timer untuk melahirkan piranha baru
		petak** matriks; //Matriks of petak
};

#endif
