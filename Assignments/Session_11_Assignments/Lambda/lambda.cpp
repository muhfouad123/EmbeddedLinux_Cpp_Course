#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
/**
 * @brief 
 * 
 * Assignment:
 *      Implement the function "calculate", which takes two parameters: the first is an
 *      array/vector, while the second is a function which modifies the elements of that
 *      array/vector by sorting its elements.
 * 
 *      Hint: use "std::sort" to implement the sorting logic.
 * 
 * @return int 
 */
/**
 * 
 * Q: Is std::sort considered to have several overloads (basically 4 overloads) in C++?!
 * Q: 
 * 
*/
constexpr int SIZE = 10;
// void calculate(std::array<int, SIZE> array, std::function<void (bool&)> clbk)
// {
//     std::sort(array.begin(), array.end(), clbk);
// }
void print(std::array<int, SIZE> array)
{
    for(int i : array)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    std::array<int, SIZE> arr{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    print(arr);
    // std::function<void (bool&)> compare = [](const int& a, const int& b) -> bool
    //                 {
    //                     return a > b;
    //                 };
    std::sort(arr.begin(), arr.end(), [](const int& a, const int& b) -> bool
                                        {
                                            return a > b;
                                        });
    print(arr);
    std::cout << "Sorted with Lambda Expression" << std::endl;
    std::sort(arr.begin(), arr.end());
    print(arr);
    std::cout << "Sorted with default operator'<' --> less than operator" << std::endl;
    return 0;
}