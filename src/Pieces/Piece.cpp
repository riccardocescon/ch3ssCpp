#include "../../include/Pieces/Piece.h"

CPiece::CPiece(Utils::Color color) : color(color)
{
}

CPiece::~CPiece()
{
}

Utils::Color CPiece::getColor()
{
    return this->color;
}

Utils::PieceType CPiece::getType()
{
    return this->type;
}

std::vector<int> CPiece::getAttackMoves(int position, int mapLength)
{
    return std::vector<int>();
}