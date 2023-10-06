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
    return cells;
}


std::vector<Cell*> Api_logic::getPathFromIds(Layer* startLayer, std::vector<int> cellsId, bool firstCall = false){
    int startLayerPos = map->getLayerPos(startLayer);
    std::vector<Cell*> tempCells, cells;
    Cell *currentCell, *checkCell;
    currentCell = map->getLayer(startLayerPos)->getCell(cellsId[0]);
    //check for path in lower layers if the current cell is NULL
    if(currentCell == NULL){
        //Start checking from the layer below the current one
        for(int lowerLayer = startLayerPos-1; lowerLayer > 0; lowerLayer--)
            //If you find a cell underneeth the current one, rerun this method but starting from the found cell
            if(map->getLayers()[lowerLayer]->getCell(cellsId[0]) != NULL){
                //Like this you will check the path from the found cell (where the piece can go) like if it was the current cell
                tempCells = getPathFromIds(
                                map->getLayer(lowerLayer), 
                                std::vector<int>(cellsId.begin(), cellsId.end()));
                //And then you add the found path to the current one
                cells.insert(cells.end(), tempCells.begin(), tempCells.end());
                tempCells.clear();
                break;
            }
    }
    //check for path in upper layers if the current cell is not NULL and has free space on it
    //cellsId.size() > 1 is done because if there is only one cell in the vector it means that 
    //we are at the edge of the map and there will be no more cells to check
    //This part starts the recursion for every cell in the upper layers (and one cell ahead) and also for the current layer
    if(cellsId.size() > 1 && (currentCell->getPiece() == NULL || firstCall))
        //Start checking from the layer where the current cell is (like this you will also check the path from the current cell) and
        //continue vertically until there is space on top of the current cell or until you reach the top of the map
        for(int elevate = 0; elevate <= currentCell->getFreeUpperSpace() - Utils::PIECEHEIGHT && elevate < map->getHeight() - startLayerPos; elevate++){
            //cellsId[1] is the next cell (column of cell) the piece will go to (meanwhile cellsId[0] is the current cell)
            checkCell = map->getLayer(startLayerPos + elevate)->getCell(cellsId[1]);
            //so, for each layer you check if the next cell is not NULL and if it has enough space on top of it
            //! NEEDED  A WAY TO CHECK THE NEXT CELL EVEN IF IT IS NULL TO SEE IF THERE IS A PATH GOING DOWN
            //! TO KEEP IN MIND THAT IS NOT POSSIBLE TO GO DOWN IF THE NEXT CELL IN THE UPPER LAYER IS NOT NULL, THERE HAS TO BE ENOUGH SPACE IN FRONT OF THE CURRENT CELL
            if(checkCell != NULL && checkCell->getFreeUpperSpace() >= Utils::PIECEHEIGHT){
                //if you find a cell that has enough space on top of it, you rerun this method but starting from the found cell
                tempCells = getPathFromIds(
                                    map->getLayer(startLayerPos + elevate), 
                                    std::vector<int>(cellsId.begin() + 1, cellsId.end()));
                cells.insert(cells.end(), tempCells.begin(), tempCells.end());
                tempCells.clear();
            }
        }
    //the !firstCall is to avoid the first call of the function to add the current cell to the vector 
    // because is the cell the piece is currently stending on
    if(currentCell != NULL && currentCell->getFreeUpperSpace() >= Utils::PIECEHEIGHT && !firstCall)
        cells.push_back(currentCell);
    return cells;
}