#ifndef LIST_H
#define LIST_H
#include <iostream>

template<class T>
struct elmt {
	elmt<T>* next;
	T info;
};

template<class T>
class List
{
public:
	elmt<T>* first;	//Pointer ke elemen pertama
	elmt<T>* last;	//Pointer ke elemen terakhir

	//CTOR
	List<T>() {
		first = NULL;
		last = NULL;
	}

	bool isEmpty() { 	//Mengembalikan true jika list kosong
		return (first==NULL && last == NULL);
	}

	//Menambah elemen T ke dalam list
	void add(T info) {
		if(!first) { 	//Kondisi list kosong
			first = new elmt<T>;
			first->info = info;
			first->next = NULL;
			last = first;
		} else { 		//Kondisi list tidak kosong
			if(last == first) { //Satu elemen
				last = new elmt<T>;
				last->info = info;
				last->next = NULL;
				first->next = last;
			} else { 	//Kondisi list memiliki lebih dari satu elemen
				elmt<T>* insinfo = new elmt<T>;
				insinfo->info = info;
				insinfo->next = NULL;
				last->next = insinfo;
				last = insinfo;
			}
		}
	}

    //Menghapus elemen T pada list
    void remove(T element){
		if (first->info == element) {	//elemen ada di elemen pertama
			elmt<T>* del = first;
			if (first-> next != NULL) {	//list memiliki lebih dari satu elemen
				elmt<T>* temp = first->next;
				first->info = first->next->info;
				first->next = first->next->next;
			} else {					//list memiliki satu elemen
				first = NULL;
				last = NULL;
			}
			delete del;
		} else {						//elemen tidak di elemen pertama
			elmt<T>* current = first;
			while (current->next->info != element && current->next != NULL) {
				//Iterasi sampai elemen terakhir atau sampai elemen ditemukan
				current = current->next;
			}
			if (current->next != NULL) { //Jika elemen ditemukan, dihapus dari list
				elmt<T>* del = current;
				current->next = current->next->next;
				delete del;
			}
		}
    }

	T get(int index) {		//Mengembalikan elemen di indeks tertentu
		if(index == 0) {	//Ambil elemen pertama
			return this->first->info;
		} else {			//Mencari elemen dengan indeks yang tepat
			elmt<T>* curr = this->first;
			for(int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->info;
		}
	}

	int find(T element) {				//Mengembalikan indeks terkecil tempat T ditemukan
		if (first->info == element) {	//Kondisi elemen ditemukan di elemen pertama
			return 0;
		} else {
			int counter = 0;			//Mencari elemen yang sesuai
			elmt<T>* current = this->first;
			while (current->next != NULL && current->next->info != element) {
				counter++;
				current = current->next;
			}
			if (current->next != NULL) {
				//Kondisi perulangan berhenti karena elemen ditemukan, mengembalikan indeks
				return counter;
			} else {
				//elemen tidak ditemukan, mengembalikan nilai -1
				return -1;
			}
		}
	}
};

#endif
