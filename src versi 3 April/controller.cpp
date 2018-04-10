#include "controller.hpp"
#define NILAI_KOIN_DEFAULT 100
#define PERIODE_KOIN 5

controller::controller(akuarium a){
    this->a = a;
    this->timestamp = 0.01;
}

akuarium controller::getAkuarium() {
  return a;
}

void controller::addKoin(double x, double y, double nilai){
    koin k(x,y,nilai);
    a.getListKoin().add(k);
}

void controller::setTime(double timestamp){
    this->timestamp = timestamp;
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
    // a.updateAkuarium();
    processPiranha();
    processGuppy();
    processMakanan();
    processSiput();
}

void controller::processGuppy(){
    if(!a.getListGuppy().isEmpty()){
        elmt<guppy>* temp = a.getListGuppy().first;
        do{
            guppy &g = temp->info;
            //mencari makan untuk yang sudah lapar
            if(g.getHungerState() && a.makananAvailable()){
                makanan m = a.searchMakanan(g.getX(), g.getY());
                if(abs(m.getX()-g.getX()) < 0.1 && abs(m.getY()-g.getY()) < 0.1){
                    a.getListMakanan().remove(m);
                    g.setFoodCounter(g.getfoodCounter()+1);
                    g.setHunger(1000);
                }
                else{
                    g.moveTowardsTarget(m.getX(), m.getY(),timestamp);
                }
            }else{
            //bergerak random jika tidak lapar
                g.move(timestamp);
            }

            //jika nabrak tembok
            if(g.getX() <= 0 || g.getY() <= 0 || g.getX() >= SCREEN_WIDTH || g.getY() >= SCREEN_HEIGHT){
                g.setDirection(g.getDirection()+M_PI);
            }

            // mengeluarkan koin bagi yang siap mengeluarkan koin
            if(g.getHunger()%PERIODE_KOIN == 0){
                addKoin(g.getX(), g.getY(), g.getTahap()*NILAI_KOIN_DEFAULT);
            }
            g.setHungerState();
            temp = temp->next;

        } while(temp != NULL);
    }
}

void controller::processMakanan() {
    if (!a.getListMakanan().isEmpty()) {
      elmt<makanan>* temp = a.getListMakanan().first;
      do {
        temp->info.move(0.01);
        temp = temp->next;
      } while (temp != NULL);
    }
}

void controller::processPiranha() {

}
void controller::processSiput(){

}
