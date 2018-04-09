#include "petak.hpp"
#include "List.hpp"
#include "piranha.hpp"
#include "guppy.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "siput.hpp"
#include <iostream>

using namespace std;

petak::petak() {}

//getter
List<piranha>& petak::getListPiranha() {}
List<guppy>& petak::getListGuppy() {}
List<koin>& petak::getListKoin() {}
List<makanan>& petak::getListMakanan() {}
List<siput>& petak::getListSiput() {}

void petak::generateGuppy(guppy g) {//Membuat guppy baru dan menambahkan ke listGuppy
    listGuppy.add(g);
}
void petak::generatePiranha(piranha p) {//Membuat piranha baru dan menambahkan ke listPiranha
	listPiranha.add(p)
}
void petak::generateMakanan(makanan m) {//membuat makanan baru dan menambakan ke listMakanan
	listMakanan.add(m)
}

void petak::updatePetak() {//Menghapus makanan yang sudah dimakan dan ikan mati dari listnya
    updateMakanan();
    updateGuppy();
    updatePiranha();
}

void petak::updateMakanan(){
    if(!listMakanan.isEmpty()){
        elmt<makanan>* temp = listMakanan.first;
        do{
            makanan m = temp->info;
            temp = temp->next;
            if(!m.isEdible()){
                listMakanan.remove(m)
            }
        } while(temp != NULL);
    }
}

void petak::updateGuppy(){
    if(!listGuppy.isEmpty()){
        elmt<guppy>* temp = listGuppy.first;
        do{
            //update status guppy
            guppy g = temp->info;
            g.setHungerState();
            g.incCounter();
            if(g.getfoodCounter() == 5){ //bisa diatur
                if(g.getTahap() < 3){
                    g.setFoodCounter(g.getfoodCounter()+1);
                }
            }
            if(g.getHunger() == 0){
                g.setMati(true);
            }
            
            //update eksistensi guppy
            temp = temp->next;
            if(!g.isMati()){
                listGuppy.remove(g)
            }
        } while(temp != NULL);

        //update hunger state

    }
}

void petak::updatePiranha(){
    if(!listPiranha.isEmpty()){
        elmt<piranha>* temp = listPiranha.first;
        do{
            piranha p = temp->info;
            p.setHungerState();
            p.incCounter();
            if(p.getfoodCounter() == 3){ //bisa diatur
                if(p.getTahap() < 3){
                    p.setFoodCounter(p.getfoodCounter()+1);
                }
            }
            if(p.getHunger() == 0){
                p.setMati(true);
            }

            temp = temp->next;
            if(!p.isMati()){
                listPiranha.remove(p)
            }
        } while(temp != NULL);
    }
}