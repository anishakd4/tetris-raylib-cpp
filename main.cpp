#include<iostream>
#include "game.h"

int main(){
    Color darkblue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    LBlock lblock = LBlock();

    while(WindowShouldClose() == false){

        game.HandleInput();

        BeginDrawing();

        ClearBackground(darkblue);

        game.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}