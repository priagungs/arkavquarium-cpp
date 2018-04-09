#include "koin.hpp"
#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//ctor

koin::koin(){}

koin::koin(double x, double y) : bendaMati(x,y){
	nilai = 0;
}
koin::koin(double x, double y, int n) : bendaMati(x,y) {
	nilai = n;
}

//setter getter
int koin::getNilai() {return nilai;}
void koin::setNilai(int n) {nilai = n;}

//Operator overloading

bool koin::operator==(koin k) {
	return (getX() == k.getX() && getY() == k.getY() && getNilai() == k.getNilai());
}
bool koin::operator!=(koin k) {
	return (getX() != k.getX() || getY() != k.getY() || getNilai() != k.getNilai());
}
