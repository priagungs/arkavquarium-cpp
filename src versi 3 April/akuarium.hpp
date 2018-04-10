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
		//Mengambil suatu list dari suatu petak dari matriks[x,y]
        List<makanan>& getListMakanan();
        List<guppy>& getListGuppy();
        List<piranha>& getListPiranha();
        List<koin>& getListKoin();
        siput& getSiput();

		//Searcher
		bool koinAvailable();
		bool guppyAvailable();
		bool makananAvailable();

		void generateGuppy(guppy); //Membuat guppy baru dan menambahkan ke listGuppy
		void generatePiranha(piranha); //Membuat piranha baru dan menambahkan ke listPiranha
		void generateMakanan(makanan); //membuat makanan baru dan menambakan ke listMakanan

		makanan searchMakanan(double x, double y); //Mengembalikan makanan terdekat dari x y yang terdapat makanan
		guppy searchGuppy(double x, double y);  //Mengembalikan guppy terdekat dari x y yang terdapat Guppy
		koin searchKoin(double x, double y); //Mengembalikan koin terdekat dari x y yang terdapat Koin
	
		void updateAkuarium();
		void updateMakanan();
		void updatePiranha();
		void updateGuppy();
		// void updateKoin();

	private:
		int ukuranX; //Menyimpan ukuran panjang akuarium
		int ukuranY; //Menyimpan ukuran lebar akuarium
		List<piranha> listPiranha;
		List<guppy> listGuppy;
		List<koin> listKoin;
		List<makanan> listMakanan;
		siput s;
};

#endif
