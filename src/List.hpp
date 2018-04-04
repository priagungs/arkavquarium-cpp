#ifndef LIST_H
#define LIST_H
#define DEFSIZE 2

template<class Type>
class List{
public:
    //Ctor
    List(){
        elements = new Type[DEFSIZE];
        idxlast = -1;
    }
    //Dtor
    ~List(){
        delete [] elements;
    }
    //CCTOR
    List(const List<Type>& L){
        idxlast = L.idxlast;
        elements = new Type[DEFSIZE];
        for(int i=0; i<=idxlast; i++){
            elements[i] = L.elements[i];
        }
    }
    //Assignment
    List& operator=(const List<Type>& L){
        idxlast = L.idxlast;
        elements = new Type[DEFSIZE];
        for(int i=0; i<=idxlast; i++){
            elements[i] = L.elements[i];
        }
        return *this;
    }
    //Mengembalikan indeks dimana element ditemukan
    int find(Type element){
        for(int i=0; i<=idxlast; i++){
            if(element == elements[i]){
                return i;
            }
        }
        return -1;
    }
    //Mengembalikan true jika list kosong
    bool isEmpty(){
        return idxlast == -1;
    }
    //Menambahkan element pada list
    void add(Type element){
        if(idxlast+1 == DEFSIZE){
            // copy element elements to temporary
            Type* temp = new Type[DEFSIZE];
            for(int i=0; i<=idxlast; i++){
                temp[i] = elements[i];
            }

            // delete old elements
            delete [] elements;

            // create new elements with size 2*size of old elements
            elements = new Type[(idxlast+1)*2];

            // copy everything in temp to new elements
            for(int i=0; i<=idxlast; i++){
                elements[i] = temp[i];
            }

            // delete temp;
            delete [] temp;

            // add new element in the last
            idxlast++;
            elements[idxlast] = element;
        }
        else{
            idxlast++;
            elements[idxlast] = element;
        }
    }
    //Menghapus element pada list
    void remove(Type element){
        int removedIdx;
        for(int i=0; i<=idxlast; i++){
            if(elements[i] == element){
                removedIdx = i;
                break;
            }
        }
        for(int i=removedIdx+1; i<=idxlast; i++){
            elements[i-1] = elements[i];
        }
        idxlast--;
    }

    //Mengambil elemen pada index tertentu
    Type get(int index){
        return elements[index];
    }


private:
    Type* elements; //representasi list sebagai array of Type
    int idxlast; //Indeks array dimana elemen list terakhir
};

#endif
