#include "../../include/API/Api_logic.h"

Map *Api_logic::map = NULL;

void Api_logic::setMap(Map *copyMap)
{
    map = copyMap;
}

std::vector<Cell *> Api_logic::selectCells(Cell *cell)
{
    std::vector<Cell *> cells;
    Layer *layer = map->findLayer(cell);
    if (cell->getPiece() == NULL)
        return cells;
    std::vector<std::vector<int>> CellsId = cell->getPiece()->getMoves(cell->getPos(), layer->getSize());
    for (int i = 0; i < CellsId.size(); i++)
    {
        getPathFromIds(&cells, layer, CellsId[i], cell->getPiece()->getColor(), true);
    }
    for (auto cell : cells)
    {
        cell->setCheck(false);
    }
    return cells;
}

void Api_logic::getPathFromIds(std::vector<Cell *> *cells, Layer *startLayer, std::vector<int> cellsId, Utils::Color color, bool firstCall = false)
{
    int startLayerPos = map->getLayerPos(startLayer);
    bool frontSpace = true;
    Cell *currentCell = map->getLayer(startLayerPos)->getCell(cellsId[0]);
    // If this cell is NULL skip it by returning the empty vector
    if (currentCell == NULL)
        return;
    // If this cell has check flag set to true, it means that it has already checked the paths from this cell, so skip it by returning the empty vector
    if (currentCell->isCheck())
        return;
    // Set the check flag to true to avoid checking the paths from this cell again, but not if it is the first call of the function because the first call is the cell the piece is currently stending on
    // and we need it to be false otherwise it will check only the paths in the first direction
    if (!firstCall)
        currentCell->setCheck(true);
    // If the current cell has a piece on it, and it's not the cell where the selected piece is standing (!firstcall), add it to the vector and return it
    if (currentCell->getPiece() != NULL && !firstCall)
    {
        if (currentCell->getPiece()->getColor() != color)
            cells->push_back(currentCell);
        return;
    }
    // cellsId.size() > 1 is done because if there is only one cell in the vector it means that
    // we are at the edge of the map and there are be no more cells to check in that direction
    if (cellsId.size() > 1)
    {
        checkUpperPath(cells, currentCell, cellsId, startLayerPos, color, &frontSpace, firstCall);

        checkLowerPath(cells, startLayerPos, cellsId, color, frontSpace);
    }
    // the !firstCall is to avoid the first call of the function to add the current cell to the vector
    //  because is the cell the piece is currently stending on
    if (currentCell->getFreeUpperSpace() >= Utils::PIECEHEIGHT && !firstCall)
        cells->push_back(currentCell);
    return;
}

void Api_logic::checkUpperPath(std::vector<Cell *> *cells, Cell *currentCell, std::vector<int> cellsId, int startLayerPos, Utils::Color color, bool *frontSpace, bool firstCall = false)
{
    Cell *checkCell;
    // check for path in upper layers if the current cell is not NULL
    // This part starts the recursion for every cell that is one column ahead in the upper layers and also in the current layer
    if (currentCell->getPiece() != NULL && !firstCall)
        return;

    // Start checking from the layer where the current cell is (like this you will also check the path from the current cell) and
    // continue vertically until there is space on top of the current cell or until you reach the top of the map
    int lastLayer = map->getHeight() - startLayerPos;
    int maxElevate = currentCell->getFreeUpperSpace() - Utils::PIECEHEIGHT;
    for (int elevate = 0; elevate <= maxElevate && elevate < lastLayer; elevate++)
    {
        // cellsId[1] is the next cell (column of cell) the piece will go to (meanwhile cellsId[0] is the current cell)
        checkCell = map->getLayer(startLayerPos + elevate)->getCell(cellsId[1]);
        if (checkCell == NULL)
            continue;

        if (checkCell->getFreeUpperSpace() < Utils::PIECEHEIGHT)
            continue;
        // so, for each layer you check if the next cell is not NULL and if it has enough space on top of it

        if (elevate <= Utils::PIECEHEIGHT && elevate > 0)
            *frontSpace = false;
        // if you find a cell that has enough space on top of it, you rerun getPathFromIds method but starting from the found cell
        getPathFromIds(cells,
                       map->getLayer(startLayerPos + elevate),
                       std::vector<int>(cellsId.begin() + 1, cellsId.end()),
                       color);
    }
}

void Api_logic::checkLowerPath(std::vector<Cell *> *cells, int startLayerPos, std::vector<int> cellsId, Utils::Color color, bool frontSpace)
{
    Cell *checkCell;

    // If there is a cell stopping me from going downwards
    if (!frontSpace)
        return;

    // check for path in lower layers, underneath the next cell, only if there is enough space in front of the current cell to let the piece pass and go down
    for (int lowerLayer = startLayerPos - 1; lowerLayer >= 0; lowerLayer--)
    {
        checkCell = map->getLayer(lowerLayer)->getCell(cellsId[1]);
        // If you find a cell underneeth, re-run this method but starting from the found cell
        if (checkCell == NULL)
            continue;

        // Like this you will check the path from the found cell (where the piece can go) like if it was the current cell
        getPathFromIds(
            cells,
            map->getLayer(lowerLayer),
            std::vector<int>(cellsId.begin() + 1, cellsId.end()),
            color);
        return;
    }
}