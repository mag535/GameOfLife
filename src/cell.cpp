/*
Melissa Gray
9/16/2022

Implementation of Cell class
*/

#include "cell.h"


// default Cell constructor
Cell::Cell(){
    // set position to (0,0)
    i = 0;
    j = 0;
    // default setup for newly created cell
    previousState = false;
    currentState = true;
    return;
}

// Cell constructor
Cell::Cell(int x, int y){
    // set position to given one
    i = x;
    j = y;
    // default setup for newly created cell
    previousState = false;
    currentState = true;
    return;
}

