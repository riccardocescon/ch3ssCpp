#ifndef FSM_H

#include <iostream>
#include <vector>
#include "../Cell.h"
#include "../Piece.h"
#include "../Utils.cpp"
#include "./Api_logic.h"

class FSM {
    private:
        static bool turn;
        static Utils::State state;
    public:
        std::vector<Cell*> selectCell(Cell* cell);
        std::vector<Cell*> selectPiece(Piece* piece);
};

#endif