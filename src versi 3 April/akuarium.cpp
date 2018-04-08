#include "akuarium.hpp"
#include "oop.hpp"
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

petak akuarium::getPetak(int x, int y) {
	//Mengambil petak dari matriks[x,y]
	return matriks[x][y];
}
//Mengambil suatu list dari suatu petak dari matriks[x,y]
List<makanan> akuarium::getListMakanan(int x, int y) {}
List<guppy> akuarium::getListGuppy(int x, int y) {}
List<piranha> akuarium::getListPiranha(int x, int y) {}
List<koin> akuarium::getListKoin(int x, int y) {}
List<siput> akuarium::getListSiput(int x, int y) {}

//Searcher
//Mengembalikan petak terdekat dari x y yang terdapat makanan
petak akuarium::searchMakanan(int x, int y) {}
//Mengembalikan petak terdekat dari x y yang terdapat Guppy
petak akuarium::searchGuppy(int x, int y) {}
 //Mengembalikan petak terdekat dari x y yang terdapat Koin
petak akuarium::searchKoin(int x, int y) {}
