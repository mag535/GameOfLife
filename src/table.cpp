/*
Melissa Gray
9/16/2022

Implementation of Table class
*/

#include "table.h"
#include <typeinfo>
#include <iostream>
#include <stdlib.h>


// Default Constructors: make table non-existent
template <typename T>
Table<T>::Table(){
    numberOfRows = 0;
    numberOfColumns = 0;
    columnsAllocated = 0;
    rows = NULL;
    memoryAllocated = 0;
    return;
}

// Constructor
template <typename T>
Table<T>::Table(int nrow, int ncol){
    numberOfRows = nrow;
    numberOfColumns = ncol;
    columnsAllocated = 0;
    memoryAllocated = 0;
    // don't allocate just yet
    rows = NULL;
    return;
}

/*
function: initialize
--------------------
Allocates memory for the rows and columns
of the table. Tracks memory allocated

Status:
    0 = sucess
    1 = couldn't allocate rows variable
    2 = couldn't allocate row pointers

Returns: a status number.

Warning: allocates memory, but does not free.
*/
template <typename T>
int Table<T>::initialize(){
    /*
    Type Translation:
        P = pointer
        i = int
        b = bool
        4Cell = Cell (class)
        5Table = Table (class)
    */
    bool allocationError = false;

    // Creating pointers for each row.
    rows = (T **) malloc(sizeof(T *) * numberOfRows);
    if (!rows)
        return 1;
    memoryAllocated += sizeof(T *) * numberOfRows;

    // Allocating memory for each row
    int i;
    for (i = 0; i < numberOfRows; i++){
        *(rows + i) = (T *) malloc(sizeof(T) * numberOfColumns);
        if (!(*(rows + i))){
            allocationError = true;
            break;
        }
        memoryAllocated += sizeof(T) * numberOfColumns;
        columnsAllocated++;
    }

    // check for allocation error
    if (allocationError){
        int j;
        for (j = 0; j < i; j++){
            free(*(rows + i));
            memoryAllocated -= sizeof(T) * numberOfColumns;
        }
        return 2;
    }
    return 0;
}

/*
function: destroy
-----------------
Frees the memory allocated for the table's rows.

Status:
    0 = memoryAllocated == zero (meaning everything was freed properly)
    1 = memoryAllocated > zero (meaning something wasn't freed)
    2 = memoryAllocated < zero (meaning allocation calculation is off)

Returns: a status number.

Warnning: frees previously allocated memory.
*/
template <typename T>
int Table<T>::destroy(){
    int i;

    // free rows
    if (columnsAllocated == numberOfColumns){
        for (i = 0; i < numberOfRows; i++){
            free(*(rows + i));
            memoryAllocated -= sizeof(T) * numberOfColumns;
        }
    }

    // free row pointers
    free(rows);
    memoryAllocated -= sizeof(T *) * numberOfRows;

    // check memoryAllocated
    if (memoryAllocated > 0)
        return 1;
    else if (memoryAllocated < 0)
        return 2;
    
    return 0;
}

/*
function: insert
----------------
Inserts a value into the given position.

x: the row
y: the column

Returns: nothing.
*/
template <typename T>
void Table<T>::insert(int x, int y, T val){
    // bound checks
    if ((x < 0) || (y < 0) || (x > numberOfRows) || (y > numberOfColumns)){
        std::cout << "ERROR: Index out of range!" << std::endl;
        return;
    }

    // find target row
    T *targetRow = *(rows + x);

    // insert value into target column
    *(targetRow + y) = val;

    return;
}

/*
function: index
---------------
Finds and returns the value at the given position.
(0, 0) Represents the element in the first row and column.

x: the row
y: the column.
*/
template <typename T>
T *Table<T>::index(int x, int y){
    // bound checks
    if ((x < 0) || (y < 0) || (x > numberOfRows) || (y > numberOfColumns)){
        std::cout << "ERROR: Index out of range!" << std::endl;
        return NULL;
    }

    T *target;

    // find target row
    T *targetRow = *(rows + x);

    // get address from target column
    target = (targetRow + y);

    return target;
}


/* Instantiation of template functions */
template class Table<bool>;
