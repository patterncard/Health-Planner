#include "BMI.h"

#ifndef BMR_H
#define BMR_H

class BMR : public BMI
{
public:
    double weight;
    double height;
    int age;
    double bmr;

    double calcBMR(double weight, double height, double age);
};

    inline double BMR::calcBMR(double weight, double height, double age)
    {
        bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
        return bmr;
    }

#endif