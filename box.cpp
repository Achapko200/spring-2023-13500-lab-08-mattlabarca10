#include <iostream>
#include <string>
#include "imageio.h"

int box(){
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
      if(col < w/4 || col >= 3*w/4 || row < h/4 || row >= 3*h/4)
            out[row][col] = img[row][col];
        else
            out[row][col] = 255;
    }
  }
  
  // and save this new image to file "taskC.pgm"
  writeImage("taskC.pgm",out, h, w);
  
  return 0;
}
int frame(){
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
      if((col == w/4 || col == 3*w/4 || row == h/4 || row == 3*h/4)&&(col >= w/4 && col <= 3*w/4 && row >= h/4 && row <= 3*h/4)){
            out[row][col] = 255;
      }
        else
            out[row][col] = img[row][col];
    }
  }
  
  // and save this new image to file "taskD.pgm"
  writeImage("taskD.pgm",out, h, w);
  
  return 0;
}
int half(){
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
int invert(){
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
      out[row][col] = (255-img[row][col]);
    }
  }
  
  // and save this new image to file "taskA.pgm"
  writeImage("taskA.pgm",out, h, w);
  
  return 0;
}
int kernel(){
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
