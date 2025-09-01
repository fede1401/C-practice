#include "Color.hpp"

Color::Color(){};

Color::Color(float red, float green, float blue){
    this->red = red;
    this->green = green;
    this->blue = blue;
}

float Color::getRed(){ return red; }

float Color::getGreen(){ return green; }

float Color::getBlue(){ return blue; }

void Color::setRed(float red){ this->red = red; }

void Color::setGreen(float green){ this->green = green; }

void Color::setBlue(float blue){ this->blue = blue;  }
