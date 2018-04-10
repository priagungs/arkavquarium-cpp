#include "List.hpp"
#include <iostream>
using namespace std;
int main(){
    List<int> L;
    L.add(1);
    L.add(1);
    L.add(1);
    while(!L.isEmpty()){
        L.remove(1);
    }
    cout << L.isEmpty();
}