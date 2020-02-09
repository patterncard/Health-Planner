#include "BMR.h"

double BMR::calcBMR(double weight, double height, double age)
{
    bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    return bmr;
}