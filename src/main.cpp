#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class BMI
{
public:
    double weight;
    double height;

    void calcBMI()
    {
        cout << "Please enter your weight (in kilograms):";
        cin >> weight;

        cout << "Please enter your height (in meters): ";
        cin >> height;

        double BodyMassIndex = weight / (height * height);

        cout << "Your Body Mass Index (BMI) is " << BodyMassIndex << endl;

        if (BodyMassIndex < 18.5)
            cout << "Unfortunately, you are malnourished.\n";
        else if (BodyMassIndex<25 & BodyMassIndex> 18.5)
        {
            cout << "Optimal" << endl;
        }
        else if (BodyMassIndex > 18.5)
        {
            cout << "You're overweight" << endl;
        }
    }
};
class BMR : public BMI
{
public:
    int age;
    double bmr;

    double calcBMR()
    {
        bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
        return bmr;
    }
};
class Food
{
public:
    string exercise;
    int timeForExercise;
    int calories;

    void enterFood()
    {
        cout << "Adding a meal" << endl;
        cout << "Enter amount of food:" << endl;
        cin >> timeForExercise;
        cout << "Enter name of food:" << endl;
        cin >> exercise;
        cout << "Enter amount of calories in meal" << endl;
        cin >> calories;
    }
    void openFile()
    {
        ofstream openFile("build/diet.txt");
        if (!openFile.is_open())
            cout << "Output file error" << endl;
        else
        {
            openFile << timeForExercise;
            openFile << exercise;
            openFile << calories;
        }
        openFile.close();
    }
};
class Calories
{
public:
    double calr = 2000;
    double setCalories(double BMIndex)
    {
        if (BMIndex < 18.5)
            calr += 1000;
        else if (BMIndex > 18.5)
        {
            calr -= 1000;
        }
        return calr;
    }
};
class Results
{
public:
    int day;
    int weight;
    void calendar()
    {
        int A[day][weight];
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cin >> A[i][j];
            }
        }
    }
};
class Workout
{
public:
    string exercise;
    int timeForExercise;

    void enterExercise()
    {
        cin >> exercise;
        cin >> timeForExercise;
    }
    void openFile()
    {
        ofstream openFile("build/workout.txt");
        if (!openFile.is_open())
            cout << "Output file error" << endl;
        else
        {
            openFile << timeForExercise;
            openFile << exercise;
        }
        openFile.close();
    }
};

int main()
{
    Food Meal;
    BMI BodyMassInd;
    Calories kCal;
    Results Tracking;
    Workout Training;
    double index;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Health Planner");
    while (window.isOpen())
    {
        sf::Event event;

        sf::String userInput;
        sf::Text userText;
        userText.setPosition(60, 300);
        userText.setFillColor(sf::Color::White);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::TextEntered)
        {
            userInput += event.text.unicode;
            userText.setString(userInput);
        }

        sf::Font font;
        try
        {
            if (!font.loadFromFile("font/CaviarDreams.ttf"))
            {
                throw "No font loaded";
            }
        }
        catch (const char *error)
        {
            cout << "An error occured: " << error << endl;
        }
        sf::Text outputText;
        outputText.setFont(font);
        outputText.setString("Enter your weight:");
        outputText.setCharacterSize(24);
        outputText.setFillColor(sf::Color::White);

        window.clear(sf::Color::Black);
        window.draw(outputText);
        window.draw(userText);
        window.display();

        BodyMassInd.calcBMI();

        Meal.enterFood();
        Meal.openFile();

        Training.enterExercise();
        Tracking.calendar();
    }
}