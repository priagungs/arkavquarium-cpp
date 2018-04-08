#include "piranha.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "guppy.hpp"
#include "List.hpp"
#include "koin.hpp"
#include <iostream>
using namespace std;

piranha::piranha() : ikan(), bendaHidup() {};
piranha::piranha(double X, double Y) : ikan(), bendaHidup(X, Y, 0) {};


void piranha::move(double,double) {

}
void piranha::moveTowardsTarget(double x, double y) {

}

void piranha::makan(List<guppy>&) { //Membuat salah satu guppy hidup pada list menjadi mati

}
void piranha::generateKoin(List<koin>&) {//Membuat koin baru dan menambahkannya ke List<koin>

}
