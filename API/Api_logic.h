#ifndef API_LOGIC_H

#include <iostream>
#include <vector>
#include "../Cell.h"
#include "../Map.h"

class Api_logic{
    private:
        static Map* map;
    public:
        static std::vector<Cell*> selectCell(Cell* cell);
        static std::vector<Cell*> selectCells(Cell* cell);
        static std::vector<Cell*> getPathFromIds(Layer* startLayer, std::vector<int> cellsId);
};

#endif