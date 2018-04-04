#include "akuarium.hpp"
#include "petak.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;	

	
akuarium::akuarium(int x, int y) {
	ukuranX = x;
	ukuranY = y;
	guppyPeriod = 0;
	piranhaPeriod = 0;
	#matriks = new petak[y][x];
}

akuarium::~akuarium() {
	delete [][] matriks;
}

//Getter
int akuarium::getX() {return ukuranX;}
int akuarium::getY() {return ukuranY;}
int akuarium::getGuppyPeriod() {return guppyPeriod;}
int akuarium::getPiranhaPeriod() {return piranhaPeriod;}
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

//Prosedur menjalankan kehidupan di akuarium
//Mengiterasi semua entitas dari semua petak untuk melakukan aksinya move/eat
void akuarium::processAkuarium() {}

//prosedur untuk mengenerate posisi (x y) random dan menciptakan entitas pada posisi tersebut
void akuarium::randomGuppy() {}
void akuarium::randomPiranha() {}
void akuarium::randomMakanan() {}

//Searcher
//Mengembalikan petak terdekat dari x y yang terdapat makanan
petak akuarium::searchMakanan(int x, int y) {}
//Mengembalikan petak terdekat dari x y yang terdapat Guppy
petak akuarium::searchGuppy(int x, int y) {}
 //Mengembalikan petak terdekat dari x y yang terdapat Koin
petak akuarium::searchKoin(int x, int y) {}
