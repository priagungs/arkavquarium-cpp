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
		akuarium();
		akuarium(int x, int y);
		~akuarium();

		//Getter
		int getX();
		int getY();
		petak& getPetak(int x, int y); //Mengambil petak dari matriks[x,y]
		//Mengambil suatu list dari suatu petak dari matriks[x,y]
        List<makanan>& getListMakanan(int x, int y);
        List<guppy>& getListGuppy(int x, int y);
        List<piranha>& getListPiranha(int x, int y);
        List<koin>& getListKoin(int x, int y);
        List<siput>& getListSiput(int x, int y);

		//Searcher
		bool koinAvailable();
		bool guppyAvailable();
		bool makananAvailable();

		void searchMakanan(int x, int y, int& xt, int& yt); //Mengembalikan petak terdekat dari x y yang terdapat makanan
		void searchGuppy(int x, int y, int& xt, int& yt);  //Mengembalikan petak terdekat dari x y yang terdapat Guppy
		void searchKoin(int x, int y, int& xt, int& yt); //Mengembalikan petak terdekat dari x y yang terdapat Koin
	private:
		int ukuranX; //Menyimpan ukuran panjang akuarium
		int ukuranY; //Menyimpan ukuran lebar akuarium
};

#endif
