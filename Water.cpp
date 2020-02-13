#include "Water.h"
#include <iostream>

Water::Water()
{
    std::cout << "Initialized Water Module" << std::endl;
}

void Water::addGlasses(int glass)
{
    glassesOfWaterVolume.push_back(glass);
};

int Water::sumAllGlassesVolume()
{
    int volume = 0;
    for (int i = 0; i < glassesOfWaterVolume.size(); i++)
    {
        volume += glassesOfWaterVolume[i];
    }
    return volume;
};