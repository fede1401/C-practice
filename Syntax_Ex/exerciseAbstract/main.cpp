#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include <iostream>

int main(){
    Shape *shape1 = new Rectangle("rectangle", 3.0, 4.0);
    Shape *shape2 = new Square("square", 3.0);

    std::cout << "Print area Rect: " << shape1->area() << ", print area Square: " << shape2->area() << std::endl; 

    std::cout << "Type shape1: " << shape1->getType() << ", type shape2: " << shape2->getType() << std::endl;
}