#include <iostream>
#include <vector>
#include "../include/API/fsm.h"
#include "../include/Pieces/Bishop.h"
#include "../include/Pieces/Rook.h"

int main(){
    FSM fsm;
    Api_logic api;
    std::vector<Cell*> cells, cells1, cells2;
    for (int i = 0; i < 64; i++){
        cells.push_back(new Cell(i, 8));
    }
    for (int i = 0; i < 8; i++){
        cells1.push_back(new Cell(i, 8));
    }
    for (int i = 8; i < 55; i++){
        if(i%8 == 0 || i%8 == 7)
            cells1.push_back(new Cell(i, 8));
        else cells1.push_back(NULL);
    }
    for (int i = 55; i < 64; i++){
        cells1.push_back(new Cell(i, 8));
    }
    for(int i = 0; i < 64; i++){
        if(i == 30)
            cells2.push_back(new Cell(i, 8));
        else cells2.push_back(NULL);
    }
    //Bishop *piece = new Bishop();
    Rook *piece = new Rook();
    cells[30]->setPiece(piece);
    std::vector<Layer*> layer {new Layer(cells), new Layer(cells1), new Layer(cells2)};
    Map* map = new Map(layer);
    api.setMap(map);
    std::vector<Cell*> cells3 = api.selectCells(cells[30]);
/* 
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    for(int i = 100; i < 100000; i++)
        cells3 = api.selectCells(cells[30]);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time: " << cpu_time_used << std::endl << "Avarage time per check: " << cpu_time_used / 100000 << std::endl;

 */
    map->print(cells3);
    return 0;
}

