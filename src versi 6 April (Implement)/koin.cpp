#include "koin.hpp"
#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//ctor
koin::koin(int x, int y) : bendaMati(x,y){ 
	nilai = 0;
}
koin::koin(int x, int y, int n) : bendaMati(x,y) {
	nilai = n;
}

//setter getter
int koin::getNilai() {return nilai;}
void koin::setNilai(int n) {nilai = n;}