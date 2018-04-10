#include "piranha.hpp"
#include "ikan.hpp"
#include "bendaHidup.hpp"
#include <iostream>
using namespace std;

int main() {
	
	//Mengetes default ctor
	piranha p1;
	cout << "Piranha p1 berhasil dibuat." << endl;
	
	//Mengetes ctor dengan parameter
	piranha p2(2.5, -5.3);
	cout << "Piranha p2 berhasil dibuat dengan x,y = (" << p2.getX() << "," << p2.getY() << ")"<< endl;
	cout << "P2 memiliki direction = " << p2.getDirection() << endl;
	cout << "P2 memiliki hunger = " << p2.getHunger() << endl;
	cout << "P2 memiliki tahap = " << p2.getTahap() << endl;
	cout << "P2 memiliki foodCounter = " << p2.getfoodCounter() << endl;
	cout << "P2 memiliki hunger state = " << p2.getHungerState() << endl;
	if (p2.isMati()) {
		cout << "P2 Hidup" << endl;
	} else {
		cout << "P2 Mati" << endl;
	}
	cout<< endl;

	piranha p3(5.4, 1.2);
	cout << "Piranha p3 berhasil dibuat dengan x,y = (" << p3.getX() << "," << p3.getY() << ")"<< endl;
	cout << "P3 memiliki direction = " << p3.getDirection() << endl;
	cout << "P3 memiliki hunger = " << p3.getHunger() << endl;
	cout << "P3 memiliki tahap = " << p3.getTahap() << endl;
	cout << "P3 memiliki foodCounter = " << p3.getfoodCounter() << endl;
	cout << "P3 memiliki hunger state = " << p3.getHungerState() << endl;
	if (p3.isMati()) {
		cout << "P3 Hidup" << endl;
	} else {
		cout << "P3 Mati" << endl;
	}
	cout<< endl;


	piranha p4(5.4, 1.2);
	cout << "Piranha p4 berhasil dibuat dengan x,y = (" << p4.getX() << "," << p4.getY() << ")" << endl;
	cout << "P4 memiliki direction = " << p4.getDirection() << endl;
	cout << "P4 memiliki hunger = " << p4.getHunger() << endl;
	cout << "P4 memiliki tahap = " << p4.getTahap() << endl;
	cout << "P4 memiliki foodCounter = " << p4.getfoodCounter() << endl;
	cout << "P4 memiliki hunger state = " << p4.getHungerState() << endl;
	if (p4.isMati()) {
		cout << "P4 Hidup" << endl;
	} else {
		cout << "P4 Mati" << endl;
	}
	cout<< endl;

	p1.setHunger(p3.getHunger());
	p1.setTahap(p3.getTahap());
	p1.setFoodCounter(p3.getfoodCounter());
	p1.setMati(p3.isMati());
	p1.setHungerState();
	p1.setX(p3.getX());
	p1.setY(p3.getY());
	p1.setDirection(p3.getDirection());
	cout << "Piranha p1 berhasil diubah dengan x,y = (" << p1.getX() << "," << p1.getY() << ")" << endl;
	cout << "P1 memiliki direction = " << p1.getDirection() << endl;
	cout << "P1 memiliki hunger = " << p1.getHunger() << endl;
	cout << "P1 memiliki tahap = " << p1.getTahap() << endl;
	cout << "P1 memiliki foodCounter = " << p1.getfoodCounter() << endl;
	cout << "P1 memiliki hunger state = " << p1.getHungerState() << endl;
	if (p1.isMati()) {
		cout << "P1 Hidup" << endl;
	} else {
		cout << "P1 Mati" << endl;
	}
	cout<< endl;
	
	//Mengetes operator overloading ==
	if (p1==p2) {
		cout << "p1 sama dengan p2" <<endl;
	} else {
		cout << "p1 berbeda dengan p2" << endl;
	}
	if (p1==p3) {
		cout << "p1 sama dengan p3" << endl; 
	} else {
		cout << "p1 berbeda dengan p3" << endl;
	}
	
	//Mengetes operator overloading !=
	if (p1!=p2) {
		cout << "p1 berbeda dengan p2" <<endl;
	} else {
		cout << "p1 sama dengan p2" << endl;
	}
	if (p4!=p3) {
		cout << "p4 berbeda dengan p3" << endl; 
	} else {
		cout << "p4 sama dengan p3" << endl;
	}
	
	cout<<endl;

	//Mengetes move
	p1.move(10);
	cout << "Move berhasil, status p1 : x,y = (" << p1.getX() << "," << p1.getY() << ")" << endl;
	cout << "P1 memiliki direction = " << p1.getDirection() << endl;
	cout << "P1 memiliki hunger = " << p1.getHunger() << endl;
	cout << "P1 memiliki tahap = " << p1.getTahap() << endl;
	cout << "P1 memiliki foodCounter = " << p1.getfoodCounter() << endl;
	cout << "P1 memiliki hunger state = " << p1.getHungerState() << endl;
	if (p1.isMati()) {
		cout << "P1 Hidup" << endl;
	} else {
		cout << "P1 Mati" << endl;
	}
	cout<< endl;
	
	//Mengetes moveTowardsTarget
	p2.moveTowardsTarget(-2.1, -7.6, 10);
	p2.move(10);
	cout << "MoveTowardsTarget berhasil, status p2 : x,y = (" << p2.getX() << "," << p2.getY() << ")" << endl;
	cout << "P2 memiliki direction = " << p2.getDirection() << endl;
	cout << "P2 memiliki hunger = " << p2.getHunger() << endl;
	cout << "P2 memiliki tahap = " << p2.getTahap() << endl;
	cout << "P2 memiliki foodCounter = " << p2.getfoodCounter() << endl;
	cout << "P2 memiliki hunger state = " << p2.getHungerState() << endl;
	if (p2.isMati()) {
		cout << "P2 Hidup" << endl;
	} else {
		cout << "P2 Mati" << endl;
	}
	cout<< endl;	
	

	return 0;
}
