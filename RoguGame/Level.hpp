#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include <vector>
#include <string>
#include <map>
#include <SFML/Window.hpp>

#include "Enemy.hpp"
#include "sound.hpp"
#include "weapon.hpp"
#include "Gate.hpp"

class enemy;
class heavy_enemy;
class axe_enemy;
class shovel_enemy;

class Level_Class
{
private:
    static const int NumberLevels=2;
    static const int TypesOfCharakters=5;
    struct levelConfig
    {
        bool usingCharakters[TypesOfCharakters];
    };
    std::map<int,levelConfig>levels;
    std::vector<enemy*>&chochol;
    std::vector<enemy*>&mushroom;
    std::vector<heavy_enemy*>&chocholP;
    std::vector<axe_enemy*>&chocholA;
    std::vector<shovel_enemy*>&chocholS;
    friend class background;
public:
    static int level;
    static int toNextLevel[NumberLevels];
    bool operator++();
    void Update(sf::Vector2f Camera,SoundEvent *Sound,Gate &gate,double FTime);
    Level_Class(std::vector<enemy*>&t1,std::vector<enemy*>&t2,std::vector<heavy_enemy*>&t3,std::vector<axe_enemy*>&t4,std::vector<shovel_enemy*>&t5,sf::RenderWindow &window);
};

#endif // LEVEL_HPP_INCLUDED
