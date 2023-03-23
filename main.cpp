#include <iostream>
#include "invert.h"
#include "invert-half.h"
#include "box.h"
#include "frame.h"
#include "scale.h"
#include "pixelate.h"
#include "kernel.h"

int main(){
    invert();
    half();
    box();
    frame();
    scale();
    pixelate();
    kernel();
}