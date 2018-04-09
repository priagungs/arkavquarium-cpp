#include "List.hpp"
#include "akuarium.hpp"
#include "piranha.hpp"
#include "guppy.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "siput.hpp"

#ifndef CONTROLLER_H
#define CONTROLER_H

class controller{
public:
    //Mengiterasi semua entitas dari semua petak untuk melakukan aksinya move/eat
    controller(akuarium&);
    void processAkuarium();

    void processGuppy();
    void processPiranha();
    void processMakanan();
    void processSiput();

    void addKoin(double,double,double);
    void addGuppy();
    void addPiranha();
    void addMakanan(double);

    void setTime(double time);
private:
    akuarium a;
    double timestamp;
};

#endif
