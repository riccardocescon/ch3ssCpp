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
    }

} // namespace Moves

#endif // MOVES_H