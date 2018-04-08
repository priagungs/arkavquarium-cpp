#include "akuarium.hpp"
#include "petak.hpp"
#include "List.hpp"
#include <iostream>
#include <math.h>
using namespace std;	

	
akuarium::akuarium(int x, int y) {
	ukuranX = x;
	ukuranY = y;
	matriks = new petak[y][x];
}

akuarium::~akuarium() {
	delete [][] matriks;
}

//Getter
int akuarium::getX() {return ukuranX;}
int akuarium::getY() {return ukuranY;}
petak akuarium::getPetak(int x, int y) {
	//Mengambil petak dari matriks[x,y]
	return matriks[y][x];
}

//Mengambil suatu list dari suatu petak dari matriks[x,y]
List<makanan> akuarium::getListMakanan(int x, int y) {
	return matriks[y][x].getListMakanan();
}
List<guppy> akuarium::getListGuppy(int x, int y) {
	return matriks[y][x].getListGuppy();
}
List<piranha> akuarium::getListPiranha(int x, int y) {
	return matriks[y][x].getListPiranha();
}
List<koin> akuarium::getListKoin(int x, int y) {
	return matriks[y][x].getListKoin();
}
List<siput> akuarium::getListSiput(int x, int y) {
	return matriks[y][x].getListSiput();
}

//Searcher
//Mengembalikan petak terdekat dari x y yang terdapat makanan
petak akuarium::searchMakanan(int x, int y) {
	petak p;
	jarak = -1;
	for(int i=0; i<this->x; i++){
		for(int j=0; j<this->y; j++){
			if(!matriks[j][i].getListMakanan.isEmpty()){
				if(jarak == -1 || sqrt(pow(x-i, 2) + pow(y-j, 2)) < jarak){
					jarak = sqrt(pow(x-i, 2) + pow(y-j, 2));
					p = matriks[j][i].getListMakanan();
				}
			}
		}
	}
	if(jarak != -1){
		return p;
	}
	else{
		return NULL;
	}
}
//Mengembalikan petak terdekat dari x y yang terdapat Guppy
petak akuarium::searchGuppy(int x, int y) {
	petak p;
	jarak = -1;
	for(int i=0; i<this->x; i++){
		for(int j=0; j<this->y; j++){
			if(!matriks[j][i].getListGuppy.isEmpty()){
				if(jarak == -1 || sqrt(pow(x-i, 2) + pow(y-j, 2)) < jarak){
					jarak = sqrt(pow(x-i, 2) + pow(y-j, 2));
					p = matriks[j][i].getListGuppy();
				}
			}
		}
	}
	if(jarak != -1){
		return p;
	}
	else{
		return NULL;
	}
}
 //Mengembalikan petak terdekat dari x y yang terdapat Koin
petak akuarium::searchKoin(int x, int y) {
	petak p;
	jarak = -1;
	for(int i=0; i<this->x; i++){
		for(int j=0; j<this->y; j++){
			if(!matriks[j][i].getListKoin.isEmpty()){
				if(jarak == -1 || sqrt(pow(x-i, 2) + pow(y-j, 2)) < jarak){
					jarak = sqrt(pow(x-i, 2) + pow(y-j, 2));
					p = matriks[j][i].getListKoin();
				}
			}
		}
	}
	if(jarak != -1){
		return p;
	}
	else{
		return NULL;
	}
}
