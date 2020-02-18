#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include "FromFile.h"

// tabelka[0][0] = healthDB["tue"]["water"];
void FromFile::readFromFileInt(json dataBase)
{
    //     json healthDB = {};
    //     std::ifstream indatabase("dataBase.json", std::ifstream::binary);
    //     indatabase >> healthDB;
    //     indatabase.close();

    //     healthDB[day][indicator] = value;

    //     std::ofstream database("dataBase.json");
    //     database << healthDB;
    //     database.close();
    // }

    void FromFile::readFromFileDouble()
    {
    }