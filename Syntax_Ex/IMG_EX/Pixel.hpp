#ifndef PIXEL_H
#define PIXEL_H

#include "Color.hpp"

class Pixel{
    
    private:
        int x;      // posizione x
        int y;      // posizione y
        Color color;

    public:
        Pixel();
        Pixel(int x, int y, Color color);

        // Getter and Setter
        int getX();
        int getY();
        Color getCol();

        void setX(int x);
        void setY(int y);
        void setColor(Color color);
};


#endif