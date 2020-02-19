class BMI
{
private:
    double weight;
    double height;

public:
    bool isResultWindowOpen = false;
    bool isErrorWindowOpen = false;
    double calcBMI(double weight, double height);
    void switchErrorWindow();
    void switchResultWindow();
    BMI()
    {
        weight = 1.0;
        height = 1.0;
    }
    ~BMI() {}
};
