#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.hpp"
#include <string>

class Rectangle: public Shape{
    
private:
    float w;
    float h;

public:
    Rectangle();
    Rectangle(std::string name, float w, float h);

    float area() override;
    std::string getType() override;

};

#endif