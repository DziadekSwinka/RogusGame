#ifndef LEVEL_CPP_INCLUDED
#define LEVEL_CPP_INCLUDED

#include "Level.hpp"

bool Level_Class::operator++()
{
    if(level<NumberLevels)
    {
        level+=1;
        return true;
    }else return false;

}

#endif // LEVEL_CPP_INCLUDED
