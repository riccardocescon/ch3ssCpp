#ifndef API_LOGIC_H

#include <iostream>
#include <vector>
#include "../Enviroment/Map.h"

class Api_logic{
    private:
        static Map* map;
    public:
        static void setMap(Map* map);
        static std::vector<Cell*> selectCell(Cell* cell);
        static std::vector<Cell*> selectCells(Cell* cell);
        static std::vector<Cell*> getPathFromIds(Layer* startLayer, std::vector<int> cellsId, bool firstCall);
        static std::vector<Cell*> checkUpperPath(Cell* currentCell, std::vector<int> cellsId, int startLayerPos, bool* frontSpace, bool firstCall);
        static std::vector<Cell*> checkLowerPath(int startLayerPos, std::vector<int> cellsId, bool frontSpace);
};

#endif