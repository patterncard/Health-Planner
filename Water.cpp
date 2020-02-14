#include "Water.h"
#include "Addition.h"
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
    return SumArray(glassesOfWaterVolume);
};
