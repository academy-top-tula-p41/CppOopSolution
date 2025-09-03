#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Date.h"

#include "Funcs.h"

class Person
{
    char name[20];
    int age;

public:

    Person() : Person("Anonim", 1) {}
    Person(const char* name) : Person(name, 1) {}
    Person(int age) : Person("Anonim", age) {}

    Person(const char* name, int age) : age{ age }
    {
        strcpy(this->name, name);
    }

    void Name(char name[]) { strcpy(this->name, name); }
    const char* Name() const { return name; }

    void Age(int age) { this->age = age; }
    const int& Age() { return age; }
};

void PrintDate(const Date& date)
{
    std::cout << date.GetDay() << "."
        << date.GetMonth() << "."
        << date.GetYear() << "\n";
}

Date CreateDate(int d, int m, int y)
{
    Date date;
    date.SetDay(d);
    date.SetMonth(m);
    date.SetYear(y);

    return date;
}

void DateExample()
{
    Date date1;
    date1.ConsolePrint();

    try
    {
        date1.SetDay(15);
    }
    catch (const char* ex)
    {
        std::cout << ex << "\n";
    }

    date1.SetMonth(9);
    date1.SetYear(2001);


    /*std::cout << date1.GetDay() << "."
        << date1.GetMonth() << "."
        << date1.GetYear() << "\n";*/

    date1.ConsolePrint();

    Date date2 = CreateDate(8, 11, 1990);
    date2.ConsolePrint();

    Date date3(22, 5, 2020);

    Date* date4 = new Date(9, 10, 2005);
}


int main()
{
    Person* bobby = new Person("Bobby", 25);
    std::cout << bobby->Age() << "\n";
    
    std::cout << bobby->Age() << "\n";

}
