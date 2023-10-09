#include "../../include/Pieces/Bishop.h"

Bishop::Bishop(Utils::Color color) : CPiece(color)
{
    this->type = Utils::PieceType::BISHOP;
}

Bishop::~Bishop()
{
}

std::vector<std::vector<int>> Bishop::getMoves(int position, int mapLength)
{
    return Moves::diagonals(position, mapLength);
}
