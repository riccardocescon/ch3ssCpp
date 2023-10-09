#include "Piece.h"

class Rook : public CPiece
{
    public:
    Rook(Utils::Color color);
    ~Rook();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};