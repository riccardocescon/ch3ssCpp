#include "../../include/Enviroment/Cell.h"
#include <iostream>

Cell::Cell()
{
    this->pos = 0;
}

Cell::Cell(int pos)
{
    this->pos = pos;
}

Cell::Cell(int pos, CPiece *piece)
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

CPiece *Cell::getPiece()
{
    return this->piece;
}

void Cell::setPiece(CPiece *piece)
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

std::string Cell::getSymbol(int size){
    int x = (this->pos % size) - 1;
    int y = this->pos / size;
    std::string cell = "";
    cell += (char) (x + 98);
    cell += (char) (y + 49);
    return cell;
}

void Cell::setFreeUpperSpace(bool space){
    this->freeUpperSpace = space;
}

bool Cell::isFreeUpperSpace(){
    return this->freeUpperSpace;
}