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
	elmt<T>* first;
	elmt<T>* last;
	List<T>() {
		first = NULL;
		last = NULL;
	}

	bool isEmpty() {
		return (first==NULL && last == NULL);
	}

	void add(T info) {
		if(!first) {
			// The list is empty
			first = new elmt<T>;
			first->info = info;
			first->next = NULL;
			last = first;
		} else {
			// The list isn't empty
			if(last == first) {
				// The list has one element
				last = new elmt<T>;
				last->info = info;
				last->next = NULL;
				first->next = last;
			} else {
				// The list has more than one element
				elmt<T>* insinfo = new elmt<T>;
				insinfo->info = info;
				insinfo->next = NULL;
				last->next = insinfo;
				last = insinfo;
			}
		}
	}

    //Menghapus element pada list
    void remove(T element){
		if (first->info == element) {
			elmt<T>* del = first;
			if (first-> next != NULL) {
				elmt<T>* temp = first->next;
				first->info = first->next->info;
				first->next = first->next->next;
			} else {
				first = NULL;
				last = NULL;
			}
			delete del;
		} else {
			elmt<T>* current = first;
			while (current->next->info != element && current->next != NULL) {
				current = current->next;
			}
			if (current->next != NULL) {
				elmt<T>* del = current;
				current->next = current->next->next;
				delete del;
			}
		}
    }

	T get(int index) {
		if(index == 0) {
			// Get the first element
			return this->first->info;
		} else {
			// Get the index'th element
			elmt<T>* curr = this->first;
			for(int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->info;
		}
	}

	int find(T element) {
		if (first->info == element) {
			return 0;
		} else {
			int counter = 0;
			elmt<T>* current = this->first;
			while (current->next != NULL && current->next->info != element) {
				counter++;
				current = current->next;
			}
			if (current->next != NULL) {
				return counter;
			} else {
				return -1;
			}
		}
	}
};

#endif // LIST_H
