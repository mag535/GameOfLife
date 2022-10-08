/*
Melissa Gray
9/16/2022

The Game of Life
*/

#include "table.h"
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

// PROTOTYPES

// MAIN
int main(int argc, char **argv){
    int i = 1;
    Table t = Table<bool>(i, i);

    bool b = true;
    t.initialize();
    std::cout << t.getMemoryAllocated() << std::endl;

    t.destroy();
    std::cout << t.getMemoryAllocated() << std::endl;
    return 0;
}


