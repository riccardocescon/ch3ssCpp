#include "./Cell.h"
#include <vector>

class Layer{
    private:
        std::vector<Cell*> cells;
    public:
        Layer();
        Layer(std::vector<Cell*> cells);
        ~Layer();
        std::vector<Cell*> getCells();
        void pushCells(std::vector<Cell*> cells);
        void addCell(Cell *cell);
        void print();
        Cell *getCell(int pos);
        void setCell(int pos, Cell *cell);
};