#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <iostream>

class Buffer{

    public:
        Buffer(int n);
        //Buffer();

        void copyA(Buffer &other);
        void moveA(Buffer &other);

        int getN();
        void setChar(char *arr);
        char* getChar();
        char* getCharAtI(int i);

    private:
        char *arrayC;
        int n;



};

#endif