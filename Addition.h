template <typename T>
T SumArray(std::vector<T> arr)
{
    T volume = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        volume += arr[i];
    }
    return volume;
}
