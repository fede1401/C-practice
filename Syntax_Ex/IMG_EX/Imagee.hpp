#ifndef IMAGEE_H
#define IMAGEE_H

#include "Color.hpp"
#include <iostream>

class Imagee{
    
    private:
        int dimX;
        int dimY;
        Color *dataImg;

    public:
        Imagee();    
        Imagee(int dimX, int dimY);

        //Getter and Setter
        int getDimX();
        int getDimY();
        Color* getDataImg();

        void setDimX(int dimX);
        void setDimY(int dimY);
        void setDim(int dimX, int dimY);

        void setDataImg(Color * dataImg);

        void fillImg(Color * pixel);

        void printImg();
};

#endif