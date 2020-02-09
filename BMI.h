class BMI
{
private:
    double weight;
    double height;

public:
    double calcBMI(double weight, double height);

    BMI()
    {
        weight = 1.0;
        height = 1.0;
    }
    ~BMI() {}
};
