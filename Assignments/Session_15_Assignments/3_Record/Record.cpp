// Record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>

struct Record
{
    std::string m_Name;
    uint32_t m_PowerLevel = 0;
};

constexpr uint16_t SIZE = 4;

int main(void)
{
    std::cout << "Hello World!\n" << std::endl;

    std::array<Record, SIZE> names_power_levels;

    names_power_levels[0].m_Name = "Erin";
    names_power_levels[0].m_PowerLevel = 100;

    names_power_levels[1].m_Name = "Armin";
    names_power_levels[1].m_PowerLevel = 80;

    names_power_levels[2].m_Name = "Mikasa";
    names_power_levels[2].m_PowerLevel = 120;
    
    names_power_levels[3].m_Name = "Reiner";
    names_power_levels[3].m_PowerLevel = 75;

    for(auto& element : names_power_levels)
    {
        std::cout << "Name: " << element.m_Name << ", Power Level: " << element.m_PowerLevel << std::endl;
    }

    return 0;
}