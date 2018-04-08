#include "guppy.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//Ctor
guppy::guppy() : ikan(), bendaHidup() {
}

guppy::guppy(double X, double Y) : ikan(), bendaHidup(X, Y, 0) {
}

void guppy::move(double X, double Y){
    x += 20;
}
void guppy::moveTowardsTarget(double X, double Y) {
    x += 20;
}
