#include <vector>
#include "Dish.h"

class Food
{
private:
    std::vector<Dish> dishes;

public:
    Food();
    int calcCalories(int protein, int carbs, int fat);
    std::vector<Dish> getAllCalories();
};
