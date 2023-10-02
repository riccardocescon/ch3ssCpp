#include "./Cell.h"
#include <iostream>

Cell::Cell()
{
    this->pos = 0;
}

Cell::Cell(int pos)
{
    this->pos = pos;
}

Cell::Cell(int pos, Piece *piece)
{
    this->pos = pos;
    this->piece = piece;
}

Cell::~Cell()
{
    delete this->piece;
}

int Cell::getPos()
{
    return this->pos;
}

void Cell::setPos(int pos)
{
    this->pos = pos;
}

Piece *Cell::getPiece()
{
    return this->piece;
}

void Cell::setPiece(Piece *piece)
{
    this->piece = piece;
}

void Cell::print()
{
    if (this->piece == NULL)
    {
        std::cout << " ";
    }
    else
    {
        std::cout << this->piece->getValue();
    }
}