#include "controller.hpp"
#include "konstanta.hpp"

controller::controller(akuarium a){
    this->a = a;
}

akuarium controller::getAkuarium() {
  return a;
}

void controller::addKoin(double x, double y, double nilai){
    koin k(x,y,nilai);
    a.getListKoin().add(k);
}

void controller::addGuppy(double X, double Y){
    guppy g(X,Y);
    a.getListGuppy().add(g);
}

void controller::addPiranha(){
    piranha p;
    a.getListPiranha().add(p);
}

void controller::addMakanan(double x){
    makanan m(x);
    a.getListMakanan().add(m);
}

void controller::processAkuarium(){
    a.updateAkuarium();
    processPiranha();
    processGuppy();
    processMakanan();
    processSiput();
    processKoin();
}

void controller::processGuppy(){
    if(!a.getListGuppy().isEmpty()){
        elmt<guppy>* temp = a.getListGuppy().first;
        do{
            guppy &g = temp->info;
            temp = temp->next;
            //mencari makan untuk yang sudah lapar
            if(g.getHungerState() && a.makananAvailable()){
                makanan m = a.searchMakanan(g.getX(), g.getY());
                if(abs(m.getX()-g.getX()) < 0.1 && abs(m.getY()-g.getY()) < 0.1){
                    a.getListMakanan().remove(m);
                    g.setFoodCounter(g.getfoodCounter()+1);
                    g.setHunger(GUPPY_HUNGER);
                }
                else{
                    g.moveTowardsTarget(m.getX(), m.getY(),TIMESTAMP_IKAN);
                }
            }else{
            //bergerak random jika tidak lapar
                g.move(TIMESTAMP_IKAN);
            }

            //jika nabrak tembok
            if(g.getX() <= 0 || g.getY() <= 0 || g.getX() >= SCREEN_WIDTH || g.getY() >= SCREEN_HEIGHT){
                g.setDirection(g.getDirection()+M_PI);
            }

            // mengeluarkan koin bagi yang siap mengeluarkan koin
            if(g.getHunger()%PERIODE_KOIN == 0){
                switch(g.getTahap()){
                    case 1: addKoin(g.getX(), g.getY(), g.getTahap()*NILAI_KOIN_TAHAP1);
                    case 2: addKoin(g.getX(), g.getY(), g.getTahap()*NILAI_KOIN_TAHAP2);
                    case 3: addKoin(g.getX(), g.getY(), g.getTahap()*NILAI_KOIN_TAHAP3);
                }
            }
        } while(temp != NULL);
    }
}

void controller::processMakanan() {
    if (!a.getListMakanan().isEmpty()) {
      elmt<makanan>* temp = a.getListMakanan().first;
      do {
        temp->info.move(TIMESTAMP_MAKANAN);
        temp = temp->next;
      } while (temp != NULL);
    }
}

void controller::processKoin(){
    if (!a.getListKoin().isEmpty()) {
      elmt<koin>* temp = a.getListKoin().first;
      do {
        temp->info.move(TIMESTAMP_KOIN);
        temp = temp->next;
      } while (temp != NULL);
    }
}

void controller::processPiranha() {

}
void controller::processSiput(){

}
