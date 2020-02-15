#include "BMI.h"

class BMR : public BMI
{
public:
    int age;
    double bmr;

    double calcBMR(double weight, double height, double age);

    BMR()
    {
        age = 1.0;
    }
    ~BMR() {}
};
