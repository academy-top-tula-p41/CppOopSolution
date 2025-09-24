// CppOopTemplatesProject.cpp 
#include <iostream>

template <typename T1, typename T2>
class Person
{
    T1 number;
    T2 series;

    char name[20];
    int age;

public:
    /*Person(T number) : number{ number }
    { }*/
};

template <typename T1, typename T2>
T1 Sum(T1 a, T2 b)
{
    return a + b;
}


template <typename T>
class Base
{
public:
    T value;
};

template <typename T>
class Derived : public Base<T>
{
public:
    T second_value;
};

template <typename T1, typename T2>
class DerivedOtherType : public Base<T1>
{
public:
    T2 second_value;
};

class DerivedExplicitInt : public Base<int>
{

};

class DerivedExplicitString : public Base<const char*>
{

};

template <typename T, int size>
class Array
{
    T array[size]{};
public:
    int Size() { return size; }
    T& operator[](int index)
    {
        return array[index];
    }
};

template <int rate>
class Accaunt
{

};


int main()
{
    const int size{ 10 };
    int array[size];


    /*
    int a{ 30 };
    float b{ 40 };
    std::cout << Sum(a, b);
    */

    /*Person<int, const char*> person;*/

    Array<int, 10> array10;
    for (int i{}; i < array10.Size(); i++)
        array10[i] = 100 + i;
    for (int i{}; i < array10.Size(); i++)
        std::cout << array10[i] << " ";

    Accaunt<5> accaunt5;
    Accaunt<10> accaunt10;
}
