#include "Piece.h"

class Pawn : public CPiece
{
public:
    Pawn(Utils::Color color);
    ~Pawn();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};