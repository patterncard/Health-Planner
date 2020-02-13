#include <vector>
#include "Dish.h"

class Food
{
private:
    std::vector<Dish> dishes;

public:
    Food();
    void addDish(char *name, int protein, int carbs, int fat);
    std::vector<Dish> getAllDishes();
};
