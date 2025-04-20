#pragma once
#include<vector>
#include "raylib.h"

class Grid {
    public:
        Grid();
        void Initialize();
        void Print();
        int grid[20][10];
        bool isCellOutside(int row, int column);
        bool isCellEmpty(int row, int column);
        int ClearFullRows();
        void Draw();
    private:
        bool isRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};