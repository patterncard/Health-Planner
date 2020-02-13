#include <vector>

class Dish
{
private:
    char *name;
    int calories;
    int protein;
    int carbs;
    int fat;
    void setDish(char *name, int protein, int carbs, int fat);

public:
    Dish(char *name, int protein, int carbs, int fat);
    int getDishCalories();
    char *getDishName();
};
