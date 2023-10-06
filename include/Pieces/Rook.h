#include "Piece.h"

class Rook : public CPiece
{
    public:
    Rook();
    ~Rook();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};