#ifndef PIECE_H

#pragma once

#include <vector>
#include "../../include/Utils.h"
class CPiece
{
public:
    CPiece();
    ~CPiece();
    int getValue();
    virtual std::vector<std::vector<int>> getMoves(int position, int mapLength) = 0;
protected:
    Utils::PieceType value;
};

#endif
