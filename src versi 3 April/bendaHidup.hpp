#include "entitas.hpp"
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
		bendaHidup(double,double);

        //Setter Getter
		double getX();
		double getY();
        double getDirection();
		void setX(double X);
		void setY(double Y);
        void setDirection(double d);

        //Prosedur untuk bergerak secara acak
        virtual void move(double time) = 0;

        //Bergerak menuju x y sebisa mungkin
        //Jika tidak bisa mencapai x y dalam satu kali gerakan, akan bergerak ke titik terdekat dari x y
        //yang bisa dicapai
        virtual void moveTowardsTarget(double x, double y, double time) = 0;

    protected:
		double x; //Absis entitas
		double y; //Ordinat entitas
        double direction; //atribut yang menyimpan kemana bendaHidup menghadap
};

#endif
