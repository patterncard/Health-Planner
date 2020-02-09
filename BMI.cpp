#include <iostream>
#include "BMI.h"

double BMI::calcBMI(double weight, double height)
{
    return weight / ((height / 100) * (height / 100));
}


