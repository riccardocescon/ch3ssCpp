#include "Api_logic.h"

std::vector<Cell*> Api_logic::selectCells(Cell* cell, Layer* layer){
    std::vector<Cell*> cells{cell};
    if(cell->getPiece() == NULL)
        return cells;
    cell->getPiece()->getMoves(cell->getPos(), layer->getSize());
}


std::vector<int> Api_logic::getCells(std::vector<int> pos, Layer* startLayer){
    int startLayerPos = map->getLayerPos(startLayer);
    int maxDist = 0;
    for(int layersChecked = 0; layersChecked < map->getHeight(); layersChecked++){
        for
    }
}