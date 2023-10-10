#include "../../include/Pieces/Queen.h"

Queen::Queen(Utils::Color color) : CPiece(color)
{
    this->type = Utils::PieceType::QUEEN;
}

Queen::~Queen()
{
}

std::vector<std::vector<int>> Queen::getMoves(int position, int mapLength)
{
    std::vector<std::vector<int>> straightMoves = Moves::straights(position, mapLength);
    std::vector<std::vector<int>> diagonalMoves = Moves::diagonals(position, mapLength);
    straightMoves.insert(straightMoves.end(), diagonalMoves.begin(), diagonalMoves.end());
    return straightMoves;
}