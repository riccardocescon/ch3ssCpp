#include "../../include/Pieces/King.h"

King::King(Utils::Color color) : CPiece(color)
{
    this->type = Utils::PieceType::KING;
}

King::~King()
{
}

std::vector<std::vector<int>> King::getMoves(int position, int mapLength)
{
    return Moves::neighbor(position, mapLength);
}