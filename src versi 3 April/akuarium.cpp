#include "akuarium.hpp"
#include "petak.hpp"
#include "List.hpp"
#include <iostream>
#include <math.h>
using namespace std;	

akuarium::akuarium(){}
	
akuarium::akuarium(int x, int y) {
	ukuranX = x;
	ukuranY = y;
	matriks = new petak*[ukuranY];
	for(int i=0; i<ukuranY; i++){
		matriks[i] = new petak[ukuranX];
	}
}

akuarium::~akuarium() {
	for(int i=0; i<ukuranX; i++){
		delete [] matriks[i];
	}
	delete [] matriks;
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
bool akuarium::koinAvailable(){
	for(int i=0; i<ukuranX; i++){
		for(int j=0; j<ukuranY; j++){
			if(!matriks[j][i].getListKoin().isEmpty()){
				return true;
			}
		}
	}
	return false;
}

bool akuarium::guppyAvailable(){
	for(int i=0; i<ukuranX; i++){
		for(int j=0; j<ukuranY; j++){
			if(!matriks[j][i].getListGuppy().isEmpty()){
				return true;
			}
		}
	}
	return false;
}

bool akuarium::makananAvailable(){
	for(int i=0; i<ukuranX; i++){
		for(int j=0; j<ukuranY; j++){
			if(!matriks[j][i].getListMakanan().isEmpty()){
				return true;
			}
		}
	}
	return false;
}

//Mengembalikan petak terdekat dari x y yang terdapat makanan
petak akuarium::searchMakanan(int x, int y) {
	if(makananAvailable()){
		petak p;
		double jarak = -1;
		for(int i=0; i<ukuranY; i++){
			for(int j=0; j<ukuranX; j++){
				if(!matriks[j][i].getListMakanan().isEmpty()){
					if(jarak == -1 || sqrt(pow(x-i, 2) + pow(y-j, 2)) < jarak){
						jarak = sqrt(pow(x-i, 2) + pow(y-j, 2));
						p = matriks[j][i].getListMakanan();
					}
				}
			}
		}
		return p;
	}
		
	}
}
//Mengembalikan petak terdekat dari x y yang terdapat Guppy
petak akuarium::searchGuppy(int x, int y) {
	if(guppyAvailable()){
		petak p;
		double jarak = -1;
		for(int i=0; i<ukuranX; i++){
			for(int j=0; j<ukuranY; j++){
				if(!matriks[j][i].getListGuppy().isEmpty()){
					if(jarak == -1 || sqrt(pow(x-i, 2) + pow(y-j, 2)) < jarak){
						jarak = sqrt(pow(x-i, 2) + pow(y-j, 2));
						p = matriks[j][i].getListGuppy();
					}
				}
			}
		}
		return p;
	}
}

 //Mengembalikan petak terdekat dari x y yang terdapat Koin
petak akuarium::searchKoin(int x, int y) {
	if(koinAvailable()){
		petak p;
		double jarak = -1;
		for(int i=0; i<ukuranX; i++){
			for(int j=0; j<ukuranY; j++){
				if(!matriks[j][i].getListKoin().isEmpty()){
					if(jarak == -1 || sqrt(pow(x-i, 2) + pow(y-j, 2)) < jarak){
						jarak = sqrt(pow(x-i, 2) + pow(y-j, 2));
						p = matriks[j][i].getListKoin();
					}
				}
			}
		}
		return p;
	}
}
