#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "progressBar.hpp"
#include "sound.hpp"
#include "vectors.hpp"
#include "items.hpp"
#include "background.hpp"
#include "Enemy.hpp"
#include "crafting.hpp"
#include "Level.hpp"

void prep_txt_items();
void Application();

struct
{
    float Speed=0.001;
    float deltaTime(float TimeAsSec)
    {
        const float TimeX=600;
        float ret={1.f};
        ret=TimeAsSec*TimeX;
        return ret;
    }
    sf::Vector2i DIM;
    float zoom=5.f;

}Config;



#endif // APPLICATION_HPP_INCLUDED
