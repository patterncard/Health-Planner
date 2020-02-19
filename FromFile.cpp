#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "FromFile.h"

using json = nlohmann::json;

int FromFile::readFromFileInt(std::string day, std::string indicator)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();
    return healthDB[day][indicator];
}

double FromFile::readFromFileDouble(std::string day, std::string indicator)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();
    return healthDB[day][indicator];
}