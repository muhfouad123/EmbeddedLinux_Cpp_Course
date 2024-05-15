#include <iostream>
#include <ostream>
#include <string>

class Person
{
private:
    std::string m_Name;
    uint16_t m_Age = 0;
    double m_Height = 0.0;
    double m_Weight = 0.0;
public:
    Person()
    {
        std::cout << "Person()                                                          --> Default Constructor\n" << std::endl;
    }
    Person(std::string name, uint8_t age, double height, double weight) : m_Name(name), m_Age(age), m_Height(height), m_Weight(weight)
    {
        std::cout << "Person(std::string, uint8_t, double, double)                      --> Parameterized Constructor\n" << std::endl;
    }
    //Person(const Person& p)
    //{
    //    std::cout << "Person(const Person&)                                             --> Copy Constructor" << std::endl;
    //}
    Person& operator=(const Person& obj)
    {
        Person person;
        person.m_Name = obj.m_Name;
        person.m_Age = obj.m_Age;
        person.m_Height = obj.m_Height;
        person.m_Weight = obj.m_Weight;
        return person;
    }
    friend std::ostream& operator<<(std::ostream& os, const Person& obj)
    {
        os << obj.m_Name << " " << obj.m_Age << " " << obj.m_Height << " " << obj.m_Weight << "\n";
        return os;
    }
    ~Person()
    {
        std::cout << "~Person()                                                         --> Destructor\n" << std::endl;
    }
};

template<typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
template<typename T>
T max(T x, T y)
{
    return ((x) > (y) ? (x) : (y));
}
int main(void)
{
    std::cout << "Hello World\n" << std::endl;

    int x = 1;
    int y = 2;

    std::cout << "x = " << x << ", y = " << y << std::endl;

    swap(x, y);

    std::cout << "x = " << x << ", y = " << y << std::endl;

    int maxVal = max(x, y);

    std::cout << "max = " << maxVal << std::endl;

    Person p1{"Muhammad Fouad", 31, 169, 100};
    Person p2(p1);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}