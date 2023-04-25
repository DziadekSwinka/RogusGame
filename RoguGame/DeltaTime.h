#ifndef DELTATIME_H_INCLUDED
#define DELTATIME_H_INCLUDED

#include <SFML/Graphics.hpp>


struct
{
    sf::Clock TimeAsSec;
    sf::Time PrevFrameTime;
    double FrameTime()
    {
        float Sec=PrevFrameTime.asSeconds();
        float TimeX=600;
        double ret={1.f};
        ret=Sec*TimeX;
        return ret;
    }
}deltaTime;

#endif // DELTATIME_H_INCLUDED
