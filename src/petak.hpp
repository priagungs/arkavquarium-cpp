#include <iostream>
#include "List.hpp"
#include "piranha.hpp"
#include "guppy.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "siput.hpp"

using namespace std;

#ifndef PETAK_HPP
#define PETAK_HPP

class petak {
	public:
	    //ctor
		petak();

		//getter
		List<piranha> getListPiranha();
        List<guppy> getListGuppy();
        List<koin> getListKoin();
        List<makanan> getListMakanan();
        List<siput> getListSiput();

		void generateGuppy(); //Membuat guppy baru dan menambahkan ke listGuppy
		void generatePiranha(); //Membuat piranha baru dan menambahkan ke listPiranha
		void generateMakanan(); //membuat makanan baru dan menambakan ke listMakanan

        void updatePetak(); //Menghapus makanan yang sudah dimakan dan ikan mati dari listnya
    private:
        //List-list dari entitas yang terdapat pada suatu petak
        List<piranha> listPiranha;
        List<guppy> listGuppy;
        List<koin> listKoin;
        List<makanan> listMakanan;
        List<siput> listSiput;
};

#endif
