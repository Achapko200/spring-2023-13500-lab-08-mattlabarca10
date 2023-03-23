#include <iostream>
#include <string>
#include "imageio.h"

int scale(){
  std::string input = "image1.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); 
  // read it from the file "image1.pgm"
  // h and w were passed by reference and now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can invert the image
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row+=2) {
    for(int col = 0; col < w; col+=2) {
        out[row][col] = img[row/2][col/2];
        out[row+1][col] = img[row/2][col/2];
        out[row][col+1] = img[row/2][col/2];
        out[row+1][col+1] = img[row/2][col/2];
    }
  }
  
  // and save this new image to file "taskE.pgm"
  writeImage("taskE.pgm",out, h, w);
  
  return 0;
}