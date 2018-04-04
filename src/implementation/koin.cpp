#include "koin.hpp"
#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;

//ctor
koin::koin() { nilai = 0; }
koin::koin(int n) {nilai = n;}
//setter getter
int koin::getNilai() {return nilai;}
void koin::setNilai(int n) {nilai = n;}