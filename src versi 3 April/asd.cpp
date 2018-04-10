#include "List.hpp"
#include <iostream>

using namespace std;
int main() {
  List<int> a;
  a.add(1);
  a.add(2);
  a.add(3);

  elmt<int>* temp = a.first;
  cout << temp->info;
  while (temp->next) {
    temp = temp->next;
    cout << temp->info;
  }

  a.remove(2);

  temp = a.first;
  cout << temp->info;
  while (temp->next) {
    temp = temp->next;
    cout << temp->info;
  }

}
