#include "Api_logic.h"

std::vector<Cell*> Api_logic::selectCells(Cell* cell){
    std::vector<Cell*> cells{cell};
    Layer* layer = map->findLayer(cell);
    if(cell->getPiece() == NULL)
        return cells;
    std::vector<std::vector<int>> CellsId = cell->getPiece()->getMoves(cell->getPos(), layer->getSize());
    std::vector<Cell*> tempCells;
    for(int i = 0; i < CellsId.size(); i++){
        tempCells = getPathFromIds(layer, CellsId[i]);
        cells.insert(cells.end(), tempCells.begin(), tempCells.end());
    }
}


std::vector<Cell*> Api_logic::getPathFromIds(Layer* startLayer, std::vector<int> cellsId){
    int startLayerPos = map->getLayerPos(startLayer);
    int maxDist = 0, height = 0, lowness = 0;
    Cell* upperCell = NULL, *bottomCell = NULL, *nextCell = NULL;
    std::vector<Cell*> cells;
    std::vector<Cell*> tempCells;
    for(int i = 0; i < cellsId.size(); i++){
        while(upperCell == NULL && startLayerPos + height < map->getHeight()){
            height++;
            upperCell = map->getLayer(startLayerPos + height)->getCell(cellsId[i]);
            nextCell = map->getLayer(startLayerPos + height - Utils::PIECEHEIGHT)->getCell(cellsId[i+1]);
            if(upperCell == NULL && height > Utils::PIECEHEIGHT && nextCell != NULL && nextCell->isFreeUpperSpace()){
                tempCells = getPathFromIds(
                                    map->getLayer(startLayerPos + height - Utils::PIECEHEIGHT), 
                                    std::vector<int>(cellsId.begin() + i + 1, cellsId.end()));
                cells.insert(cells.end(), tempCells.begin(), tempCells.end());
                tempCells.clear();
                break;
            }
        }
        while(bottomCell == NULL && startLayerPos - lowness >= 0){
            lowness++;
            bottomCell = map->getLayer(startLayerPos - lowness)->getCell(cellsId[i]);
            if(bottomCell != NULL && lowness > Utils::PIECEHEIGHT+1 && map->getLayer(startLayerPos - lowness)->getCell(cellsId[i])->isFreeUpperSpace()){
                tempCells = getPathFromIds(
                                    map->getLayer(startLayerPos - lowness), 
                                    std::vector<int>(cellsId.begin() + i, cellsId.end()));
                cells.insert(cells.end(), tempCells.begin(), tempCells.end());
                tempCells.clear();
                break;
            }
        }
    }
    return cells;
}