#include "controller.hpp"


controller::controller(akuarium &a){
    this->a = a;
}

void controller::addKoin(double x, double y, double nilai){
    koin k(x,y,nilai);
    a.getPetak(x,y).getListKoin().add(k);
}


void controller::addGuppy(double x, double y){
    guppy g(x,y);
    a.getPetak(x,y).getListGuppy().add(g);
}

void controller::addPiranha(double x, double y){
    piranha p(x,y);
    a.getPetak(x,y).getListPiranha().add(p);
}

void controller::addMakanan(double x){
    makanan m(x);
    a.getPetak(x,0).getListMakanan().add(m);
}

void controller::processGuppy(){
    for(int i=0; i<a.getX(); i++){
        for(int j=0; j<a.getY(); j++){
            if(!a.getListGuppy(i,j).isEmpty()){
               // ceritanya temp isinya element tiap list
               guppy temp;
               if(temp.getHunger() == 0){

               }
            }
        }
    }
}



