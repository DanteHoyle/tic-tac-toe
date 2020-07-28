#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../lib/board.hpp"

BoardSquare::BoardSquare(int x, int y)
{
    xPos = x;
    yPos = y;

    state = EMPTY;
    updateTexture();

    sprite.setPosition(xPos, yPos);
}

BoardSquare::~BoardSquare()
{
    currentTexture = NULL;
}

void BoardSquare::updateTexture()
{
    switch (state)
    {
    case EMPTY:
        currentTexture = &empty_Texture;
        break;
    case X:
        currentTexture = &x_Texture;
        break;
    case O:
        currentTexture = &o_Texture;
        break;

    default:
        std::cout << "Error, invalid board square state!\n";
        break;
    }

    sprite.setTexture(*currentTexture);
}

void BoardSquare::setState(int newState)
{
    state = newState;
    updateTexture();
}

void BoardSquare::display(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void BoardSquare::highlight()
{
    sprite.setColor(sf::Color::Yellow);
}

bool setupTextures()
{
    bool success = true;

    if (!BoardSquare::empty_Texture.loadFromFile("med/empty.png"))
    {
        std::cout << "Error, could not load empty.png\n";
        success = false;
    }

    if (!BoardSquare::x_Texture.loadFromFile("med/x.png"))
    {
        std::cout << "Error, could not load empty.png\n";
        success = false;
    }

    if (!BoardSquare::o_Texture.loadFromFile("med/o.png"))
    {
        std::cout << "Error, could not load empty.png\n";
        success = false;
    }

    return success;
}

sf::Texture BoardSquare::empty_Texture;
sf::Texture BoardSquare::x_Texture;
sf::Texture BoardSquare::o_Texture;

bool initialized = setupTextures();