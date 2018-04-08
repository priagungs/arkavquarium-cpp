#include "akuarium.hpp"
#include <iostream>
using namespace std;

akuarium::akuarium() {
	generateGuppy(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	generateGuppy(SCREEN_HEIGHT/2, SCREEN_HEIGHT/2);

}

akuarium::~akuarium() {

}

//Mengambil suatu list dari suatu petak dari matriks[x,y]
List<makanan> akuarium::getListMakanan(){
    return listMakanan;
}
List<guppy> akuarium::getListGuppy() {
    return listGuppy;
}
List<piranha> akuarium::getListPiranha() {
    return listPiranha;
}
List<koin> akuarium::getListKoin() {
    return listKoin;
}
siput akuarium::getSiput() {
    return snail;
}
//Searcher
//Mengembalikan petak terdekat dari x y yang terdapat makanan
int searchMakanan(int , int){
    return 0;
} //Mengembalikan petak terdekat dari x y yang terdapat makanan
int searchGuppy(int , int ){
    return 0;
}  //Mengembalikan petak terdekat dari x y yang terdapat Guppy
int searchKoin(int , int ){
    return 0;
} //Mengembalikan petak terdekat dari x y yang terdapat Koin

//Membuat guppy baru dan menambahkan ke listGuppy
void akuarium::generateGuppy(double X, double Y){
    listGuppy.add(guppy(X,Y));
}
void akuarium::generatePiranha(double X, double Y){

} //Membuat piranha baru dan menambahkan ke listPiranha
void akuarium::generateMakanan(double X, double Y){

}//membuat makanan baru dan menambakan ke listMakanan

void akuarium::updatePetak(){} //Menghapus makanan yang sudah dimakan dan ikan mati dari listnya
