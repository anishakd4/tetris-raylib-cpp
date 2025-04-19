#include<iostream>
#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"

int main(){
    Color darkblue = {44, 44, 127, 255};
    
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    LBlock lblock = LBlock();

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(darkblue);

        grid.Draw();
        lblock.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}