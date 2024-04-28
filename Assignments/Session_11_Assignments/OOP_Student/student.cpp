#include <iostream>

class Student
{
private:
    std::string m_Name;
    uint16_t m_Age;
    uint16_t m_ID;
public:
    Student()
    {
        std::cout << "Student()         --> Default Constructor" << std::endl;
    }
    // Student(std::string pName, uint8_t pAge, uint16_t pID)
    // {
    //     this->m_Name = pName;
    //     this->m_Age = pAge;
    //     this->m_ID = pID;

    //     std::cout << "Student()         --> Parameterized Constructor" << std::endl;
    // }
    Student(std::string pName, uint8_t pAge, uint16_t pID) : m_Name(pName), m_Age(pAge), m_ID(pID)
    {
        std::cout << "Student()         --> Default Constructor with initializer list" << std::endl;
    }
    void setName(std::string pName)
    {
        this->m_Name = pName;
    }
    std::string getName(void)
    {
        return this->m_Name;
    }
    void setAge(uint16_t pAge)
    {
        this->m_Age = pAge;
    }
    uint16_t getAge(void)
    {
        return this->m_Age;
    }
    void setID(uint16_t pID)
    {
        this->m_ID = pID;
    }
    uint16_t getID(void)
    {
        return this->m_ID;
    }
    void printName(void)
    {
        std::cout << "Student name: " << getName() << std::endl;
    }
    void printAge(void)
    {
        std::cout << "Student age: " << getAge() << std::endl;
    }
    void printID(void)
    {
        std::cout << "Student ID: " << getID() << std::endl;
    }
    ~Student()
    {
        std::cout << "~Student()" << std::endl;
    }
};

int main(void)
{
    Student s1{"Muhammad Fouad", 20, 10873};
    Student s2;
    s2.setName("Abdelrahman Mohamed");
    s2.setAge(24);
    s2.setID(10496);

    s1.printName();
    s1.printAge();
    s1.printID();

    s2.printName();
    s2.printAge();
    s2.printID();
    return 0;
}