#pragma once
#include<vector>
#include<map>
#include "position.h"
#include "colors.h"

class Block {
    public:
        Block();
        void Draw();
        int id;
        void Move(int rows, int columns);
        void Rotate();
        void UndoRotation();
        std::vector<Position> GetCellPositions();
        std::map<int, std::vector<Position>> cells;
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int columnOffset;
};