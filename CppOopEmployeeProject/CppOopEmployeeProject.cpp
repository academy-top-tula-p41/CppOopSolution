// CppOopEmployeeProject.cpp :
#include <iostream>

#include "Employee.h"

int main()
{
    /*Employee* employees = new Employee[3]
    {
        Employee("Bobby", 26),
        Employee("Jimmy", 19),
        Employee("Sammy", 22)
    };

    for (int i{}; i < 3; i++)
        std::cout << employees[i] << "\n";*/

    //std::cout << Employee::StaticId() << "\n";

    Employee bobby("Bobby", 28);
    bobby["age"] = 30;
    bobby["salary"] = 200000;

    std::cout << bobby << "\n";
}
