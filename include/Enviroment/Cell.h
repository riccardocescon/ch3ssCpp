#ifndef CELL_H
#include "../Pieces/Piece.h"
#include <string>

class Cell
{
    private:
        int pos;
        CPiece *piece = NULL;
        int freeUpperSpace;
        std::string symbol;
        bool check = 0;
    public:
        Cell();
        Cell(int pos, int layerSize);
        Cell(int pos, CPiece *piece, int layerSize);
        ~Cell();
        int getPos();
        void setPos(int pos);
        CPiece *getPiece();
        void setPiece(CPiece *piece);
        void print();
        std::string getCellSymbol(int size);
        void setFreeUpperSpace(int space);
        int getFreeUpperSpace();
        std::string getSymbol();
        bool isCheck();
        void setCheck(bool check);
};

#endif