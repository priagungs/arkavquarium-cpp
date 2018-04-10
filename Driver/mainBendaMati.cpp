#include "bendaMati.hpp"
#include <iostream>
using namespace std;

int main(){
	bendaMati b1;
	bendaMati b2(5,7);
	
	cout << "b1.x : " << b1.getX() << endl;
	cout << "b1.y : " << b1.getY() << endl;
	cout << "b1.speed : " << b1.getSpeed() << endl;
	
	cout << "b2.x : " << b2.getX() << endl;
	cout << "b2.y : " << b2.getY() << endl;
	cout << "b2.speed : " << b2.getSpeed() << endl;
	
	b1.setX(1.5);
	b1.setY(25);
	
	cout << "b1.x sekarang: " << b1.getX() << endl;
	cout << "b1.y sekarang: " << b1.getY() << endl;
	cout << "b1.speed sekarang: " << b1.getSpeed() << endl;
	
	b1.move(2.1);
	
	cout << "b1.x sekarang: " << b1.getX() << endl;
	cout << "b1.y sekarang: " << b1.getY() << endl;
	cout << "b1.speed sekarang: " << b1.getSpeed() << endl;
}