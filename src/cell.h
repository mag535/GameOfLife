/*
Melissa Gray
9/16/2022

Header file for Cell object
*/


#ifndef CELL_H
#define CELL_H

class Cell{
    private:
        // state trackers
        bool previousState;
        bool currentState;

        // i,j position in grid
        int i;
        int j;
        
        // for graphics
        float width;
        float height;
        // FIXME: color object
    
    public:
        // default constructor
        Cell();
        // Constructor
        Cell(int x, int y);

        // setters for the prev and curr state
        void setCurrentState(bool curr);
        void setPreviousState(bool prev);
        // getters for the prev and curr state
        bool getCurrentState() { return currentState; }
        bool getPreviousState() { return previousState; }
        // getters for the position of the cell within the grid
        int getI() { return i; }
        int getJ() { return j; }
};

#endif