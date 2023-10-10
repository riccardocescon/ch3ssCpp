#include "../../include/Pieces/Rook.h"

Rook::Rook(Utils::Color color) : CPiece(color)
{
    this->type = Utils::PieceType::ROOK;
}

Rook::~Rook()
{
}

std::vector<std::vector<int>> Rook::getMoves(int position, int mapLength)
{
    return Moves::straights(position, mapLength);
}