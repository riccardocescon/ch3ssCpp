#include "../../include/Pieces/Pawn.h"

Pawn::Pawn(Utils::Color color) : CPiece(color)
{
    this->type = Utils::PieceType::PAWN;
}

Pawn::~Pawn()
{
}

std::vector<std::vector<int>> Pawn::getMoves(int position, int mapLength)
{
    return Moves::pawn(position, mapLength, movesCount > 0 ? 1 : 2, this->color);
}