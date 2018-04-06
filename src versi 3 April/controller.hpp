#ifndef CONTROLLER_H
#define CONTROLER_H

#include "List.hpp"
#include "akuarium.hpp"

class controller{
public:
    //Mengiterasi semua entitas dari semua petak untuk melakukan aksinya move/eat
    void processAkuarium(akuarium a);

    //prosedur untuk mengenerate posisi (x y) random dan menciptakan entitas pada posisi tersebut
    void randomGuppy(akuarium a);
    void randomPiranha(akuarium a);
    void randomMakanan(akuarium a);
    int getGuppyPeriod();
    int getPiranhaPeriod();
private:
    int guppyPeriod; //Sebagai timer untuk melahirkan guppy baru
    int piranhaPeriod; //Sebagai timer untuk melahirkan piranha baru
};

#endif