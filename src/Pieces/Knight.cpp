#include "../../include/Pieces/Knight.h"

Knight::Knight(Utils::Color color) : CPiece(color)
{
    this->type = Utils::PieceType::KNIGHT;
}

Knight::~Knight()
{
}

std::vector<std::vector<int>> Knight::getMoves(int position, int mapLength)
{
    return Moves::knight(position, mapLength);
}

std::vector<int> Knight::getAttackMoves(int position, int mapLength)
{
    return Moves::knightAttack(position, mapLength);
}