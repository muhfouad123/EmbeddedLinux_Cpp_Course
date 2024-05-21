// IStrategy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class IVehcileStrategy
{
private:
public:
    virtual void calculate_speed(void) = 0;
};
class Mercedes : public IVehcileStrategy
{
private:
public:
    Mercedes()
    {
        std::cout << "Mercedes()                                --> Default Constructor" << std::endl;
    }
    void calculate_speed(void)
    {
        std::cout << "Calculating speed for Mercedes .." << std::endl;
    }
    ~Mercedes()
    {
        std::cout << "~Mercedes()                               --> Destructor" << std::endl;
    }
};
class VW : public IVehcileStrategy
{
private:
public:
    VW()
    {
        std::cout << "VW()                                      --> Default Constructor" << std::endl;
    }
    void calculate_speed(void)
    {
        std::cout << "Calculating speed for VW .." << std::endl;
    }
    ~VW()
    {
        std::cout << "~VW()                                     --> Destructor" << std::endl;
    }
};
class BMW : public IVehcileStrategy
{
private:
public:
    BMW()
    {
        std::cout << "BMW()                                     --> Default Constructor" << std::endl;
    }
    void calculate_speed(void)
    {
        std::cout << "Calculating speed for BMW .." << std::endl;
    }
    ~BMW()
    {
        std::cout << "~BMW()                                    --> Destructor" << std::endl;
    }
};

class Vehicle
{
private:
    IVehcileStrategy* m_CalculateSpeed;
public:
    Vehicle(IVehcileStrategy* obj) : m_CalculateSpeed(obj)
    {
        std::cout << "Vehicle(IVehicleStrategy*)                --> Parameterized Constructor" << std::endl;
    }
    void vehicle_speed(void)
    {
        m_CalculateSpeed->calculate_speed();
    }
    ~Vehicle()
    {
        std::cout << "~Vehicle()                                --> Destructor" << std::endl;
    }
};

int main(void)
{
    std::cout << "This code implements the Strategy Design Pattern.\n" << std::endl;

    Mercedes mercedesVehicle;
    VW vwVehicle;
    BMW bmwVehicle;

    Vehicle v1(&mercedesVehicle);
    v1.vehicle_speed();

    Vehicle v2(&vwVehicle);
    v2.vehicle_speed();

    Vehicle v3(&bmwVehicle);
    v3.vehicle_speed();

    return 0;
}