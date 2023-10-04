#ifndef LAYER_H

#include "./Cell.h"
#include <vector>
#include <iostream>
#include <cmath>

class Layer{
    private:
        std::vector<Cell*> cells;
        int size;
    public:
        Layer();
        Layer(int size);
        Layer(std::vector<Cell*> cells);
        ~Layer();
        std::vector<Cell*> getCells();
        void pushCells(std::vector<Cell*> cells);
        void addCell(Cell *cell);
        void print();
        void print(std::vector<Cell*> cells);
        Cell *getCell(int pos);
        void setCell(int pos, Cell *cell);
        Cell findCell(CPiece* piece);
        int getSize();
};

#endif