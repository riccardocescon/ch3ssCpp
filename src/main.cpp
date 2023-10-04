#include <iostream>
#include <vector>
#include "../include/API/fsm.h"
#include "../include/Pieces/Bishop.h"

int main(){
    FSM fsm;
    Api_logic api;
    std::vector<Cell*> cells;
    for (int i = 0; i < 64; i++){
        cells.push_back(new Cell(i));
    }
    std::vector<Cell*> cells2;
    for (int i = 0; i < 64; i+=9){
        cells2.push_back(cells[i]);
    }
    Bishop *piece = new Bishop();
    cells[7]->setPiece(piece);
    std::vector<Layer*> layer {new Layer(cells)};
    Map* map = new Map(layer);
    map->print(cells2);
    return 0;
}