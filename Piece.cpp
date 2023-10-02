#include "./Piece.h"

Piece::Piece()
{
    this->value = 0;
}

Piece::~Piece()
{
}

int Piece::getValue()
{
    return this->value;
}