#include "List.hpp"
#include "akuarium.hpp"
#include "piranha.hpp"
#include "guppy.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "siput.hpp"
#include "oop.hpp"
#include "time.h"
#include <cmath>

#ifndef CONTROLLER_H
#define CONTROLLER_H

class controller{
public:
	int uang;
	int levelTelur;
    //Mengiterasi semua entitas dari semua petak untuk melakukan aksinya move/eat
    controller(akuarium);
    void processAkuarium();

    akuarium getAkuarium();

    void processGuppy();
    void processPiranha();
    void processMakanan();
    void processSiput();
    void processKoin();

    void addKoin(double,double,double);
    void addGuppy();
    void addPiranha();
    void addMakanan(double);

    void setTime(double);
private:
    akuarium a;
};

#endif
