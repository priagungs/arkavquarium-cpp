#include "akuarium.hpp"
#include "oop.hpp"
#include "petak.hpp"
#include "List.hpp"
#include <iostream>
#include <math.h>
using namespace std;	

akuarium::akuarium(){
	ukuranX = SCREEN_WIDTH;
	ukuranY = SCREEN_HEIGHT;
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
void akuarium::searchMakanan(int x, int y, int& xt, int& yt) {
	if(makananAvailable()){
		elmt<makanan>* temp = listMakanan.first;
		double jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
		xt = temp->info.getX();
		yt = temp->info.getY();
		do{
			temp = temp->next;
			if(jarak > sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2))){
				jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
				xt = temp->info.getX();
				yt = temp->info.getY();
			}
		} while(temp->next != NULL);
	}
}
//Mengembalikan petak terdekat dari x y yang terdapat Guppy
void akuarium::searchGuppy(int x, int y, int& xt, int& yt) {
	if(guppyAvailable()){
		elmt<guppy>* temp = listGuppy.first;
		double jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
		xt = temp->info.getX();
		yt = temp->info.getY();
		do{
			temp = temp->next;
			if(jarak > sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2))){
				jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
				xt = temp->info.getX();
				yt = temp->info.getY();
			}
		} while(temp->next != NULL);
	}
}

 //Mengembalikan petak terdekat dari x y yang terdapat Koin
void akuarium::searchKoin(int x, int y, int& xt, int& yt){ //Mengembalikan petak terdekat dari x y yang terdapat Koin
	if(koinAvailable()){
		elmt<koin>* temp = listKoin.first;
		double jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
		xt = temp->info.getX();
		yt = temp->info.getY();
		do{
			temp = temp->next;
			if(jarak > sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2))){
				jarak = sqrt(pow(x-temp->info.getX(), 2) + pow(y-temp->info.getY(), 2));
				xt = temp->info.getX();
				yt = temp->info.getY();
			}
		} while(temp->next != NULL);
	}	
}

//update status akuarium
void akuarium::updateAkuarium(){
	updateMakanan();
	updatePiranha();
	updateGuppy();
}

void akuarium::updateMakanan(){
    if(!listMakanan.isEmpty()){
        elmt<makanan>* temp = listMakanan.first;
        do{
            makanan m = temp->info;
            temp = temp->next;
            if(!m.isEdible()){
                listMakanan.remove(m);
            }
        } while(temp != NULL);
    }
}

void akuarium::updateGuppy(){
    if(!listGuppy.isEmpty()){
        elmt<guppy>* temp = listGuppy.first;
        do{
            //update status guppy
            guppy g = temp->info;
            g.setHungerState();
            g.decCounter();
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
                listGuppy.remove(g);
            }
        } while(temp != NULL);
    }
}

void akuarium::updatePiranha(){
    if(!listPiranha.isEmpty()){
        elmt<piranha>* temp = listPiranha.first;
        do{
            piranha p = temp->info;
            p.setHungerState();
            p.decCounter();
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
                listPiranha.remove(p);
            }
        } while(temp != NULL);
    }
}