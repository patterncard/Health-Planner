#include "BMI.h"

class BMR : public BMI
{
public:
    double weight;
    double height;
    int age;
    double bmr;

    double calcBMR(double weight, double height, double age);

    BMR()
    {
        weight = 1.0;
        height = 1.0;
        age = 1.0;
    }
    ~BMR() {}
};
