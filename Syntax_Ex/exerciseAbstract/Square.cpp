#include "Square.hpp"

Square::Square(std::string name, float l){
    this->setName(name);
    this->l = l;
}

float Square::area(){ return (l*l); }

std::string Square::getType(){ return "Square"; }