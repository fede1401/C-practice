#ifndef COLOR_H
#define COLOR_H

class Color{

    private:
        float red;
        float green;
        float blue;
    
    public:
        Color();
        Color(float red, float green, float blue);

        //Getter and setter
        float getRed();
        float getGreen();
        float getBlue();

        void setRed(float red);
        void setGreen(float green);
        void setBlue(float blue);
};


#endif