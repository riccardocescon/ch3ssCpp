#include "../../include/API/fsm.h"

bool FSM::turn = true;
Utils::State FSM::state = Utils::State::SELECT;

std::vector<Cell*> FSM::selectCell(Cell* cell){
    std::vector<Cell*> cells;
    if(state == Utils::State::SELECT){
        return Api_logic::selectCells(cell);
    }else if(state == Utils::State::MOVE){
        //return this->selectPiece(cell->getPiece());
    }
    return cells;
}