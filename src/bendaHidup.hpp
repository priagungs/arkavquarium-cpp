#include "entitas.hpp"
#include <string>
#include <iostream>
using namespace std;

#ifndef BENDAHIDUP_HPP
#define BENDAHIDUP_HPP

class bendaHidup : public entitas {
    public:
        //Ctor
        bendaHidup();

        //Setter Getter
        string getDirection();
        void setDirection(string d);

        //Prosedur untuk bergerak secara acak
        virtual void move();
        //Bergerak menuju x y sebisa mungkin
        //Jika tidak bisa mencapai x y dalam satu kali gerakan, akan bergerak ke titik terdekat dari x y
        //yang bisa dicapai
        void moveTowardsTarget(int x, int y);

    protected:
        string direction; //atribut yang menyimpan kemana bendaHidup menghadap
};

#endif
