#pragma once

std::string input = "image1.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); 
  // read it from the file "image1.pgm"
  // h and w were passed by reference and now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  
  // Now we can invert the image
  int out[MAX_H][MAX_W];

int box();
int frame();
int half();
int invert();
int kernel();
int pixelate();
int scale();
