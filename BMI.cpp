#include <iostream>
#include "BMI.h"

double BMI::calcBMI(double weight, double height)
{
    return weight / ((height / 100) * (height / 100));
}

void BMI::switchResultWindow()
{
    isResultWindowOpen = !isResultWindowOpen;
}

void BMI::switchErrorWindow()
{
    isErrorWindowOpen = !isErrorWindowOpen;
}
