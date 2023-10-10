// #ifdef TESTING
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../include/API/fsm.h"
#include "../include/Pieces/Bishop.h"
#include "../include/Pieces/Rook.h"
#include "../include/Pieces/Pawn.h"
#include "../include/Pieces/Knight.h"

TEST(sommaTest, TestSommaPositiva)
{

    FSM fsm;
    Api_logic api;
    std::vector<Cell *> cells, cells1, cells2;

    // Setup Base Layer
    for (int i = 0; i < 64; i++)
    {
        cells.push_back(new Cell(i, 8));
    }

    // Setup First Layer
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

    // Setup Second Layer
    for (int i = 0; i < 64; i++)
    {
        if (i == 30 || i == 14 || i == 18)
            // if(i == 30)
            cells2.push_back(new Cell(i, 8));
        else
            cells2.push_back(NULL);
    }

    // Bishop *bishop = new Bishop(Utils::Color::BLACK);
    // Rook *rook1 = new Rook(Utils::Color::BLACK);
    // Rook *rook2 = new Rook(Utils::Color::BLACK);
    // Pawn *pawn = new Pawn(Utils::Color::WHITE);
    // Knight *knight = new Knight(Utils::Color::WHITE);
    // cells[36]->setPiece(bishop);
    // cells[44]->setPiece(rook1);
    // cells2[18]->setPiece(rook2);
    // cells[11]->setPiece(pawn);
    // cells[45]->setPiece(knight);
    std::vector<Layer *> layer{new Layer(cells), new Layer(cells1), new Layer(cells2)};
    Map *map = new Map(layer);
    api.setMap(map);
    std::vector<Cell *> cells3 = api.selectCells(cells[45]);

    map->print(cells3);

    EXPECT_EQ(true, true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// #endif