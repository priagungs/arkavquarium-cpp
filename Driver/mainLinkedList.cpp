#include "List.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	List<int> list;
	//LinkedList<double> ListDouble(5.3);
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(7);
	list.remove(0);

	int x = list.find(1);
	cout << x;
	int y = list.get(6);
	cout << y;

	list.remove(3);
	list.remove(7);
	
	List<double> l;
	l.add(1.0);
	l.remove(1.0);
	cout << "oink";
	//for(int i=0; i<5; i++) {
	//	cout << List.get(i);
	//}
	
	return 0;
}
