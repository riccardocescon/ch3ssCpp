#ifndef TESTING
#include <iostream>
#include <vector>
#include "../include/API/fsm.h"
#include "../include/Pieces/Bishop.h"
#include "../include/Pieces/Rook.h"
#include "../include/Pieces/Pawn.h"
#include "../include/Pieces/Knight.h"

//    a  b  c  d  e  f  g  h
// -----------------------
// 1 | 00 01 02 03 04 05 06 07
// 2 | 08 09 10 11 12 13 14 15
// 3 | 16 17 18 19 20 21 22 23
// 4 | 24 25 26 27 28 29 30 31
// 5 | 32 33 34 35 36 37 38 39
// 6 | 40 41 42 43 44 45 46 47
// 7 | 48 49 50 51 52 53 54 55
// 8 | 56 57 58 59 60 61 62 63

int main()
{
    FSM fsm;
    Api_logic api;
    std::vector<Cell *> cells, cells1, cells2;
    for (int i = 0; i < 64; i++)
    {
        cells.push_back(new Cell(i, 8));
    }
    for (int i = 0; i < 8; i++)
    {
        cells1.push_back(new Cell(i, 8));
    }
    for (int i = 8; i < 55; i++)
    {
        if (i % 8 == 0 || i % 8 == 7)
            cells1.push_back(new Cell(i, 8));
        else
            cells1.push_back(NULL);
    }
    for (int i = 55; i < 64; i++)
    {
        cells1.push_back(new Cell(i, 8));
    }
    for (int i = 0; i < 64; i++)
    {
        if (i == 30 || i == 14 || i == 18)
            // if(i == 30)
            cells2.push_back(new Cell(i, 8));
        else
            cells2.push_back(NULL);
    }
    Bishop *bishop = new Bishop(Utils::Color::BLACK);
    Rook *rook1 = new Rook(Utils::Color::BLACK);
    Rook *rook2 = new Rook(Utils::Color::BLACK);
    Pawn *pawn = new Pawn(Utils::Color::WHITE);
    Knight *knight = new Knight(Utils::Color::WHITE);
    cells[36]->setPiece(bishop);
    cells[44]->setPiece(rook1);
    cells2[18]->setPiece(rook2);
    cells[11]->setPiece(pawn);
    cells[45]->setPiece(knight);
    std::vector<Layer *> layer{new Layer(cells), new Layer(cells1), new Layer(cells2)};
    Map *map = new Map(layer);
    api.setMap(map);
    std::vector<Cell *> cells3 = api.selectCells(cells[45]);

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    for (int i = 100; i < 500000; i++)
        api.selectCells(cells2[30]);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout << "Time: " << cpu_time_used << std::endl
              << "Avarage time per check: " << cpu_time_used / 500000 << std::endl;

    map->print(cells3);
    return 0;
}
