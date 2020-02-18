#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "ToFile.h"

using json = nlohmann::json;

// tabelka[0][0] = healthDB["tue"]["water"];
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

    // database << healthDB;

    std::cout << healthDB << std::endl; //This will print the entire json object.
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

    std::cout << healthDB << std::endl;
}