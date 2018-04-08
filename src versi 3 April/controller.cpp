#include "controller.hpp"


controller::controller(akuarium a){
    this->a = a;
}

void controller::addKoin(int x, int y, int nilai){
    koin k(x,y,nilai);
    a.getPetak(x,y).getListKoin.add(k);
}


void controller::addGuppy(int x, int y){
    guppy g(x,y);
    a.getPetak(x,y).getListGuppy.add(k);
}

void controller::addPiranha(int x, int y){
    piranha p(x,y);
    a.getPetak(x,y).getListPiranha.add(p);
}

void controller::addMakanan(int x, int y){
    makanan m(x,y);
    a.getPetak(x,y).getListMakanan.add(m);
}

void controller::processGuppy(){
    for(int i=0; i<a.getX(); i++){
        for(int j=0; j<a.getY(); j++){
            if(!a.getListGuppy.isEmpty()){
               // ceritanya temp isinya element tiap list
               guppy temp;
               if(temp.getHunger() == 0){

               }
            }
        }
    }
}



