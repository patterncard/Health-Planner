#include <iostream>
#include <string>

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
}