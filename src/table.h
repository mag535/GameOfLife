/*
Melissa Gray
9/16/2022

Header file for Table object

Tables are 2D matrices.
*/


#ifndef TABLE_H
#define TABLE_H

#include <cstddef>

//#define NULL 0

template <typename T>
class Table{
    private:
        // counters
        int numberOfRows;
        int numberOfColumns;
        int columnsAllocated;

        // holds the rows of the table
        T **rows;

        // for tracking memory allocation
        size_t memoryAllocated;
        /*
            Type Size:
                int     = 4B
                bool    = 1B
                Table   = 24B
                *       = 8B

        */
    
    public:
        // Constructors
        Table();
        Table(int nrow, int ncol);

        // allocation managment
        int initialize();

        int destroy();

        // getters
        int getNumberOfRows() { return numberOfRows; }
        int getNumberOfColumns() { return numberOfColumns; }
        size_t getMemoryAllocated() { return memoryAllocated; }

        // setters
        void setNumebrOfRows(int r) { numberOfRows = r; }
        void setNumberOfColumns(int c) { numberOfColumns = c; }

        // indexers
        T index(int x, int y);

        // prints
        void printRow();
        void printColumn();
        void print();
};

#endif