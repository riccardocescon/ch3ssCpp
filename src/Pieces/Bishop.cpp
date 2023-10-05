#include "../../include/Pieces/Bishop.h"

Bishop::Bishop(): CPiece()
{
    this->value = Utils::PieceType::BISHOP;
}

Bishop::~Bishop()
{
}

std::vector<std::vector<int>> Bishop::getMoves(int position, int mapLength)
{
    int secondDiagonal = mapLength+1, mainDiagonal = mapLength-1;
    int checkPosition = position; 
    std::vector<int> validCells;
    std::vector<std::vector<int>> validCellsByDirection;
    // Bottom left
    for(int checkPosition = position; checkPosition > 0; checkPosition -= secondDiagonal){
        if(((checkPosition + 1) % mapLength == 0)) break;
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();

    // Bottom right
    for(int checkPosition = position; checkPosition > 0; checkPosition -= mainDiagonal){
        if(((checkPosition + 1) % mapLength == 1)) break;
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();

    // Top right
    for(int checkPosition = position; checkPosition < mapLength*mapLength; checkPosition += secondDiagonal){
        if(((checkPosition+1) % mapLength == 1)) break;
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();

    // Top left
    for(int checkPosition = position; checkPosition < mapLength*mapLength; checkPosition += mainDiagonal){
        if(((checkPosition+1) % mapLength == 0)) break;
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();
    return validCellsByDirection;
}
