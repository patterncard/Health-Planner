#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "ToFile.h"

void ToFile::saveToFile(int data)
{
    std::ofstream outputDataBase("dataBase.json");
    if (!outputDataBase.is_open())
        std::cout << "Output file error!";
    else
    {
        outputDataBase << data;
        outputDataBase.close();
    }
}