#include "bendaMati.hpp"
#include "List.hpp"
#include <iostream>

#ifndef MAKANAN_HPP
#define MAKANAN_HPP

class makanan : public bendaMati{
public:
    makanan();
    makanan(double);
    bool isEdible();
    void setEdible(bool);
private:
    bool edible;
};

#endif
