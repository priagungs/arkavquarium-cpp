#include "akuarium.hpp"
#include <iostream>
using namespace std;

akuarium::akuarium() {
	matriks = new petak*[SCREEN_HEIGHT];
	for (int i=0; i<SCREEN_HEIGHT; ++i) {
        matriks[i] = new petak[SCREEN_WIDTH];
	}
}

akuarium::~akuarium() {
	for (int i = 0; i < SCREEN_HEIGHT; ++i)
        delete [] matriks[i];
    delete [] matriks;
}

//Mengambil suatu list dari suatu petak dari matriks[x,y]
List<makanan> akuarium::getListMakanan(int x, int y) {}
List<guppy> akuarium::getListGuppy(int x, int y) {}
List<piranha> akuarium::getListPiranha(int x, int y) {}
List<koin> akuarium::getListKoin(int x, int y) {}
List<siput> akuarium::getListSiput(int x, int y) {}

//Searcher
//Mengembalikan petak terdekat dari x y yang terdapat makanan
makanan searchMakanan(int , int){} //Mengembalikan petak terdekat dari x y yang terdapat makanan
guppy searchGuppy(int , int ){}  //Mengembalikan petak terdekat dari x y yang terdapat Guppy
koin searchKoin(int , int ){} //Mengembalikan petak terdekat dari x y yang terdapat Koin

void generateGuppy(){} //Membuat guppy baru dan menambahkan ke listGuppy
void generatePiranha(){} //Membuat piranha baru dan menambahkan ke listPiranha
void generateMakanan(){}//membuat makanan baru dan menambakan ke listMakanan

void updatePetak(){} //Menghapus makanan yang sudah dimakan dan ikan mati dari listnya
