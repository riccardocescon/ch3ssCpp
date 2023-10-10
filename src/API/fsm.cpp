#include "../../include/API/fsm.h"

bool FSM::turn = true;
Utils::State FSM::state = Utils::State::SELECT;

std::vector<Cell *> FSM::selectCell(Cell *cell)
{
    std::vector<Cell *> cells;
    if (state == Utils::State::SELECT)
    {
        cells = Api_logic::selectCells(cell);
        state = Utils::State::MOVE;
        return cells;
    }
    else if (state == Utils::State::MOVE)
    {
        // return this->selectPiece(cell->getPiece());
    }
    return cells;
}