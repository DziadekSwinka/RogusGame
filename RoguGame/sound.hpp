#ifndef SOUND_HPP_INCLUDED
#define SOUND_HPP_INCLUDED

#include <SFML/Audio.hpp>
#include <queue>
class SoundEvent
{
private:
    std::string path[10]={  "100zMatmy.wav",
                            "360stopni.wav",
                            "uposledzony.wav",
                            "eeee paraparubuja.wav",
                            "Gangaritus.wav",
                            "ja sie swietnie bawie.wav",
                            "tak.wav",
                            "a Natalia ma C2 prawie.wav",
                            "termomobil.wav",
                            "KupilemCos.wav"};
    sf::SoundBuffer buffer[10];
    std::queue <int> toPlay;
    sf::Sound sound;
public:
    SoundEvent();
    void update();
    void pushToQueue(int numberOfSound);
    void playNow(int numberOfSound);

};

#endif // SOUND_HPP_INCLUDED
