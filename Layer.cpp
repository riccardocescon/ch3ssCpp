#include "./Layer.h"

Layer::Layer(){
    this->cells = std::vector<Cell*>();
    this->size = 8;
}

Layer::Layer(int size){
    this->cells = std::vector<Cell*>();
    this->size = size;
}

Layer::Layer(std::vector<Cell*> cells){
    this->cells = cells;
    this->size = sqrt(cells.size());
}

Layer::~Layer(){
    for(int i = 0; i < this->cells.size(); i++){
        delete this->cells[i];
    }
}

std::vector<Cell*> Layer::getCells(){
    return this->cells;
}

void Layer::pushCells(std::vector<Cell*> cells){
    for(int i = 0; i < cells.size(); i++){
        this->cells.push_back(cells[i]);
    }
}

void Layer::addCell(Cell *cell){
    this->cells.push_back(cell);
}

void Layer::print(){
    for(int i = 0; i < this->cells.size(); i++){
        //pirnt red if cell has a piece
        if(this->cells[i]->getPiece() != NULL){
            std::cout << "\033[1;31m";
            std::cout << this->cells[i]->getSymbol() << " ";
            std::cout << "\033[0m";
        }else{
            std::cout << this->cells[i]->getSymbol() << " ";
        }

    }
    std::cout << std::endl;
}

Cell *Layer::getCell(int pos){
    return this->cells[pos];
}

int Layer::getSize(){
    return this->size;
}