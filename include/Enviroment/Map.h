#ifndef MAP_H

#include "./Layer.h"

class Map{
    private:
        std::vector<Layer*> layers;
        int height;
    public:
        Map();
        Map(int height);
        Map(std::vector<Layer*> layers);
        ~Map();
        void setCellsFreeSpace();
        std::vector<Layer*> getLayers();
        void pushLayers(std::vector<Layer*> layers);
        void addLayer(Layer *layer);
        void print();
        void print(std::vector<Cell*> cell);
        Layer *getLayer(int pos);
        int getHeight();
        void setLayer(int pos, Layer *layer);
        Layer* findLayer(CPiece* piece);
        Layer* findLayer(Cell* cell);
        int getLayerPos(Layer* layer);
        void printLayer(int pos);
        void printLayers();
};

#endif