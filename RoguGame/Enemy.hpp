#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

#include "crafting.hpp"
#include "equipment.hpp"
#include "weapon.hpp"


class enemy
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Vector2f pos;
    sf::Clock time;
    bool isAlive;
    double calcDir(sf::Vector2f characterPos);
    double alpha,a,b,c;
    void collision();
public:
    float HP;
    enemy(sf::RenderWindow &window1,std::string path):window(window1)
    {
        isAlive=true;
        HP=100;
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(2.f,2.f);
        sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
        pos.x=(rand()%34700)+2500;
        pos.y=(rand()%34700)+2500;
        c=0.5;
    }
    void Update(sf::Vector2f characterPos);
};

#endif // ENEMY_HPP_INCLUDED
