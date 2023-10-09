#include "../../include/API/Api_logic.h"

Map* Api_logic::map = NULL;

void Api_logic::setMap(Map *copyMap){
    map = copyMap;
}

std::vector<Cell*> Api_logic::selectCells(Cell* cell){
    std::vector<Cell*> cells;
    Layer* layer = map->findLayer(cell);
    if(cell->getPiece() == NULL)
        return cells;
    std::vector<std::vector<int>> CellsId = cell->getPiece()->getMoves(cell->getPos(), layer->getSize());
    std::vector<Cell*> tempCells;
    for(int i = 0; i < CellsId.size(); i++){
        tempCells = getPathFromIds(layer, CellsId[i], true);
        cells.insert(cells.end(), tempCells.begin(), tempCells.end());
        tempCells.clear();
    }
    for(auto cell: cells){
        cell->setCheck(false);
    }
    return cells;
}


std::vector<Cell*> Api_logic::getPathFromIds(Layer* startLayer, std::vector<int> cellsId, bool firstCall = false){
    int startLayerPos = map->getLayerPos(startLayer);
    bool frontSpace = true;
    std::vector<Cell*> tempCells, cells;
    Cell *currentCell;
    currentCell = map->getLayer(startLayerPos)->getCell(cellsId[0]);
    //If this cell is NULL skip it by returning the empty vector
    if(currentCell == NULL) return cells;
    //If this cell has check flag set to true, it means that it has already checked the paths from this cell, so skip it by returning the empty vector
    if(currentCell->isCheck()) return cells;
    //Set the check flag to true to avoid checking the paths from this cell again, but not if it is the first call of the function because the first call is the cell the piece is currently stending on 
    //and we need it to be false otherwise it will check only the paths in the first direction
    if(!firstCall) currentCell->setCheck(true);
    //If the current cell has a piece on it, and it's not the cell where the selected piece is standing (!firstcall), add it to the vector and return it
    if(currentCell->getPiece() != NULL && !firstCall){
        //!Add check for the piece color, if enemy add the cell to the vector, else return the empty vector
        cells.push_back(currentCell);
        return cells;
    }
    //If there is something to check after the current cell, check it
    if(cellsId.size() > 1){
        tempCells = checkUpperPath(currentCell, cellsId, startLayerPos, &frontSpace, firstCall);
        cells.insert(cells.end(), tempCells.begin(), tempCells.end());
        tempCells.clear();

        tempCells = checkLowerPath(startLayerPos, cellsId, frontSpace);
        cells.insert(cells.end(), tempCells.begin(), tempCells.end());
        tempCells.clear();
    }
    //the !firstCall is to avoid the first call of the function to add the current cell to the vector 
    // because is the cell the piece is currently stending on
    if(currentCell->getFreeUpperSpace() >= Utils::PIECEHEIGHT && !firstCall)
        cells.push_back(currentCell);
    return cells;
}

std::vector<Cell*> Api_logic::checkUpperPath(Cell* currentCell, std::vector<int> cellsId, int startLayerPos, bool* frontSpace, bool firstCall = false){
    Cell *checkCell;
    std::vector<Cell*> tempCells, cells;
    //check for path in upper layers if the current cell is not NULL and has free space on it
    //cellsId.size() > 1 is done because if there is only one cell in the vector it means that 
    //we are at the edge of the map and there will be no more cells to check
    //This part starts the recursion for every cell in the upper layers (and one cell ahead) and also for the current layer
    if(currentCell->getPiece() == NULL || firstCall)
        //Start checking from the layer where the current cell is (like this you will also check the path from the current cell) and
        //continue vertically until there is space on top of the current cell or until you reach the top of the map
        for(int elevate = 0; elevate <= currentCell->getFreeUpperSpace() - Utils::PIECEHEIGHT && elevate < map->getHeight() - startLayerPos; elevate++){
            //cellsId[1] is the next cell (column of cell) the piece will go to (meanwhile cellsId[0] is the current cell)
            checkCell = map->getLayer(startLayerPos + elevate)->getCell(cellsId[1]);
            //so, for each layer you check if the next cell is not NULL and if it has enough space on top of it
            if(checkCell != NULL && checkCell->getFreeUpperSpace() >= Utils::PIECEHEIGHT){
                if(elevate <= Utils::PIECEHEIGHT) *frontSpace = false;
                //if you find a cell that has enough space on top of it, you rerun getPathFromIds method but starting from the found cell
                tempCells = getPathFromIds(
                                    map->getLayer(startLayerPos + elevate), 
                                    std::vector<int>(cellsId.begin() + 1, cellsId.end()));
                cells.insert(cells.end(), tempCells.begin(), tempCells.end());
                tempCells.clear();
            }
        }
    return cells;
}

std::vector<Cell*> Api_logic::checkLowerPath(int startLayerPos, std::vector<int> cellsId, bool frontSpace){
    Cell *checkCell;
    if(frontSpace)
        //check for path in lower layers, underneath the next cell, only if there is enough space in front of the current cell to let the piece pass and go down
        for(int lowerLayer = startLayerPos-1; lowerLayer >= 0; lowerLayer--){
            checkCell = map->getLayer(lowerLayer)->getCell(cellsId[1]);
            //If you find a cell underneeth, re-run this method but starting from the found cell
            if(checkCell != NULL){
                //Like this you will check the path from the found cell (where the piece can go) like if it was the current cell
                return getPathFromIds(
                                map->getLayer(lowerLayer), 
                                std::vector<int>(cellsId.begin() + 1, cellsId.end()));
            }
        }
    return std::vector<Cell*>();
}