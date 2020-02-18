#include <string>
#include <nlohmann/json.hpp>

class FromFile
{
public:
    int readFromFileInt(std::string day, std::string indicator);
    double readFromFileDouble(std::string day, std::string indicator);
};