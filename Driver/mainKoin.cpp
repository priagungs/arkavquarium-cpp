#include "piranha.hpp"
#include <iostream>
using namespace std;

int main(){
	koin k1;
	koin k2(2.5,5.5);
	koin k3(3.2,7,4);
	
	cout << "k1.x : " << k1.getX() << endl;
	cout << "k1.y : " << k1.getY() << endl;
	cout << "nilai k1 : " << k1.getNilai() << endl;
	
	cout << "k2.x : " << k2.getX() << endl;
	cout << "k2.y : " << k2.getY() << endl;
	cout << "nilai k2 : " << k2.getNilai() << endl;
	
	cout << "k3.x : " << k3.getX() << endl;
	cout << "k3.y : " << k3.getY() << endl;
	cout << "nilai k3 : " << k3.getNilai() << endl;
	
	if(k2==k3){
		cout << "k2 sama dengan k3" << endl;
	}
	if(k2!=k3){
		cout << "k2 tidak sama dengan k3" << endl;
	}
	
	k3.setX(k2.getX());
	k3.setY(k2.getY());
	k3.setNilai(k2.getNilai());
	cout << "k3.x sekarang: " << k3.getX() << endl;
	cout << "k3.y sekarang: " << k3.getY() << endl;
	cout << "nilai k3 sekarang: " << k3.getNilai() << endl;
	
	if(k2==k3){
		cout << "k2 sama dengan k3" << endl;
	}
	if(k2!=k3){
		cout << "k2 tidak sama dengan k3" << endl;
	}
}