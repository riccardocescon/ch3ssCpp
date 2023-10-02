#include "./Piece.h"

class Cell
{
    private:
        int pos;
        Piece *piece;
    public:
        Cell();
        Cell(int pos);
        Cell(int pos, Piece *piece);
        ~Cell();
        int getPos();
        void setPos(int pos);
        Piece *getPiece();
        void setPiece(Piece *piece);
        void print();
};