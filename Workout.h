#include <vector>

class Workout
{
public:
    Workout();
    std::vector<double> timeTrainedMinutes;
    void addRecord(double glass);
    double sumAllTimeSpent();
};