#include "makanan.hpp"
#include <iostream>
using namespace std;

int main(){
	makanan m1;
	makanan m2(2);
	
	if(m1.isEdible()){
		cout << "m1 edible" << endl;
	}else{
		cout << "m1 tidak edible" << endl;
	}
	if(m2.isEdible()){
		cout << "m2 edible" << endl;
	}else{
		cout << "m2 tidak edible" << endl;
	}
	
	m1.setEdible(false);
	if(m1.isEdible()){
		cout << "m1 masih edible" << endl;
	}else{
		cout << "m1 menjadi tidak edible" << endl;
	}
	
	cout << "m1 mempunyai nilai x " << m1.getX() << endl;
	cout << "m2 mempunyai nilai x " << m2.getX() << endl;
	
	if(m1 != m2){
		cout << "m1 dan m2 tidak sama" << endl;
	}
	if(m1 == m2){
		cout << "m1 dan m2 sama" << endl;
	}
	
	m1.setX(2);
	cout << "sekarang m1 mempunyai nilai x " << m1.getX() << endl;
	
	if(m1 != m2){
		cout << "m1 dan m2 tidak sama" << endl;
	}
	if(m1 == m2){
		cout << "m1 dan m2 sama" << endl;
	}
}