#include "petak.hpp"
#include "List.hpp"
#include "piranha.hpp"
#include "guppy.hpp"
#include "makanan.hpp"
#include "koin.hpp"
#include "siput.hpp"
#include <iostream>

using namespace std;

petak::petak() {}

//getter
List<piranha> petak::getListPiranha() {}
List<guppy> petak::getListGuppy() {}
List<koin> petak::getListKoin() {}
List<makanan> petak::getListMakanan() {}
List<siput> petak::getListSiput() {}

void petak::generateGuppy(guppy g) {//Membuat guppy baru dan menambahkan ke listGuppy
    listGuppy.add(g);
}
void petak::generatePiranha(piranha p) {//Membuat piranha baru dan menambahkan ke listPiranha
	listPiranha.add(p)
}
void petak::generateMakanan(makanan m) {//membuat makanan baru dan menambakan ke listMakanan
	listMakanan.add(m)
}

void petak::updatePetak() {//Menghapus makanan yang sudah dimakan dan ikan mati dari listnya
    updateMakanan();
    updateIkan();
}

void petak::updateMakanan(){
    if(!listMakanan.isEmpty()){
        elmt<makanan>* temp = listMakanan.first;
        do{
            makanan m = temp->info;
            temp = temp->next;
            if(!m.isEdible()){
                listMakanan.remove(m)
            }
        } while(temp != NULL)
    }
}

void petak::updateIkan(){
    if(!listGuppy.isEmpty()){
        elmt<guppy>* temp = listGuppy.first;
        do{
            guppy g = temp->info;
            temp = temp->next;
            if(!g.isMati()){
                listGuppy.remove(g)
            }
        } while(temp != NULL)
    }

    if(!listPiranha.isEmpty()){
        elmt<piranha>* temp = listPiranha.first;
        do{
            piranha p = temp->info;
            temp = temp->next;
            if(!p.isMati()){
                listPiranha.remove(p)
            }
        } while(temp != NULL)
    }
}