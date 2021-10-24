/* Sort even numbers within a given array */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

void sortEven(std::vector<int>& input)
{
    std::vector<size_t> indexesOfEven;
    std::vector<int> evenValues;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] % 2 == 0)
        {
            indexesOfEven.push_back(i);
            evenValues.push_back(input[i]);
        }
    }
    std::sort(evenValues.begin(), evenValues.end());
    for (size_t i = 0; i < evenValues.size(); ++i)
    {
        size_t ind = indexesOfEven[i];
        input[ind] = evenValues[i];
    }
}
// O(nlogn) in time, O(n) in

int main()
{
    std::vector<int> sample{ 3, 8, 12, 4, 5, 6, 7, 9, 3, 2, 7, 18, 19 };
    sortEven(sample);
    for (const int v : sample)
    {
        std::cout << v << ", ";
    }
    std::cout << "\n";
    return 0;
}