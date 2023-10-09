#ifndef BISHOP_H

#include "./Piece.h"

class Bishop : public CPiece
{
public:
    Bishop(Utils::Color color);
    ~Bishop();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};

#endif
