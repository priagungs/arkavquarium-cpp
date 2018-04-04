#include "bendaHidup.hpp"
#include "entitas.hpp"
#include <string>
#include <iostream>
using namespace std;

bendaHidup::bendaHidup() {
	direction = "kanan"; //PASTIIN LAGI MAU BAHASA INDO ATAU INGGRIS
}
string bendaHidup::getDirection() {
	return direction;
}
void bendaHidup::setDirection(string d) {
	direction = d;
}