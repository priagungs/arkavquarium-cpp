#include "ikan.hpp"
#include <iostream>
using namespace std;

int main() {
	
	ikan I1;
	cout << "Hunger = " << I1.getHunger() << endl;
	cout << "Tahap = " << I1.getTahap() << endl;
	cout << "Food Counter = " << I1.getfoodCounter() << endl;
	cout << "Hunger State = " << I1.getHungerState() << endl <<endl;
	
	I1.setHunger(2);
	I1.setTahap(2);
	I1.setFoodCounter(30);
	I1.setHungerState();
	
	cout << "State I1 menjadi : " << endl;
	cout << "Hunger = " << I1.getHunger() << endl;
	cout << "Tahap = " << I1.getTahap() << endl;
	cout << "Food Counter = " << I1.getfoodCounter() << endl;
	cout << "Hunger State = " << I1.getHungerState() << endl <<endl;
		
	return 0;
}