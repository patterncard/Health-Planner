#include <string>
#include <nlohmann/json.hpp>

class FromFile
{
public:
    void readFromFileInt(json dataBase);
    void readFromFileDouble(json dataBase);
};