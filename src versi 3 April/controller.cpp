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
    // update status semua guppy yang ada
    for(int i=0; i<a.getX(); i++){
        for(int j=0; j<a.getY(); j++){
            if(!a.getListGuppy(i,j).isEmpty()){
                a.getPetak(i,j).updatePetak();
            }
        }
    }

    for(int i=0; i<a.getX(); i++){
        for(int j=0; j<a.getY(); j++){
            if(!a.getListGuppy(i,j).isEmpty()){
                elmt<guppy>* temp = getListGuppy(i,j).first;
                do{
                    guppy g = temp->info;
                    // mencari makan untuk yang sudah lapar
                    if(p.getHungerState()){
                        int x,y;
                        a.searchMakanan(i,j,x,y);
                        g.moveTowardsTarget(x,y);
                    }
                    //bergerak random jika tidak lapar
                    else{
                        
                    }

                    // mengeluarkan koin bagi yang siap mengeluarkan koin


                } while(temp != NULL);
            }
        }
    }
}



