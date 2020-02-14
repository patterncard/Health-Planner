#include <vector>
#include "Dish.h"

class Food
{
private:
    std::vector<Dish> dishes;

public:
    Food();
    void addDish(int protein, int carbs, int fat);
    std::vector<Dish> getAllDishes();
};
