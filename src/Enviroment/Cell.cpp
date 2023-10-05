#include "../../include/Enviroment/Cell.h"
#include <iostream>

Cell::Cell(): pos(0), piece(NULL), freeUpperSpace(0)
{
}

//Layer size nedeed to get the cell symbol(Just to debug, not used in the game)
Cell::Cell(int pos, int layerSize): pos(pos), piece(NULL), freeUpperSpace(0)
{
    symbol = getCellSymbol(layerSize);
}

Cell::Cell(int pos, CPiece *piece, int layerSize): pos(pos), piece(piece), freeUpperSpace(0)
{
    symbol = getCellSymbol(layerSize);
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

std::string Cell::getCellSymbol(int size){
    int x = (this->pos % size) - 1;
    int y = this->pos / size;
    std::string cell = "";
    cell += (char) (x + 98);
    cell += (char) (y + 49);
    return cell;
}

std::string Cell::getSymbol(){
    return this->symbol;
}

void Cell::setFreeUpperSpace(int space){
    this->freeUpperSpace = space;
}

int Cell::getFreeUpperSpace(){
    return this->freeUpperSpace;
}