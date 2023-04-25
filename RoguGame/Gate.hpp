#ifndef GATE_HPP_INCLUDED
#define GATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Level.hpp"

using namespace std;

class Gate
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Text text;
    sf::Font GochiHand_Regular;
    sf::Clock clock;
public:
    Gate(sf::RenderWindow &window1);
    void Update(sf::Vector2f charPos);
    void setPosition(sf::Vector2f newPos);
    static bool show;
    static sf::Vector2f startPos;
};

#endif // GATE_HPP_INCLUDED
