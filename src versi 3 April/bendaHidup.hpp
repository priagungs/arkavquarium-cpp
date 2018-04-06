#include "entitas.hpp"
#include <string>
#include <iostream>
using namespace std;

#ifndef BENDAHIDUP_HPP
#define BENDAHIDUP_HPP

class bendaHidup : public entitas {
//Child class dari kelas entitas
//Berisi arah hadapan dan method untuk bergerak benda hidup

    public:
        //Ctor
        bendaHidup();
		bendaHidup(int,int,string);

        //Setter Getter
		int getX();
		int getY();
        string getDirection();
		void setX(int X);
		void setY(int Y);
        void setDirection(string d);

        //Prosedur untuk bergerak secara acak
        virtual void move() = 0;
        //Bergerak menuju x y sebisa mungkin
        //Jika tidak bisa mencapai x y dalam satu kali gerakan, akan bergerak ke titik terdekat dari x y
        //yang bisa dicapai
        virtual void moveTowardsTarget(int x, int y) = 0;

    protected:
		int x; //Absis entitas
		int y; //Ordinat entitas
        double direction; //atribut yang menyimpan kemana bendaHidup menghadap
};

#endif
