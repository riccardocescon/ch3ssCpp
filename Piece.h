#ifndef PIECE_H

#include <vector>
#include "./Utils.cpp"
class Piece
{
public:
    Piece();
    ~Piece();
    int getValue();
    virtual std::vector<std::vector<int>> getMoves(int position, int mapLength) = 0;
protected:
    Utils::PieceType value;
};

#endif
