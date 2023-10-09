#include "Piece.h"

class Queen : public CPiece
{
public:
    Queen(Utils::Color color);
    ~Queen();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};