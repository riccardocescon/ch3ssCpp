#ifndef UTILS_H

#pragma once

namespace Utils{
    enum Color{
        WHITE,
        BLACK
    };

    enum PieceType{
        PAWN = 1,
        ROOK= 2,
        KNIGHT = 3,
        BISHOP = 4,
        QUEEN = 5,
        KING = 6
    };

    enum State{
        SELECT,
        MOVE,
        CHECK,
        CHECKMATE
    };

    const int PIECEHEIGHT = 2;
}

#endif