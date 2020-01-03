#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class BMI
{
    void calcBMI()
    {
        cout << "Please enter your weight (in kilograms):";
        double weight;
        cin >> weight;

        cout << "Please enter your height (in meters): ";
        double height;
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
        ofstream openFile("build/food.txt");
        if (!openFile.is_open())
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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Health Planner");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Font font;
        if (!font.loadFromFile("font/CaviarDreams.ttf"))
        {
            // error
        }
        sf::Text text;
        text.setFont(font);
        text.setString("Hello world");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }
    // Food breadd;
    // breadd.enterFood();
    // breadd.openFile();
}