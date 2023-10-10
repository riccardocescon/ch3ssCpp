#ifndef MOVES_H

#include <vector>

#pragma once

namespace Moves
{

    inline std::vector<std::vector<int>> diagonals(int position, int mapLength)
    {
        int secondDiagonal = mapLength + 1, mainDiagonal = mapLength - 1;
        std::vector<int> validCells;
        std::vector<std::vector<int>> validCellsByDirection;
        // Bottom left
        for (int checkPosition = position; checkPosition > 0; checkPosition -= secondDiagonal)
        {
            if (((checkPosition + 1) % mapLength == 0))
                break;
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        validCells.clear();

        // Bottom right
        for (int checkPosition = position; checkPosition > 0; checkPosition -= mainDiagonal)
        {
            if (((checkPosition + 1) % mapLength == 1))
                break;
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        validCells.clear();

        // Top right
        for (int checkPosition = position; checkPosition < mapLength * mapLength; checkPosition += secondDiagonal)
        {
            if (((checkPosition + 1) % mapLength == 1))
                break;
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        validCells.clear();

        // Top left
        for (int checkPosition = position; checkPosition < mapLength * mapLength; checkPosition += mainDiagonal)
        {
            if (((checkPosition + 1) % mapLength == 0))
                break;
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        return validCellsByDirection;
    };

    inline std::vector<std::vector<int>> straights(int position, int mapLength)
    {
        std::vector<int> validCells;
        std::vector<std::vector<int>> validCellsByDirection;
        // Bottom
        for (int checkPosition = position; checkPosition > 0; checkPosition -= mapLength)
        {
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        validCells.clear();

        // Right
        for (int checkPosition = position; checkPosition > 0; checkPosition--)
        {
            if (((checkPosition + 1) % mapLength == 0))
                break;
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        validCells.clear();

        // Top
        for (int checkPosition = position; checkPosition < mapLength * mapLength; checkPosition += mapLength)
        {
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        validCells.clear();

        // Left
        for (int checkPosition = position; checkPosition < mapLength * mapLength; checkPosition++)
        {
            if (((checkPosition) % mapLength == 0))
                break;
            validCells.push_back(checkPosition);
        }
        validCellsByDirection.push_back(validCells);
        return validCellsByDirection;
    };

    inline std::vector<std::vector<int>> neighbor(int position, int mapLength)
    {
        int secondDiagonal = mapLength + 1, mainDiagonal = mapLength - 1;
        std::vector<int> valdCells;
        std::vector<std::vector<int>> validCellsByDirection;
        if (position - mapLength >= 0)
            validCellsByDirection.push_back(std::vector<int>(1, position - mapLength));
        if (position - 1 >= 0 && (position - 1) % mapLength != mapLength - 1)
            validCellsByDirection.push_back(std::vector<int>(1, position - 1));
        if (position + mapLength < mapLength * mapLength)
            validCellsByDirection.push_back(std::vector<int>(1, position + mapLength));
        if (position + 1 < mapLength * mapLength && (position + 1) % mapLength != 0)
            validCellsByDirection.push_back(std::vector<int>(1, position + 1));
        if (position - secondDiagonal >= 0 && (position - secondDiagonal + 1) % mapLength != 0)
            validCellsByDirection.push_back(std::vector<int>(1, position - secondDiagonal));
        if (position - mainDiagonal >= 0 && (position - mainDiagonal) % mapLength != mapLength - 1)
            validCellsByDirection.push_back(std::vector<int>(1, position - mainDiagonal));
        if (position + secondDiagonal < mapLength * mapLength && (position + secondDiagonal) % mapLength != 0)
            validCellsByDirection.push_back(std::vector<int>(1, position + secondDiagonal));
        if (position + mainDiagonal < mapLength * mapLength && (position + mainDiagonal + 1) % mapLength != 0)
            validCellsByDirection.push_back(std::vector<int>(1, position + mainDiagonal));
        return validCellsByDirection;
    };

    inline std::vector<std::vector<int>> pawn(int position, int mapLength, int limit, int direction)
    {
        int secondDiagonal = mapLength + 1, mainDiagonal = mapLength - 1;
        std::vector<int> validCells;
        std::vector<std::vector<int>> validCellsByDirection;
        int nexCell = 0;
        if (direction == 1)
        {
            for (int i = 0; (nexCell = (position - i * mapLength)) >= 0 && i <= limit; i++)
            {
                validCells.push_back(nexCell);
            }
            validCellsByDirection.push_back(validCells);
            validCells.clear();
            if ((position - mainDiagonal) % mapLength != 0 && (position - mainDiagonal) >= 0){
                validCells.push_back(position);
                validCells.push_back(position - mainDiagonal);
                validCellsByDirection.push_back(validCells);
                validCells.clear();
            }
            if ((position - secondDiagonal) % mapLength != mapLength - 1 && (position - secondDiagonal) >= 0){
                validCells.push_back(position);
                validCells.push_back(position - secondDiagonal);
                validCellsByDirection.push_back(validCells);
                validCells.clear();
            }
        }
        else
        {
            for (int i = 0; (nexCell = (position + i * mapLength)) < mapLength * mapLength && i <= limit; i++)
            {
                validCells.push_back(nexCell);
            }
            validCellsByDirection.push_back(validCells);
            validCells.clear();
            if ((position + mainDiagonal) % mapLength != mapLength - 1 && (position + mainDiagonal) < mapLength * mapLength){
                validCells.push_back(position);
                validCells.push_back(position + mainDiagonal);
                validCellsByDirection.push_back(validCells);
                validCells.clear();
            }
            if ((position + secondDiagonal) % mapLength != 0 && (position + secondDiagonal) < mapLength * mapLength){
                validCells.push_back(position);
                validCells.push_back(position + secondDiagonal);
                validCellsByDirection.push_back(validCells);
                validCells.clear();
            }
        }
        return validCellsByDirection;
    };

    inline std::vector<std::vector<int>> knight(int position, int mapLength){
        std::vector<int> validCells, validCells2;
        std::vector<std::vector<int>> validCellsByDirection;
        int targetCell = 0;
        //FL
        if ((position - 2 * mapLength - 1) >= 0 && (position - 2 * mapLength - 1) % mapLength != mapLength - 1){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position - 2 * mapLength - 1;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position - i * mapLength - 1);
                validCells2.push_back(position - (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //FR
        if((position - 2 * mapLength + 1) >= 0 && (position - 2 * mapLength + 1) % mapLength != 0){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position - 2 * mapLength + 1;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position - i * mapLength + 1);
                validCells2.push_back(position - (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //LF
        if((position - mapLength - 2) >= 0 && (position - mapLength - 2) % mapLength != mapLength - 1){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position - mapLength - 2;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position - i - 2);
                validCells2.push_back(position - (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //RF
        if((position - mapLength + 2) >= 0 && (position - mapLength + 2) % mapLength != 0){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position - mapLength + 2;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position - i + 2);
                validCells2.push_back(position - (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //LB
        if((position + mapLength - 2) < mapLength * mapLength && (position + mapLength - 2) % mapLength != mapLength - 1){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position + mapLength - 2;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position + i - 2);
                validCells2.push_back(position + (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //RB
        if((position + mapLength + 2) < mapLength * mapLength && (position + mapLength + 2) % mapLength != 0){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position + mapLength + 2;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position + i + 2);
                validCells2.push_back(position + (i+1)* mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //BL
        if((position + 2 * mapLength - 1) < mapLength * mapLength && (position + 2 * mapLength - 1) % mapLength != mapLength - 1){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position + 2 * mapLength - 1;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position + i * mapLength - 1);
                validCells2.push_back(position + (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
            validCells.clear();
            validCells2.clear();
        }
        //BR
        if((position + 2 * mapLength + 1) < mapLength * mapLength && (position + 2 * mapLength + 1) % mapLength != 0){
            validCells.push_back(position);
            validCells2.push_back(position);
            targetCell = position + 2 * mapLength + 1;
            for(int i = 0; i < 2; i++){
                validCells.push_back(position + i * mapLength + 1);
                validCells2.push_back(position + (i+1) * mapLength);
            }
            validCells.push_back(targetCell);
            validCells2.push_back(targetCell);
            validCellsByDirection.push_back(validCells);
            validCellsByDirection.push_back(validCells2);
        }
        return validCellsByDirection;

    }

    inline std::vector<int> knightAttack(int position, int mapLength){
        std::vector<int> validCellsByDirection;
        int targetCell = 0;
        //FL
        if ((position - 2 * mapLength - 1) >= 0 && (position - 2 * mapLength - 1) % mapLength != mapLength - 1){
            validCellsByDirection.push_back( position - 2 * mapLength - 1);
        }
        //FR
        if((position - 2 * mapLength + 1) >= 0 && (position - 2 * mapLength + 1) % mapLength != 0){
            validCellsByDirection.push_back(position - 2 * mapLength + 1);
        }
        //LF
        if((position - mapLength - 2) >= 0 && (position - mapLength - 2) % mapLength != mapLength - 1){
            validCellsByDirection.push_back(position - mapLength - 2);
        }
        //RF
        if((position - mapLength + 2) >= 0 && (position - mapLength + 2) % mapLength != 0){
            validCellsByDirection.push_back(position - mapLength + 2);
        }
        //LB
        if((position + mapLength - 2) < mapLength * mapLength && (position + mapLength - 2) % mapLength != mapLength - 1){
            validCellsByDirection.push_back(position + mapLength - 2);
        }
        //RB
        if((position + mapLength + 2) < mapLength * mapLength && (position + mapLength + 2) % mapLength != 0){
            validCellsByDirection.push_back(position + mapLength + 2);
        }
        //BL
        if((position + 2 * mapLength - 1) < mapLength * mapLength && (position + 2 * mapLength - 1) % mapLength != mapLength - 1){
            validCellsByDirection.push_back(position + 2 * mapLength - 1);
        }
        //BR
        if((position + 2 * mapLength + 1) < mapLength * mapLength && (position + 2 * mapLength + 1) % mapLength != 0){
            validCellsByDirection.push_back(position + 2 * mapLength + 1);
        }
        return validCellsByDirection;

    }

} // namespace Moves

#endif // MOVES_H