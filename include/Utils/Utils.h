#ifndef UTILS_H

#pragma once

namespace Utils
{
    enum Color
    {
        WHITE,
        BLACK
    };

    enum PieceType
    {
        PAWN = 1,
        BISHOP = 2,
        KNIGHT = 3,
        ROOK = 4,
        QUEEN = 5,
        KING = 6
    };

    enum State
    {
        SELECT,
        MOVE,
        CHECK,
        CHECKMATE
    };

    const int PIECEHEIGHT = 1;

    const int INFINSPACE = 100;
}

#endif