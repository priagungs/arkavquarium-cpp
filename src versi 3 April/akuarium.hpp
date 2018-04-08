#include "petak.hpp"
#include "List.hpp"
#include "oop.hpp"
#include "piranha.hpp"
#include "guppy.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "siput.hpp"
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
		~akuarium();

		//Mengambil suatu list dari suatu petak dari matriks[x,y]
        List<makanan> getListMakanan();
        List<guppy> getListGuppy();
        List<piranha> getListPiranha();
        List<koin> getListKoin();
        siput getSiput();

		//Searcher
		int searchMakanan(int , int); //Mengembalikan petak terdekat dari x y yang terdapat makanan
		int searchGuppy(int , int );  //Mengembalikan petak terdekat dari x y yang terdapat Guppy
		int searchKoin(int , int ); //Mengembalikan petak terdekat dari x y yang terdapat Koin

		void generateGuppy(double, double); //Membuat guppy baru dan menambahkan ke listGuppy
		void generatePiranha(double, double); //Membuat piranha baru dan menambahkan ke listPiranha
		void generateMakanan(double, double); //membuat makanan baru dan menambakan ke listMakanan

		void updatePetak(); //Menghapus makanan yang sudah dimakan dan ikan mati dari listnya

	private:
		List<guppy> listGuppy;
		List<makanan> listMakanan;
		siput snail;
		List<piranha> listPiranha;
		List<koin> listKoin;
};

#endif
