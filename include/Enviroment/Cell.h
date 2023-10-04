#ifndef CELL_H
#include "../Pieces/Piece.h"
#include <string>

class Cell
{
    private:
        int pos;
        CPiece *piece;
        bool freeUpperSpace;
    public:
        Cell();
        Cell(int pos);
        Cell(int pos, CPiece *piece);
        ~Cell();
        int getPos();
        void setPos(int pos);
        CPiece *getPiece();
        void setPiece(CPiece *piece);
        void print();
        std::string getSymbol(int size);
        void setFreeUpperSpace(bool space);
        bool isFreeUpperSpace();
};

#endif