#include "Color.hpp"
#include "Imagee.hpp"

int main(){
    Imagee imgg = Imagee(4, 2);

    Color col[25] = {Color(5.0, 1.0, 2.0),Color(5.0, 1.0, 2.0),Color(5.0, 1.0, 2.0),Color(5.0, 1.0, 2.0), 
        Color(5.0, 1.0, 2.0),Color(5.0, 1.0, 2.0),Color(5.0, 1.0, 2.0),Color(5.0, 1.0, 2.0)};
    
    Color *point = &col[0];

    imgg.fillImg(point);

    imgg.printImg();
}