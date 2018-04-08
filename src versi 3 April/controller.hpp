#include "List.hpp"
#include "akuarium.hpp"

#ifndef CONTROLLER_H
#define CONTROLER_H

class controller{
public:
    //Mengiterasi semua entitas dari semua petak untuk melakukan aksinya move/eat
    controller();
    void processAkuarium();

    void processGuppy();
    void processPiranha();
    void processMakanan();
    void processSiput();

    void addKoin(int,int);
    void addGuppy(int,int);
    void addPiranha(int,int);
    void addMakanan(int,int);

    akuarium tank;
};

#endif
