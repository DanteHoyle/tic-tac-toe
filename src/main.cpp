/*
    simple SFML 2.0 tic-tac-toe game
    made by Dante Hoyle July 2020
*/

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../lib/board.hpp"
#include "../lib/gamelogic.hpp"

// Globals
const int FRAMERATE = 60;
const int SQUARE_GAP = 8;
const int BOARD_SIZE = 800;

int main()
{
    // create Window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tic-Tac-Toe");
    window.setFramerateLimit(FRAMERATE);

    // create a couple squares to test
    // BoardSquare testing(0, 0);
    std::vector<BoardSquare> v_squares;
    std::vector<sf::RectangleShape> v_lines;

    // game vars
    int currentTurn = X;
    bool gameIsOver = false;

    // create lines
    v_lines.push_back(sf::RectangleShape(sf::Vector2f(SQUARE_GAP / 2, 800.f)));
    v_lines.push_back(sf::RectangleShape(sf::Vector2f(SQUARE_GAP / 2, 800.f)));
    v_lines.push_back(sf::RectangleShape(sf::Vector2f(800.f, SQUARE_GAP / 2)));
    v_lines.push_back(sf::RectangleShape(sf::Vector2f(800.f, SQUARE_GAP / 2)));

    for (int i = 0; i < 4; i++)
    {
        v_lines[i].setFillColor(sf::Color::White);
    }
    
    v_lines[0].setPosition(BOARD_SIZE / 3, 0);
    v_lines[1].setPosition(2 * BOARD_SIZE / 3, 0);
    v_lines[2].setPosition(0, BOARD_SIZE / 3);
    v_lines[3].setPosition(0, 2 * BOARD_SIZE / 3);
    
    // fill square vector with squares
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x = ((j + 1) * SQUARE_GAP) + (j * SQUARE_WIDTH);
            int y = ((i + 1) * SQUARE_GAP) + (i * SQUARE_HEIGHT);

            v_squares.push_back(BoardSquare(x, y)); 
        }
    }

    // Main Loop
    while (window.isOpen())
    {
        // Event Loop
        sf::Event e;
        while (window.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::Closed: 
                window.close();
                break;
            
            case sf::Event::MouseButtonPressed:
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if (gameIsOver)
                        break;

                    for (int i = 0; i < 9; i++)
                    {
                        if (pointBoxCollide(e.mouseButton.x, e.mouseButton.y, v_squares[i].xPos, v_squares[i].yPos, SQUARE_WIDTH, SQUARE_HEIGHT) && v_squares[i].state == EMPTY)
                        {
                            v_squares[i].setState(currentTurn);
                            
                            if (currentTurn == X)
                                currentTurn = O;
                            else
                                currentTurn = X;
                        }
                    }

                    if (checkWin(v_squares) != NO_WINNER)
                        gameIsOver = true;

                }
                // clear the board
                else if (e.mouseButton.button == sf::Mouse::Right)
                {
                    gameIsOver = false;
                    currentTurn = X;
                    resetBoard(v_squares);
                }
                break;
            }   
        }

        // ------------------ Draw Loop -------------------------------

        // Clears the screen
        window.clear(sf::Color::Black);

        // Draw the squares
        for (int i = 0; i < 9; i++)
        {
            v_squares[i].display(window);
        }

        // Draw the board lines
        for (int i = 0; i < 4; i++)
        {
            window.draw(v_lines[i]);
        }

        // flips the display
        window.display();
    }

}

