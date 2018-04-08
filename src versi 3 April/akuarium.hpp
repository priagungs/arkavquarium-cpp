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
    List<makanan> getListMakanan(int x, int y);
    List<guppy> getListGuppy(int x, int y);
    List<piranha> getListPiranha(int x, int y);
    List<koin> getListKoin(int x, int y);
    List<siput> getListSiput(int x, int y);

		//Searcher
		makanan searchMakanan(int , int); //Mengembalikan petak terdekat dari x y yang terdapat makanan
		guppy searchGuppy(int , int );  //Mengembalikan petak terdekat dari x y yang terdapat Guppy
		koin searchKoin(int , int ); //Mengembalikan petak terdekat dari x y yang terdapat Koin

		void generateGuppy(); //Membuat guppy baru dan menambahkan ke listGuppy
		void generatePiranha(); //Membuat piranha baru dan menambahkan ke listPiranha
		void generateMakanan(); //membuat makanan baru dan menambakan ke listMakanan

		void updatePetak(); //Menghapus makanan yang sudah dimakan dan ikan mati dari listnya

	private:
		List<piranha> listPiranha;
		List<guppy> listGuppy;
		List<koin> listKoin;
		List<makanan> listMakanan;
		List<siput> listSiput;
};

#endif
