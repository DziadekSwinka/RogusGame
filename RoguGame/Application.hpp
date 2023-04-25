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
#include "Gate.hpp"
#include "DeltaTime.h"

void prep_txt_items();
void Application();

struct
{
    float Speed=0.001;
    float zoom=5.f;
    sf::Vector2i DIM;
}Config;



#endif // APPLICATION_HPP_INCLUDED
