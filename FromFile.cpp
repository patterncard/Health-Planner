#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "FromFile.h"

using json = nlohmann::json;

// readFromFileInt("wed", "BMI");
// tabelka[0][0] = healthDB["tue"]["water"];

int FromFile::readFromFileInt(std::string day, std::string indicator)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();
    return healthDB[day][indicator];

    // json j_string = healthDB[day][indicator];
    // auto cpp_string = j_string.get<std::string>();
    // return cpp_string;
}

double readFromFileDouble(std::string day, std::string indicator)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();
    return healthDB[day][indicator];
}