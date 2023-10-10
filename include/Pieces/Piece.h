#ifndef PIECE_H

#pragma once

#include <vector>
#include "../../include/Utils/Utils.h"
#include "../../include/Utils/Pieces/Moves.h"
class CPiece
{
public:
    CPiece(Utils::Color color);
    ~CPiece();
    virtual std::vector<int> getAttackMoves(int position, int mapLength);
    Utils::Color getColor();
    Utils::PieceType getType();
    virtual std::vector<std::vector<int>> getMoves(int position, int mapLength) = 0;

protected:
    Utils::PieceType type;
    Utils::Color color;
    int movesCount = 0;
};

#endif
