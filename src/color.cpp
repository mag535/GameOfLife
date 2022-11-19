/*
Melissa Gray
10/6/2022

Header file for Color class
*/

#include "color.h"


/* CONSTRUCTORS */

// Default: set color to transparant black
Color::Color(){
    int i;
    for (i = 0; i < 4; i++){
        rgba[i] = 0;
    }
    return;
}

// Constructor: set own color
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
