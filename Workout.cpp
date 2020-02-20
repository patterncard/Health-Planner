#include "Workout.h"
#include "Addition.h"
#include <iostream>

Workout::Workout()
{
    std::cout << "Initialized Workout Module" << std::endl;
}

void Workout::addRecord(double time)
{
    timeTrainedMinutes.push_back(time);
};

double Workout::sumAllTimeSpent()
{
    return SumArray(timeTrainedMinutes);
};