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

std::string Cell::getSymbol(){
    int x = (this->pos - 1) % 8;
    int y = this->pos / 8;
    std::string cell = "";
    cell += (char) (x + 97);
    cell += (char) (y + 49);
    return cell;
}

void Cell::setFreeUpperSpace(bool space){
    this->freeUpperSpace = space;
}