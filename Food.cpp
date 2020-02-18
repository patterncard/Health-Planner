#include "Food.h"
#include <iostream>

Food::Food()
{
    std::cout << "Initialized Food Module" << std::endl;
}

int Food::addDish(int protein, int carbs, int fat)
{
    Dish dish(protein, carbs, fat);
    dishes.push_back(dish);
    return dish.getDishCalories();
};

std::vector<Dish> Food::getAllDishes()
{
    return dishes;
}
