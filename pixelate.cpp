#include <iostream>
#include <string>
#include "imageio.h"

int pixelate(){
  std::string input = "image1.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); 
  // read it from the file "image1.pgm"
  // h and w were passed by reference and now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can pixelate the image
  int out[MAX_H][MAX_W];
  int avg;
  for(int row = 0; row < h; row+=2) {
    for(int col = 0; col < w; col+=2) {
        avg = (img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1])/4;
        out[row][col] = avg;
        out[row+1][col] = avg;
        out[row][col+1] = avg;
        out[row+1][col+1] = avg;
    }
  }
  
  // and save this new image to file "taskF.pgm"
  writeImage("taskF.pgm",out, h, w);
  
  return 0;
}