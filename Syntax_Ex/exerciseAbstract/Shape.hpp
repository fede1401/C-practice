#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape{

private:
    std::string name;

public:
    Shape();
    Shape(std::string name);

    virtual std::string getType();

    virtual float area() = 0;
    void setName(std::string name);

};

#endif