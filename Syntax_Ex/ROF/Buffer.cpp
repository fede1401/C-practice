#include "Buffer.hpp"

Buffer::Buffer(int n){
    this->n = n;
    this->arrayC = new char[n];
}


void Buffer::copyA(Buffer &other){
    for (int i =0; i<10; i++){
        *(arrayC+i) = other.arrayC[i];
        std::cout << *(arrayC+i) << std::endl;
    }
    return;
}

void Buffer::moveA(Buffer &other){
    for (int i =0; i<10; i++){
        *(arrayC+i) = other.arrayC[i];
        other.arrayC[i] = ' ';
        std::cout << *(arrayC+i) << std::endl;
    }
    return;
}

int Buffer::getN(){
    return this->n;
}

void Buffer::setChar(char *arr){
    this->arrayC = arr;
}

char* Buffer::getChar(){
    return arrayC;
}

char* Buffer::getCharAtI(int i){
    return (arrayC+i);
}


int main(){
    Buffer buff = Buffer(9);
    int n = buff.getN();
    Buffer buff2 = Buffer(n);
    char arr[10] = {'0','1','2','3','4','5','6','7','8', '9'};
    char *arr1 = &arr[0];
    buff2.setChar(arr1);
    buff.copyA(buff2);
    std::cout << buff.getChar() << std::endl;

    std::cout << buff.getCharAtI(4) << std::endl;
}