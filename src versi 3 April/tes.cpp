#include "List.hpp"
#include <iostream>
using namespace std;
int main(){
    List<int> L;
    L.add(1);
    elmt<int>* temp = L.first;
    while(temp != NULL){
        cout << temp->info << endl;
        temp = temp -> next;
    }
    temp = L.first;
    while(temp != NULL){
        if(temp->info == 1){
            L.remove(1);
            L.remove(1);
        }
        temp = temp -> next;
    }
    temp = L.first;
    while(temp != NULL){
        cout << temp->info << endl;
        temp = temp -> next;
    }

}