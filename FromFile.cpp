#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "FromFile.h"

using json = nlohmann::json;

// readFromFileInt("wed", "BMI");

// tabelka[0][0] = healthDB["tue"]["water"];
std::string FromFile::readFromFileInt(std::string day, std::string indicator)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();
    return healthDB[day][indicator];
}

std::string readFromFileDouble(std::string day, std::string indicator)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();
    return healthDB[day][indicator];
}