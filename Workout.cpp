#include "Workout.h"
#include "Addition.h"
#include <iostream>

Workout::Workout()
{
    std::cout << "Initialized Workout Module" << std::endl;
}

void Workout::addRecord(double glass)
{
    timeTrainedMinutes.push_back(glass);
};

double Workout::sumAllTimeSpent()
{
    return SumArray(timeTrainedMinutes);
};