#ifndef PIECE_H

#pragma once

#include <vector>
#include "../../include/Utils.h"
class CPiece
{
public:
    CPiece(Utils::Color color);
    ~CPiece();
    int getValue();
    virtual std::vector<std::vector<int>> getMoves(int position, int mapLength) = 0;
    Utils::Color getColor();
protected:
    Utils::PieceType value;
    Utils::Color color;
};

#endif
