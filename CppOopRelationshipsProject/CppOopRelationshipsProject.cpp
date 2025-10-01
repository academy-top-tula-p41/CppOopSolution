// CppOop Relationships Project.cpp 
//
#include <iostream>

class Flat
{
public:
    Flat()
    {
        std::cout << "Flat construct " << this <<"\n";
    }

    ~Flat()
    {
        std::cout << "Flat destruct\n";
    }
};

class House
{
    Flat flat;
public:
    House()
    {
        std::cout << "House construct " << this << "\n";
    }

    ~House()
    {
        std::cout << "House destruct\n";
    }
};

class Driver
{
public:
    Driver()
    {
        std::cout << "Driver construct " << this << "\n";
    }

    ~Driver()
    {
        std::cout << "Driver destruct\n";
    }
};

class Car
{
    Driver* driver{};
public:
    Car()
    {
        std::cout << "Car construct " << this << "\n";
    }

    void AddDriver(Driver* driver)
    {
        this->driver = driver;
    }

    ~Car()
    {
        std::cout << "Car destruct\n";
    }
};

class Doctor
{
    Patient* patient;
public:

};

class Patient
{
    Doctor* doctor;
public:

};

int main()
{
    //House house;
    Driver* driver = new Driver;
    Car car;
    car.AddDriver(driver);
}
