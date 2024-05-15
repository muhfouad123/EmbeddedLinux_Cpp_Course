// Composition_Aggregation_Relationship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

class PageObject
{
    virtual void addItem(PageObject a) {}
    virtual void removeItem(void) {}
    virtual void deleteItem(PageObject a) {}
};
class Page : public PageObject
{
public:
    void addItem(PageObject a)
    {
        std::cout << "Item added into the page" << std::endl;
    }
    void removeItem(void)
    {
        std::cout << "Item removed from the page" << std::endl;
    }
    void deleteItem(PageObject a)
    {
        std::cout << "Item deleted from the page" << std::endl;
    }
};
class Copy : public PageObject
{
private:

    // The following statement proves that class Copy composes the class PageObject.
    // The "copyPages" object implements composition of class Copy to class PageObject.
    //std::vector<PageObject> copyPages;
    //PageObject copyPages;

    // This pointer implements aggregation of class Copy to class PageObject.
    PageObject* copyPagesPtr;
public:
    void insertItem(PageObject page)
    {
        //copyPages.push_back(page);
    }
    void addItem(PageObject a)
    {
        std::cout << "Item added into the page" << std::endl;
    }
    void removeItem(void)
    {
        std::cout << "Item removed from the page" << std::endl;
    }
    void deleteItem(PageObject a)
    {
        std::cout << "Item deleted from the page" << std::endl;
    }
};
//class Copy : public Page
//{
//private:
//    std::vector<Page> copyPages;
//public:
//    void insertItem(Page pageItem)
//    {
//        copyPages.push_back(pageItem);
//    }
//    void addItem(Page pageItem)
//    {
//        std::cout << "Item added into the page" << std::endl;
//    }
//    void removeItem(void)
//    {
//        std::cout << "Item removed from the page" << std::endl;
//    }
//    void deleteItem(Page pageItem)
//    {
//        std::cout << "Item deleted from the page" << std::endl;
//    }
//};
int main(void)
{
    std::cout << "Hello World!\n";

    Page p1;
    Page p2;
    Copy myCopy;

    myCopy.insertItem(p1);
    myCopy.insertItem(p2);
    myCopy.addItem(p1);
    p1.addItem(p2);
    myCopy.removeItem();
    p2.removeItem();

    return 0;
}
