#ifndef BISHOP_H

#include "./Piece.h"

class Bishop : public CPiece
{
public:
    Bishop();
    ~Bishop();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};

#endif
