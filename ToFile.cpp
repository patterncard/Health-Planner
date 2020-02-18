#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "ToFile.h"

using json = nlohmann::json;

void ToFile::saveToFileInt(std::string day, std::string indicator, int value)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();

    healthDB[day][indicator] = value;

    std::ofstream database("dataBase.json");
    database << healthDB;
    database.close();
}

void ToFile::saveToFileDouble(std::string day, std::string indicator, double value)
{
    json healthDB = {};
    std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    indatabase >> healthDB;
    indatabase.close();

    healthDB[day][indicator] = value;

    std::ofstream database("dataBase.json");
    database << healthDB;
    database.close();
}