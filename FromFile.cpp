#include "FromFile.h"
#include <nlohmann/json.hpp>

void FromFile::readFromFile()
{
    std::ifstream inputDataBase("dataBase.json");
    if (!inputDataBase.is_open())
        std::cout << "Input file error!";
    else
    {
        inputDataBase >> data;
        inputDataBase.close();
    }
}