#include "BMI.h"

class BMR : public BMI
{
public:
    int age;
    double bmr;
    bool isResultWindowOpen = false;
    bool isErrorWindowOpen = false;
    void switchErrorWindow();
    void switchResultWindow();
    double calcBMR(double weight, double height, double age);

    BMR()
    {
        age = 1.0;
    }
    ~BMR() {}
};
