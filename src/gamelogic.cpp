#include "../lib/gamelogic.hpp"

int checkWin(std::vector<BoardSquare> &gameBoard)
{
    // check horizontal lines
    for (int i = 0; i < 3; i++)
    {
        int row = i * 3;

        if (gameBoard[row].state == X && gameBoard[row + 1].state == X && gameBoard[row + 2].state == X)
        {
            gameBoard[row].highlight();
            gameBoard[row + 1].highlight();
            gameBoard[row + 2].highlight();

            return X_WINNER;
        }
        else if (gameBoard[row].state == O && gameBoard[row + 1].state == O && gameBoard[row + 2].state == O)
        {
            gameBoard[row].highlight();
            gameBoard[row + 1].highlight();
            gameBoard[row + 2].highlight();

            return O_WINNER;
        }
    }

    // check vertical lines
    for (int i = 0; i < 3; i++)
    {
        if (gameBoard[i].state == X && gameBoard[i + 3].state == X && gameBoard[i + 6].state == X)
        {
            gameBoard[i].highlight();
            gameBoard[i + 3].highlight();
            gameBoard[i + 6].highlight();

            return X_WINNER;
        }
        else if (gameBoard[i].state == O && gameBoard[i + 3].state == O && gameBoard[i + 6].state == O)
        {
            gameBoard[i].highlight();
            gameBoard[i + 3].highlight();
            gameBoard[i + 6].highlight();

            return O_WINNER;
        }
    }

    // check diag
    // x..
    // .x.
    // ..x
    if (gameBoard[0].state == X && gameBoard[4].state == X && gameBoard[8].state == X)
    {
        gameBoard[0].highlight();
        gameBoard[4].highlight();
        gameBoard[8].highlight();

        return X_WINNER;
    }
    else if (gameBoard[0].state == O && gameBoard[4].state == O && gameBoard[8].state == O)
    {
        gameBoard[0].highlight();
        gameBoard[4].highlight();
        gameBoard[8].highlight();

        return O_WINNER;
    }

    // checks diag
    // ..x
    // .x.
    // x..
    if (gameBoard[2].state == X && gameBoard[4].state == X && gameBoard[6].state == X)
    {
        gameBoard[2].highlight();
        gameBoard[4].highlight();
        gameBoard[6].highlight();

        return X_WINNER;
    }
    else if (gameBoard[2].state == O && gameBoard[4].state == O && gameBoard[6].state == O)
    {
        gameBoard[2].highlight();
        gameBoard[4].highlight();
        gameBoard[6].highlight();

        return O_WINNER;
    }
    

    // no wins detected
    return NO_WINNER;
}

bool pointBoxCollide(double px, double py, double bx, double by, double bw, double bh)
{
    if (px < bx)
        return false;           // if x point is less than the left edge
    else if (px > bx + bw)
        return false;           // if x point is greater than the right edge
    else if (py < by)
        return false;           // if y point is less than the top edge
    else if (py > by + bh)
        return false;           // if y point is greater than bottom edge

    // if it falls 
    return true;
}

void resetBoard(std::vector<BoardSquare> &gameBoard)
{
    for (int i = 0; i < 9; i++)
    {
        gameBoard[i].sprite.setColor(sf::Color::White);
        gameBoard[i].setState(EMPTY);
    }
}