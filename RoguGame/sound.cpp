#include "sound.hpp"

SoundEvent::SoundEvent()
{
    for(int i=0;i<10;i++)
    {
        buffer[i].loadFromFile("Sounds\\"+path[i]);
    }
}

void SoundEvent::update()
{
    if(sound.getStatus()!=sf::Sound::Playing && !toPlay.empty())
    {
        sound.setBuffer(buffer[toPlay.front()]);
        sound.play();
        toPlay.pop();
    }
}

void SoundEvent::pushToQueue(int numberOfSound)
{
    toPlay.push(numberOfSound);
}

void SoundEvent::playNow(int numberOfSound)
{
    while(toPlay.empty()!=true)
        toPlay.pop();
    sound.setBuffer(buffer[numberOfSound]);
    sound.play();

}
