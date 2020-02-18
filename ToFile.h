#include <string>

class ToFile
{
public:
    void saveToFileInt(std::string day, std::string indicator, int value);
    void saveToFileDouble(std::string day, std::string indicator, double value);
};