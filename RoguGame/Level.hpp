#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include <vector>
#include <string>
#include <map>
#include <SFML/Window.hpp>

#include "Enemy.hpp"
#include "sound.hpp"

class Level_Class
{
private:
    static int level;
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
    bool operator++();
    void Update(sf::Vector2f Camera,SoundEvent *Sound);
    Level_Class(std::vector<enemy*>&t1,std::vector<enemy*>&t2,std::vector<heavy_enemy*>&t3,std::vector<axe_enemy*>&t4,std::vector<shovel_enemy*>&t5,sf::RenderWindow &window);
};

#endif // LEVEL_HPP_INCLUDED
