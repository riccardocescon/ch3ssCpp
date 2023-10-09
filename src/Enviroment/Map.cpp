#include "../../include/Enviroment/Map.h"

Map::Map(){
    this->layers = std::vector<Layer*>();
    height = 1;
}

Map::Map(int height){
    this->layers = std::vector<Layer*>();
    this->height = height;
}

Map::Map(std::vector<Layer*> layers){
    this->layers = layers;
    height = layers.size();
    setCellsFreeSpace();
}

Map::~Map(){
    for (int i = 0; i < this->layers.size(); i++)
        delete this->layers[i];
}

//For every cell in every layer, set how many free spaces are above it
void Map::setCellsFreeSpace(){
    int free = 0;
    Cell* checkingCell = this->layers[0]->getCell(0);
    for(int pos = 0; pos < pow(this->getLayer(0)->getSize(), 2); pos++){
        free = 0;
        checkingCell = NULL;
        for(int layer = 0; layer < this->height; layer++){
            if(this->layers[layer]->getCell(pos) != NULL){
                //if it is the last layer always put it free
                if(layer == this->height-1)
                    this->layers[layer]->getCell(pos)->setFreeUpperSpace(Utils::INFINSPACE);
                if(checkingCell != NULL)
                    checkingCell->setFreeUpperSpace(free);
                free = 0;
                checkingCell = this->layers[layer]->getCell(pos);
            }else free++;
        }
        if(free != 0) checkingCell->setFreeUpperSpace(Utils::INFINSPACE);
    }
}

std::vector<Layer*> Map::getLayers(){
    return this->layers;
}

void Map::pushLayers(std::vector<Layer*> layers){
    for (int i = 0; i < layers.size(); i++)
        this->layers.push_back(layers[i]);
}

void Map::addLayer(Layer *layer){
    this->layers.push_back(layer);
}

void Map::print(){
    std::cout << std::endl;
    for (int i = 0; i < this->layers.size(); i++){
        this->layers[i]->print();
    }
}

void Map::print(std::vector<Cell*> cells){
    std::cout << std::endl;
    for (int i = 0; i < this->layers.size(); i++){
        this->layers[i]->print(cells);
    }
}

Layer *Map::getLayer(int pos){
    return this->layers[pos];
}

int Map::getHeight(){
    return this->height;
}

void Map::setLayer(int pos, Layer *layer){
    this->layers[pos] = layer;
}

Layer *Map::findLayer(CPiece* piece){
    for (int i = 0; i < this->layers.size(); i++){
        for (int j = 0; j < this->layers[i]->getCells().size(); j++){
            if (this->layers[i]->getCells()[j]->getPiece() == piece){
                return this->layers[i];
            }
        }
    }
    return NULL;
}

Layer *Map::findLayer(Cell* cell){
    for (int i = 0; i < this->layers.size(); i++){
        for (int j = 0; j < this->layers[i]->getCells().size(); j++){
            if (this->layers[i]->getCells()[j] == cell){
                return this->layers[i];
            }
        }
    }
    return NULL;
}

void Map::printLayer(int pos){
    this->layers[pos]->print();
}

void Map::printLayers(){
    for (int i = 0; i < this->layers.size(); i++){
        this->layers[i]->print();
    }
}

int Map::getLayerPos(Layer* layer){
    for (int i = 0; i < this->layers.size(); i++){
        if (this->layers[i] == layer){
            return i;
        }
    }
    return -1;
}