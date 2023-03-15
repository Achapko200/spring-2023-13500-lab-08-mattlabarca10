#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "imageio.h"

int main(){
    std::string input = "image1.pgm";
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 
    // read it from the file "image1.pgm"
    // h and w were passed by reference and now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data
    // Now we can invert the image
    int out[MAX_H][MAX_W];
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(col==0 || col==w-1 || row==0 || row==h-1)
                out[row][col] = 0;
            else if(((img[row+1][col-1])+2*img[row+1][col]+img[row+1][col+1])-(img[row-1][col-1]+2*img[row-1][col]+img[row-1][col+1])<0)
                out[row][col] = 0;
            else if(((img[row+1][col-1])+2*img[row+1][col]+img[row+1][col+1])-(img[row-1][col-1]+2*img[row-1][col]+img[row-1][col+1])>255)
                out[row][col] = 0;
            else
                out[row][col] = ((img[row+1][col-1])+2*img[row+1][col]+img[row+1][col+1])-(img[row-1][col-1]+2*img[row-1][col]+img[row-1][col+1]);
        }
        //f(a,b,c,d,e,f,g,h,i) = (g+2h+i)-(a+2b+c)
    }
  
  
    // and save this new image to file "taskG.pgm"
    writeImage("taskG.pgm",out, h, w);
    return 0;
}