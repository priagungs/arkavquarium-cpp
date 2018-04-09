#include "makanan.hpp"
#include <iostream>
using namespace std;

makanan::makanan(){}

makanan::makanan(double X) : bendaMati(X,0.0) {
	edible = true;
}

//getter setter
bool makanan::isEdible() {
	return edible;
}

void makanan::setEdible(bool b) {
    edible = b;
}

