#ifndef BISHOP_H

#include "../Piece.h"
#include "../Utils.cpp"

class Bishop : public Piece
{
public:
    Bishop();
    ~Bishop();
    std::vector<std::vector<int>> getMoves(int position, int mapLength);
};

#endif
