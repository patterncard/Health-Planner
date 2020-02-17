#include <string>

class ToFile
{
public:
    bool day;

    double bmi;
    double bmr;
    int dish;
    int water;
    double workout;

    void saveToFileInt(std::string day, std::string indicator, int value);
    void saveToFileDouble(std::string day, std::string indicator, double value);
};