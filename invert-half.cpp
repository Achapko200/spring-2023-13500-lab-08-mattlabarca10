#include <iostream>
#include <string>
#include "imageio.h"

int main(){
  std::string input = "image2.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); 
  // read it from the file "image2.pgm"
  // h and w were passed by reference and now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  
  // Now we can invert the right half of the picture
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++){
        if(col >= w/2)
            out[row][col] = (255-img[row][col]);
        else
            out[row][col] = img[row][col];
    }
  }
  
  // and save this new image to file "taskB.pgm"
  writeImage("taskB.pgm",out, h, w);
  
  return 0;
}