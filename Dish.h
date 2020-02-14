#include <vector>

class Dish
{
private:
    int calories;
    int protein;
    int carbs;
    int fat;
    void setDish(int protein, int carbs, int fat);

public:
    Dish(int protein, int carbs, int fat);
    int getDishCalories();

    Dish() {}
    ~Dish() {}
};
