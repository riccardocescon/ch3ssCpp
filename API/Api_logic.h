#include <iostream>
#include <vector>
#include "../Cell.h"
#include "../Map.h"

class Api_logic{
    private:
        Map* map;
    public:
        std::vector<Cell*> selectCell(Cell* cell);
        std::vector<Cell*> selectCells(Cell* cell, Layer* layer);
        std::vector<int> getCells(std::vector<int> pos, Layer* startLayer);
};