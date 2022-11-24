/*
Melissa Gray
10/6/2022

Header file for Color class
*/

#include "color.h"
#include <math.h>


/* CONSTRUCTORS */

// Default: set color to transparent black
Color::Color(){
    int i;
    for (i = 0; i < 4; i++){
        rgba[i] = 0;
    }
    return;
}

// Constructor: set own color
Color::Color(int r, int g, int b, int a){
    rgba[0] = r;
    rgba[1] = g;
    rgba[2] = b;
    rgba[3] = a;
    return;
}
// Array Constructor
Color::Color(int newColor[4]){
    int i;
    for (i = 0; i < 4; i++){
        rgba[i] = newColor[i];
    }
    return;
}


/* PREDEFINED COLORS */
const int Color::red[] = {255, 0, 0, 255};
const int Color::green[] = {0, 255, 0, 255};
const int Color::blue[] = {0, 0, 255, 255};
const int Color::black[] = {0, 0, 0, 255};
const int Color::goldenrod[] = {218, 165, 32, 255};
const int Color::turquoise[] = {1, 119, 130, 255};
const int Color::seaGreen[] = {38, 255, 176, 255};
const int Color::gray[] = {128, 128, 128, 255};
const int Color::white[] = {255, 255, 255, 255};

/*
function: invert
----------------
Inverts this object's color by subtracting the red, green, and blue
parts from 255 separately.

Returns: nothing.
*/
void Color::invert(){
    rgba[0] = 255 - rgba[0];
    rgba[1] = 255 - rgba[1];
    rgba[2] = 255 - rgba[2];
    return;
}

/*
function: complement
-------------------------
Calculates the color needed to cancel out the given color and create a grayscale
color. This means the red, green, and blue parts are all equal.

other: the color to cancel to grayscale.

Returns: the color that cancels the given color to grayscale.
*/
Color Color::complement(Color other){
    Color complementColor;
    int part;
    int rgb[3]{other.getRed(), other.getGreen(), other.getBlue()};

    // check if other is already grayscale
    if ((rgb[0] == rgb[1]) && (rgb[1] == rgb[2])){
        return other;
    }

    // find max part
    int maxPart;
    if (rgb[0] > rgb[1]){
        maxPart = rgb[0];
    }else{
        maxPart = rgb[1];
    }

    if (rgb[2] > maxPart){
        maxPart = rgb[2];
    }

    // calculate complement
    complementColor = Color(maxPart - rgb[0], maxPart - rgb[1], 
                            maxPart - rgb[2], other.getAlpha());

    return complementColor;
}
