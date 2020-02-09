#include <iostream>
#include "BMI.h"

double Bmi::calcBMI(double weight, double height)
{
    return weight / ((height / 100) * (height / 100));
}

