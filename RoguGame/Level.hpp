#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include <string>

class Level_Class
{
private:
    int level;
    static const int NumberLevels=2;
    static const int TypesOfCharakters=5;
    struct
    {
        int background;
        bool usingCharakters[TypesOfCharakters];
        std::string name;
    }levelConfig;
public:
    bool operator++();
};

#endif // LEVEL_HPP_INCLUDED
