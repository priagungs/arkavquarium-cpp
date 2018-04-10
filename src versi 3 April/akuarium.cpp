#include "akuarium.hpp"
#include "oop.hpp"
#include "petak.hpp"
#include "List.hpp"
#include "konstanta.hpp"
#include <iostream>
#include <math.h>
using namespace std;

akuarium::akuarium(){
	ukuranX = SCREEN_WIDTH;
	ukuranY = SCREEN_HEIGHT;
}

akuarium::akuarium(int x, int y) {
	ukuranX = x;
	ukuranY = y;
}

akuarium::~akuarium() {}

//Getter
int akuarium::getX() {return ukuranX;}
int akuarium::getY() {return ukuranY;}

//Mengambil suatu list dari suatu petak dari matriks[x,y]
List<makanan>& akuarium::getListMakanan() {
	return listMakanan;
}
List<guppy>& akuarium::getListGuppy() {
	return listGuppy;
}
List<piranha>& akuarium::getListPiranha() {
	return listPiranha;
}
List<koin>& akuarium::getListKoin() {
	return listKoin;
}
siput& akuarium::getSiput() {
	return s;
}

//Searcher
bool akuarium::koinAvailable(){
	return !listKoin.isEmpty();
}

bool akuarium::guppyAvailable(){
	return !listGuppy.isEmpty();
}

bool akuarium::makananAvailable(){
	return !listMakanan.isEmpty();
}

//Mengembalikan petak terdekat dari x y yang terdapat makanan
makanan akuarium::searchMakanan(double x, double y) {
	//if(makananAvailable()){
		elmt<makanan>* temp = listMakanan.first;

		makanan m = temp->info;
		double jarak = sqrt(pow(x-m.getX(), 2) + pow(y-m.getY(), 2));

		while (temp->next != NULL) {
			temp = temp->next;
			if(jarak > sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2))){
				jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
				m = temp->info;
			}
		}
		return m;
	//}
}
//Mengembalikan petak terdekat dari x y yang terdapat Guppy
guppy akuarium::searchGuppy(double x, double y) {
	// if(guppyAvailable()){
		elmt<guppy>* temp = listGuppy.first;
		double jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
		guppy g = temp->info;
		do{
			temp = temp->next;
			if(jarak > sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2))){
				jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
				g = temp->info;
			}
		} while(temp->next != NULL);
		return g;
	//}
}

 //Mengembalikan petak terdekat dari x y yang terdapat Koin
koin akuarium::searchKoin(double x, double y){ //Mengembalikan petak terdekat dari x y yang terdapat Koin
	// if(koinAvailable()){
		elmt<koin>* temp = listKoin.first;
		double jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
		koin k = temp->info;
		do{
			temp = temp->next;
			if(jarak > sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2))){
				jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
				k = temp->info;
			}
		} while(temp->next != NULL);
		return k;
	// }
}

//update status akuarium
void akuarium::updateAkuarium(){
	updateMakanan();
	updatePiranha();
	updateGuppy();
	updateKoin();
}

void akuarium::updateMakanan(){
    if(!listMakanan.isEmpty()){
        elmt<makanan>* temp = listMakanan.first;
        do{
            makanan &m = temp->info;
			temp = temp->next;
			if(m.getY() >= SCREEN_HEIGHT && !listMakanan.isEmpty()){
				listMakanan.remove(m);
			}
            // if(!m.isEdible()){
            //     listMakanan.remove(m);
            // }
        } while(temp != NULL);
    }
}

void akuarium::updateGuppy(){
    if(!listGuppy.isEmpty()){
        elmt<guppy>* temp = listGuppy.first;
        do{
            //update status guppy
            guppy &g = temp->info;
			temp = temp->next;
			cout << g.getHungerState();
            g.setHungerState();
            g.decCounter();
            if(g.getfoodCounter() == GUPPY_FOOD_COUNTER_NAIK_TAHAP){ //bisa diatur
                if(g.getTahap() < 3){
                    g.setTahap(g.getTahap()+1);
					g.setFoodCounter(0);
				}
            }
            if(g.getHunger() <= 0){
                g.setMati(true);
            }

            //update eksistensi guppy
            if(g.isMati()){
                listGuppy.remove(g);
            }
        } while(temp != NULL);
    }
}

void akuarium::updatePiranha(){
    if(!listPiranha.isEmpty()){
        elmt<piranha>* temp = listPiranha.first;
        do{
            piranha &p = temp->info;
			temp = temp->next;
            p.setHungerState();
            p.decCounter();
            if(p.getfoodCounter() == PIRANHA_FOOD_COUNTER_NAIK_TAHAP){ //bisa diatur
                if(p.getTahap() < 3){
                    p.setFoodCounter(p.getfoodCounter()+1);
                }
            }
            if(p.getHunger() <= 0){
                p.setMati(true);
            }

            if(p.isMati()){
                listPiranha.remove(p);
            }
        } while(temp != NULL);
    }
}

void akuarium::updateKoin(){
	 if (!listKoin.isEmpty()) {
      elmt<koin>* temp = listKoin.first;
      do {
		koin &k = temp->info;
		temp = temp->next;
        if(k.getY() >= SCREEN_HEIGHT && !listKoin.isEmpty()){
			listKoin.remove(k);	
		}
      } while (temp != NULL);
    }
}
