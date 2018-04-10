#include "List.hpp"
#include <iostream>
using namespace std;
int main(){
    List<int> L;
    L.add(1);
    L.add(2);
    L.add(3);
    elmt<int>* temp = L.first;
    while(temp != NULL){
        cout << temp->info << endl;
        temp = temp -> next;
    }
    temp = L.first;
    while(temp != NULL){
        if(temp->info == 2){
            L.remove(2);
        }
        temp = temp -> next;
    }
    temp = L.first;
    while(temp != NULL){
        cout << temp->info << endl;
        temp = temp -> next;
    }

}