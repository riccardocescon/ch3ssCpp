#include "Piece.h"

class King : public CPiece
{
public:
    King(Utils::Color color);
    ~King();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};