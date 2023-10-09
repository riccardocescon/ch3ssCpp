#include "../../include/Pieces/Rook.h"

Rook::Rook(Utils::Color color): CPiece(color)
{
    this->value = Utils::PieceType::ROOK;
}

Rook::~Rook()
{
}

std::vector<std::vector<int>> Rook::getMoves(int position, int mapLength){
    std::vector<int> validCells;
    std::vector<std::vector<int>> validCellsByDirection;
    // Bottom
    for(int checkPosition = position; checkPosition > 0; checkPosition -= mapLength){
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();

    // Right
    for(int checkPosition = position; checkPosition > 0; checkPosition--){
        if(((checkPosition+1) % mapLength == 0)) break;
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();

    // Top
    for(int checkPosition = position; checkPosition < mapLength*mapLength; checkPosition += mapLength){
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();

    // Left
    for(int checkPosition = position; checkPosition < mapLength*mapLength; checkPosition++){
        if(((checkPosition) % mapLength == 0)) break;
        validCells.push_back(checkPosition);
    }
    validCellsByDirection.push_back(validCells);
    validCells.clear();
    return validCellsByDirection;
}