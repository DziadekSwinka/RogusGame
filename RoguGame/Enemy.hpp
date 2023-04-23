#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "crafting.hpp"
#include "equipment.hpp"
#include "weapon.hpp"
#include "vectors.hpp"
#include "sound.hpp"
#include "throwedItem.hpp"

class enemy
{
protected:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt,txt_dmg;
    sf::Vector2f pos;
    sf::Clock time;
    sf::Clock dmgTime,updateTime;
    bool noTxt;
    double calcDir(sf::Vector2f characterPos);
    double alpha,a,b,c;
    void collision(sf::Vector2f charPos,SoundEvent *Sound);
    void injur(SoundEvent *Sound);
    void ini(std::string path,std::string path2);
    const unsigned int DMG_rate=5;
    const float AttackTime=4;
public:
    float HP;
    enemy(sf::RenderWindow &window1,std::string path,std::string path2):window(window1)
    {
        ini(path,path2);
        HP=100;
        c=0.8;
    }
    virtual void Update(sf::Vector2f characterPos,SoundEvent *Sound);
};

class heavy_enemy
    :public enemy
{
protected:
    const int DMG_rate=15;
    const float AttackTime=5;
public:
    heavy_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=150;
        c=0.6;
    }
};
class axe_enemy
    :public enemy
{
protected:
    const int DMG_rate=15;
    const float AttackTime=2;
public:
    axe_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=150;
        c=0.5;
    }
};
class shovel_enemy
    :public enemy
{
protected:
    const int DMG_rate=10;
    const float AttackTime=1;
public:
    shovel_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=100;
        c=0.8;
    }
};
class mush_enemy
    :public enemy
{
protected:
    const int DMG_rate=10;
    const float AttackTime=6;
    static std::vector<ThrowedItem*>throwed;
public:
    mush_enemy(sf::RenderWindow &window1,std::string path,std::string path2):enemy(window1,path,path2)
    {
        ini(path,path2);
        HP=100;
        c=0.8;
        sprite.setScale(0.4,0.45);
    }
    virtual void Update(sf::Vector2f characterPos,SoundEvent *Sound);
};

#endif // ENEMY_HPP_INCLUDED
