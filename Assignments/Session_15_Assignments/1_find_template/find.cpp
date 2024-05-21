// find.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

template<typename InputIterator, typename T>
InputIterator Find(InputIterator first, InputIterator last, const T& value)
{
    InputIterator it;
    InputIterator retVal;
    for(it = first; it != last; it++)
    {
        if(*it == value)
        {
            retVal = it;
            break;
        }
        else
        {
            /* Do nothing! */
        }
    }
    retVal = it;
    return retVal;
}

int main(void)
{
    std::cout << "This code is to implement std::find() funtion as a template function.\n" << std::endl;
    std::vector<int> vectInt{10, 20, 30, 40, 50};
    std::vector<int>::iterator itVect;

    int element = 70;

    itVect = Find<std::vector<int>::iterator, int>(vectInt.begin(), vectInt.end(), element);

    if(itVect != vectInt.end())
    {
        std::cout << "Element found at index no." << (itVect - vectInt.begin()) << std::endl;
    }
    else
    {
        std::cout << "Element not found .." << std::endl;
    }

    return 0;
}