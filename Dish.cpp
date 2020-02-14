#include "Dish.h"
#include <iostream>

Dish::Dish(int protein, int carbs, int fat)
{
    std::cout << "Initialized Dish" << std::endl;
    setDish(protein, carbs, fat);
}

void Dish::setDish(int protein_, int carbs_, int fat_)
{
    calories = 4 * protein_ + 4 * carbs_ + 9 * fat_;
    protein = protein_;
    carbs = carbs_;
    fat = fat_;
}

int Dish::getDishCalories()
{
    return calories;
}
