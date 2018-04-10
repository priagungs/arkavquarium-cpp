#include "guppy.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include <iostream>
using namespace std;

int main() {
	
	//Mengetes default ctor
	guppy g1;
	cout << "guppy g1 berhasil dibuat." << endl;
	
	//Mengetes ctor dengan parameter
	guppy g2(2.5, -5.3);
	cout << "guppy g2 berhasil dibuat dengan x,y = (" << g2.getX() << "," << g2.getY() << ")"<< endl;
	cout << "g2 memiliki direction = " << g2.getDirection() << endl;
	cout << "g2 memiliki hunger = " << g2.getHunger() << endl;
	cout << "g2 memiliki tahap = " << g2.getTahap() << endl;
	cout << "g2 memiliki foodCounter = " << g2.getfoodCounter() << endl;
	cout << "g2 memiliki hunger state = " << g2.getHungerState() << endl;
	if (g2.isMati()) {
		cout << "g2 Hidup" << endl;
	} else {
		cout << "g2 Mati" << endl;
	}
	cout<< endl;

	guppy g3(5.4, 1.2);
	cout << "guppy g3 berhasil dibuat dengan x,y = (" << g3.getX() << "," << g3.getY() << ")"<< endl;
	cout << "g3 memiliki direction = " << g3.getDirection() << endl;
	cout << "g3 memiliki hunger = " << g3.getHunger() << endl;
	cout << "g3 memiliki tahap = " << g3.getTahap() << endl;
	cout << "g3 memiliki foodCounter = " << g3.getfoodCounter() << endl;
	cout << "g3 memiliki hunger state = " << g3.getHungerState() << endl;
	if (g3.isMati()) {
		cout << "g3 Hidup" << endl;
	} else {
		cout << "g3 Mati" << endl;
	}
	cout<< endl;


	guppy g4(5.4, 1.2);
	cout << "guppy g4 berhasil dibuat dengan x,y = (" << g4.getX() << "," << g4.getY() << ")" << endl;
	cout << "g4 memiliki direction = " << g4.getDirection() << endl;
	cout << "g4 memiliki hunger = " << g4.getHunger() << endl;
	cout << "g4 memiliki tahap = " << g4.getTahap() << endl;
	cout << "g4 memiliki foodCounter = " << g4.getfoodCounter() << endl;
	cout << "g4 memiliki hunger state = " << g4.getHungerState() << endl;
	if (g4.isMati()) {
		cout << "g4 Hidup" << endl;
	} else {
		cout << "g4 Mati" << endl;
	}
	cout<< endl;

	g1.setHunger(g3.getHunger());
	g1.setTahap(g3.getTahap());
	g1.setFoodCounter(g3.getfoodCounter());
	g1.setMati(g3.isMati());
	g1.setHungerState();
	g1.setX(g3.getX());
	g1.setY(g3.getY());
	g1.setDirection(g3.getDirection());
	cout << "guppy g1 berhasil diubah dengan x,y = (" << g1.getX() << "," << g1.getY() << ")" << endl;
	cout << "g1 memiliki direction = " << g1.getDirection() << endl;
	cout << "g1 memiliki hunger = " << g1.getHunger() << endl;
	cout << "g1 memiliki tahap = " << g1.getTahap() << endl;
	cout << "g1 memiliki foodCounter = " << g1.getfoodCounter() << endl;
	cout << "g1 memiliki hunger state = " << g1.getHungerState() << endl;
	if (g1.isMati()) {
		cout << "g1 Hidup" << endl;
	} else {
		cout << "g1 Mati" << endl;
	}
	cout<< endl;
	
	//Mengetes operator overloading ==
	if (g1==g2) {
		cout << "g1 sama dengan g2" <<endl;
	} else {
		cout << "g1 berbeda dengan g2" << endl;
	}
	if (g1==g3) {
		cout << "g1 sama dengan g3" << endl; 
	} else {
		cout << "g1 berbeda dengan g3" << endl;
	}
	
	//Mengetes operator overloading !=
	if (g1!=g2) {
		cout << "g1 berbeda dengan g2" <<endl;
	} else {
		cout << "g1 sama dengan g2" << endl;
	}
	if (g4!=g3) {
		cout << "g4 berbeda dengan g3" << endl; 
	} else {
		cout << "g4 sama dengan g3" << endl;
	}
	
	cout<<endl;

	//Mengetes move
	g1.move(10);
	cout << "Move berhasil, status g1 : x,y = (" << g1.getX() << "," << g1.getY() << ")" << endl;
	cout << "g1 memiliki direction = " << g1.getDirection() << endl;
	cout << "g1 memiliki hunger = " << g1.getHunger() << endl;
	cout << "g1 memiliki tahap = " << g1.getTahap() << endl;
	cout << "g1 memiliki foodCounter = " << g1.getfoodCounter() << endl;
	cout << "g1 memiliki hunger state = " << g1.getHungerState() << endl;
	if (g1.isMati()) {
		cout << "g1 Hidup" << endl;
	} else {
		cout << "g1 Mati" << endl;
	}
	cout<< endl;
	
	//Mengetes moveTowardsTarget
	g2.moveTowardsTarget(-2.1, -7.6, 10);
	g2.move(10);
	cout << "MoveTowardsTarget berhasil, status g2 : x,y = (" << g2.getX() << "," << g2.getY() << ")" << endl;
	cout << "g2 memiliki direction = " << g2.getDirection() << endl;
	cout << "g2 memiliki hunger = " << g2.getHunger() << endl;
	cout << "g2 memiliki tahap = " << g2.getTahap() << endl;
	cout << "g2 memiliki foodCounter = " << g2.getfoodCounter() << endl;
	cout << "g2 memiliki hunger state = " << g2.getHungerState() << endl;
	if (g2.isMati()) {
		cout << "g2 Hidup" << endl;
	} else {
		cout << "g2 Mati" << endl;
	}
	cout<< endl;	
	

	return 0;
}
