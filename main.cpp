#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BMI
{
    void calcBMI()
    {
        cout << "Please enter your weight (in kilograms): ";
        double weight;
        cin >> weight;

        cout << "Please enter your height (in meters): ";
        double height;
        cin >> height;

        double BodyMassIndex = weight / (height * height); 

        cout << "Your Body Mass Index (BMI) is " << BodyMassIndex << endl; 

        if (BodyMassIndex < 18.5)
            cout << "Unfortunately, you are malnourished.\n"; 
        else if(BodyMassIndex<25 & BodyMassIndex > 18.5)
        {
            cout << "Optimal" << endl;
        }
        else if (BodyMassIndex > 18.5)
        {
            cout << "You're overweight" << endl;
        }
        
    }
};
class Food
{
    public:
    string foodName;
    int foodAmount;
    int calories;
    
    void enterFood()
    {
        cout << "Adding a meal" << endl;
        cout << "Enter amount of food:" << endl;
        cin >> foodAmount;
        cout << "Enter name of food:" << endl;
        cin >> foodName;
        cout << "Enter amount of calories in meal" << endl;
        cin >> calories;
    }
    void openFile()
    {
        ofstream openFile("food.txt");
        if(!openFile.is_open())
        cout << "Output file error" << endl;
        else
        {
            openFile << foodAmount;
            openFile << foodName;
            openFile << calories;
        }
        openFile.close();        
    }

};
class Calories
{
};
class Diet
{
};
class Results
{
};
class Workout
{
};

int main()
{
    Food breadd;
    breadd.enterFood();
    breadd.openFile();
}