#include <string>
#include <nlohmann/json.hpp>

class FromFile
{
public:
    std::string readFromFileInt(std::string day, std::string indicator);
    std::string readFromFileDouble(std::string day, std::string indicator);
};