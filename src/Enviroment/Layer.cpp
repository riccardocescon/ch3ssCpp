#include "../../include/Enviroment/Layer.h"

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
        if(i%this->size == this->size-1)
            std::cout << std::endl;

    }
    std::cout << std::endl;
}

void Layer::print(std::vector<Cell*> cells){
    bool skip = false;
    for(int i = 0; i < this->cells.size(); i++){
        if(this->cells[i] == NULL){
            std::cout << "[] ";
            if(i%this->size == this->size-1)
            std::cout << std::endl;
            continue;
        }
        for(auto cell: cells){
            //print yellow if cell is in the vector
            if(this->cells[i] == cell){
                    std::cout << "\033[1;35m";
                    std::cout << this->cells[i]->getSymbol() << " ";
                    std::cout << "\033[0m";
                skip = true;
                break;
            }
        }
        if(skip){
            skip = false;
        }else if(this->cells[i]->getPiece() != NULL){
            std::cout << "\033[1;31m";
            std::cout << this->cells[i]->getSymbol() << " ";
            std::cout << "\033[0m";
        }else{
            std::cout << this->cells[i]->getSymbol() << " ";
        }
        if(i%this->size == this->size-1)
            std::cout << std::endl;

    }
    std::cout << std::endl;
}

Cell *Layer::getCell(int pos){
    return this->cells[pos];
}

int Layer::getSize(){
    return this->size;
}