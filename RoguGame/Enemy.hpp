#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

#include "crafting.hpp"
#include "equipment.hpp"
#include "weapon.hpp"
#include "vectors.hpp"

class enemy
{
protected:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt,txt_dmg;
    sf::Vector2f pos;
    sf::Clock time;
    sf::Clock dmgTime;
    bool noTxt;
    double calcDir(sf::Vector2f characterPos);
    double alpha,a,b,c;
    void collision(sf::Vector2f charPos);
    void injur();
    void ini(std::string path,std::string path2);
    const int DMG_rate=5;
public:
    float HP;
    enemy(sf::RenderWindow &window1,std::string path,std::string path2):window(window1)
    {
        ini(path,path2);
        HP=100;
        c=0.8;
    }
    void Update(sf::Vector2f characterPos);
};

class heavy_enemy
    :public enemy
{
protected:
    const int DMG_rate=8;
public:
    heavy_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=150;
        c=0.5;
    }
};
class axe_enemy
    :public enemy
{
protected:
    const int DMG_rate=15;
public:
    axe_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=150;
        c=0.4;
    }
};
class shovel_enemy
    :public enemy
{
protected:
    const int DMG_rate=10;
public:
    shovel_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=100;
        c=0.6;
    }
};

#endif // ENEMY_HPP_INCLUDED
