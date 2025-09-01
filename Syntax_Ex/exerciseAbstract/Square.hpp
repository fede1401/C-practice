#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.hpp"
#include <string>

class Square: public Shape{
    
private:
    float l;

public:
    Square(std::string name, float l);

    float area() override;
    std::string getType() override;
};

#endif