#include "Calories.h"

double Calories::setCalories(double BMIndex)
{
    if (BMIndex < 18.5)
        calr += 1000;
    else if (BMIndex > 18.5)
    {
        calr -= 1000;
    }
    return calr;
}