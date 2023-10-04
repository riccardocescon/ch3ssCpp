#include "./fsm.h"

std::vector<Cell*> FSM::selectCell(Cell* cell){
    std::vector<Cell*> cells;
    if(state == Utils::State::SELECT){
        
        if (cell->getPiece() != NULL)
            return FSM::selectPiece(cell->getPiece());
        return cells;
    }else if(state == Utils::State::MOVE){
        return this->selectPiece(cell->getPiece());
    }
    return cells;
}