#ifndef GATE_HPP_INCLUDED
#define GATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Gate
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Vector2f pos;
public:
    Gate(sf::RenderWindow &window1);
    void Update(sf::Vector2f charPos);
    void setPosition(sf::Vector2f newPos);
    static bool show;
};

#endif // GATE_HPP_INCLUDED
