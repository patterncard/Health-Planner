#include "Food.h"
#include <iostream>

Food::Food()
{
    std::cout << "Initialized Food Module" << std::endl;
}

void Food::addDish(char *name, int protein, int carbs, int fat)
{
    Dish dish(name, protein, carbs, fat);
    dishes.push_back(dish);
};

std::vector<Dish> Food::getAllDishes()
{
    return dishes;
}
