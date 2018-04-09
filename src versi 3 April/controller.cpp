#include "controller.hpp"
#define NILAI_KOIN_DEFAULT 100
#define PERIODE_KOIN 5

controller::controller(akuarium a){
    this->a = a;
    this->timestamp = 0;
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
    //a.updateAkuarium();
    processPiranha();
    //processGuppy();
    processMakanan();
    processSiput();
}

void controller::processGuppy(){
    // update status semua guppy yang ada
    if(!a.getListGuppy().isEmpty()){
        elmt<guppy>* temp = a.getListGuppy().first;
        do{
            guppy g = temp->info;
            // mencari makan untuk yang sudah lapar
            if(g.getHungerState()){
                int x,y;
                a.searchMakanan(g.getX(),g.getY(),x,y);
                g.moveTowardsTarget(x,y,timestamp);
            }
            //bergerak random jika tidak lapar
            else{
                g.move(timestamp);
            }

            // mengeluarkan koin bagi yang siap mengeluarkan koin
            if(PERIODE_KOIN%g.getHunger() == 0){
                addKoin(g.getX(), g.getY(), g.getTahap()*NILAI_KOIN_DEFAULT);
            }

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
