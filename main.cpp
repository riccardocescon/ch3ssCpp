#include <iostream>
#include <vector>
#include "./Cell.h"
#include "./Map.h"
#include "./Utils.cpp"
#include "./API/Api_logic.h"
#include "./API/fsm.h"

int main(){
    FSM fsm;
    Api_logic api;
    std::vector<Cell*> cells;
    for (int i = 0; i < 16; i++){
        cells.push_back(new Cell(i));
    }
    Map* map = new Map(4);
    map->print();
    return 0;
}