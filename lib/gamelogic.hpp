#pragma once
#include <vector>
#include "board.hpp"

enum winner {
    NO_WINNER,
    X_WINNER,
    O_WINNER
};

// return 0 for no win, 1 for X win, 2 for O win
int checkWin(std::vector<BoardSquare> &gameBoard);

// function which takes a point on the screen (px, py) and sees if it falls
// in a box (bx, by, bw, bh)
bool pointBoxCollide(double px, double py, double bx, double by, double bw, double bh);

void resetBoard(std::vector<BoardSquare> &gameBoard);