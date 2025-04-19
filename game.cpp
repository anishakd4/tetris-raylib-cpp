#include "game.h"
#include <random>
#include "iostream"

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    //nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock(){
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    std::random_device rd;  // Seed source
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dist(0, blocks.size() - 1); // Range 1-100

    int randomIndex = dist(gen);

    std::cout<< randomIndex << std::endl;
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;

    // int randomIndex = rand() % blocks.size();
    // Block block = blocks[randomIndex];
    // blocks.erase(blocks.begin() + randomIndex);
    // return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch(keyPressed){
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

void Game::MoveBlockLeft(){
    currentBlock.Move(0, -1);
    if(isBlockOutside()){
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight(){
    currentBlock.Move(0, 1);
    if(isBlockOutside()){
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if(isBlockOutside()){
        currentBlock.Move(-1, 0);
    }
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.isCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if(isBlockOutside()){
        currentBlock.UndoRotation();
    }
}
