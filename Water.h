#include <vector>

class Water
{
public:
    Water();
    std::vector<int> glassesOfWaterVolume;
    void addGlasses(int glass);
    int sumAllGlassesVolume();
};
