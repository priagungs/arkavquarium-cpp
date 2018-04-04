#include "makanan.hpp"
#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;


//Ctor
makanan::makanan(int x) : bendaMati(x,0){
	edible = true;
}
//getter setter
bool makanan::isEdible() {
	return edible;
}
void makanan::setEdible(bool b) {edible = b;}
