#include "Imagee.hpp"

using namespace std;

Imagee::Imagee(){}

Imagee::Imagee(int dimX, int dimY){
    this->dimX = dimX;
    this->dimY = dimY;
    this->dataImg = new Color[dimX * dimY];
}

int Imagee::getDimX(){ return dimX; }

int Imagee::getDimY(){ return dimY; }

Color * Imagee::getDataImg(){ return dataImg; }


void Imagee::setDimX(int dimX){ this->dimX = dimX; }

void Imagee::setDimY(int dimY){ this->dimY = dimY;  }

void Imagee::setDim(int dimX, int dimY){
    this->dimX = dimX;
    this->dimY = dimY;
}

void Imagee::setDataImg(Color * dataImg){ this->dataImg = dataImg; }

void Imagee::fillImg(Color *pixel){
    for (int i = 0; i < dimX * dimY; i++) {
        dataImg[i] = pixel[i];
    }
}

void Imagee::printImg(){
    cout << "Print img" << endl;
    for (int i = 0; i < dimX; i++) {
        for (int j = 0; j < dimY; j++) {
            int index = i * dimY + j;
            Color c = dataImg[index];
            std::cout << "[" << i << ", " << j << "] --> ("
                      << c.getRed() << ", "
                      << c.getGreen() << ", "
                      << c.getBlue() << ")" << std::endl;
        }
    }
}