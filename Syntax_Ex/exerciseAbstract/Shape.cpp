#include "Shape.hpp"

Shape::Shape(){}

Shape::Shape(std::string name){ this->name = name; }

void Shape::setName(std::string name){ this->name = name; }

std::string Shape::getType(){ return "Generic Shape"; }