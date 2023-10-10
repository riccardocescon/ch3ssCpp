#include "Piece.h"

class Knight : public CPiece
{
public:
    Knight(Utils::Color color);
    ~Knight();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
    std::vector<int> getAttackMoves(int position, int mapLength);
};