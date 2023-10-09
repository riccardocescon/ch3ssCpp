#include "../../include/Pieces/Piece.h"

CPiece::CPiece(Utils::Color color): color(color)
{
}

CPiece::~CPiece()
{
}

int CPiece::getValue()
{
    return this->value;
}

Utils::Color CPiece::getColor()
{
    return this->color;
}