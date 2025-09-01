#include "Rectangle.hpp"

Rectangle::Rectangle(){}

Rectangle::Rectangle(std::string name, float w, float h){
    this->setName(name);
    this->w =w;
    this->h = h;
}

float Rectangle::area(){ return (w*h); }

std::string Rectangle::getType(){ return "Rectangle"; }