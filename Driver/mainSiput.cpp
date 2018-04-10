#include "siput.hpp"
#include <iostream>
using namespace std;

int main(){
	siput s1;
	
	cout << "x : " << s1.getX() << endl;
	cout << "y : " << s1.getY() << endl;
	cout << "direction : " << s1.getDirection() << endl;
	
	s1.moveTowardsTarget(5,5,7);
	
	cout << "x sekarang : " << s1.getX() << endl;
	cout << "y sekarang : " << s1.getY() << endl;
	cout << "direction sekarang : " << s1.getDirection() << endl;
	
	s1.moveTowardsTarget(6,5,7);
	
	cout << "x sekarang : " << s1.getX() << endl;
	cout << "y sekarang : " << s1.getY() << endl;
	cout << "direction sekarang : " << s1.getDirection() << endl;
}