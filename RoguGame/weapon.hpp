#ifndef WEAPON_HPP_INCLUDED
#define WEAPON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "ammunition.hpp"
#include "equipment.hpp"

const float loadingTime=2.5;

class weapon
{
public:
    weapon(sf::RenderWindow &window1);
    void Update(sf::Vector2f Center);
    static std::vector<ammunition*>ammo;
    static void Destr(int i);
private:
    sf::Clock Loading;
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Font GochiHand_Regular;
    sf::Text time;
    int fix;
};
class hand_weapon
{
public:
    void Update(sf::Vector2f Center);
    hand_weapon(sf::RenderWindow &window1,std::string path);
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Clock Loading;
};

#endif // WEAPON_HPP_INCLUDED
