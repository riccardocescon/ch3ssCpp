#ifndef API_LOGIC_H

#include <iostream>
#include <vector>
#include "../Enviroment/Map.h"

class Api_logic
{
private:
    static Map *map;

public:
    static void setMap(Map *map);
    static std::vector<Cell *> selectCell(Cell *cell);
    static std::vector<Cell *> selectCells(Cell *cell);
    static void getPathFromIds(std::vector<Cell *> *cells, Layer *startLayer, std::vector<int> cellsId, Utils::Color color, bool firstCall);
    static void checkUpperPath(std::vector<Cell *> *cells, Cell *currentCell, std::vector<int> cellsId, int startLayerPos, Utils::Color color, bool *frontSpace, bool firstCall);
    static void checkLowerPath(std::vector<Cell *> *cells, int startLayerPos, std::vector<int> cellsId, Utils::Color color, bool frontSpace);
    static void handlePawnAttack(CPiece *piece, std::vector<Cell *> *cells, Cell *cell);
    static void handleKnightAttack(CPiece *piece, std::vector<Cell *> *cells, Cell *cell);
};

#endif