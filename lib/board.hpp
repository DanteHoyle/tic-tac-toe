#pragma once
#include <SFML/Graphics.hpp>

enum {
    EMPTY,
    X,
    O
};

const int SQUARE_WIDTH = 256;
const int SQUARE_HEIGHT = 256;

bool setupTextures();

class BoardSquare
{
public:
    BoardSquare(int x, int y);
    ~BoardSquare();

    sf::Texture* currentTexture = NULL;
    sf::Sprite sprite;

    int xPos, yPos;
    int state;

    void updateTexture();
    void setState(int newState);
    void display(sf::RenderWindow &window);
    void highlight();

    static sf::Texture empty_Texture;
    static sf::Texture x_Texture;
    static sf::Texture o_Texture;
};