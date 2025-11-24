#include <iostream>
#include "Vector.h"
#include <vector>

class Person
{
    char name[20];
    int age;
public:
    Person()
    {
        strcpy_s(name, 1, "");
        age = 0;
    }

    Person(const char* name, int age) : age{ age }
    {
        strcpy_s(this->name, strlen(name) + 1, name);
    }

    const char* Name() const { return name; }
    int Age() const { return age; }


    friend std::ostream& operator<<(std::ostream& out, const Person& p)
    {
        out << "Name: " << p.name << ", Age: " << p.age;
        return out;
    }
};

class IntCompare : public ICompare<int>
{
public:
    bool Less(const int& a, const int& b) override
    {
        return a < b;
    }
};

class PersonNameCompare : public ICompare<Person>
{
public:
    bool Less(const Person& left, const Person& right) override
    {
        return strcmp(left.Name(), right.Name()) < 0;
    }
};

class PersonAgeCompare : public ICompare<Person>
{
public:
    bool Less(const Person& left, const Person& right) override
    {
        return left.Age() < right.Age();
    }
};

int main()
{
    srand(time(nullptr));

    /*Vector<int> v1;
    

    for (int i = 1; i <= 10; i++)
        v1.PushBack(i * 100);
    v1.Print();
    std::cout << v1.Size() << " " << v1.Capacity() << "\n\n";

    try
    {
        for (int i = 0; i < 11; i++)
        {
            std::cout << v1.PopBack() << "\n";
            std::cout << v1.Size() << " " << v1.Capacity() << "\n";
        }
    }
    catch (const char* ex)
    {
        std::cout << ex << "\n";
    }*/
    
    /*std::cout << v1.Size() << " " << v1.Capacity() << "\n";

    v1.PushBack(100);
    v1.PushBack(200);
    v1.PushBack(300);
    v1.PushBack(400);
    v1.PushBack(500);
    v1.Print();
    std::cout << v1.Size() << " " << v1.Capacity() << "\n";

    v1.PushFront(600);
    v1.PushFront(700);
    v1.Print();
    std::cout << v1.Size() << " " << v1.Capacity() << "\n";

    v1.Insert(4, 1000);
    v1.Print();
    std::cout << v1.Size() << " " << v1.Capacity() << "\n";*/

    Vector<int> numbers(10);
    for (int i{}; i < numbers.Size(); i++)
        numbers[i] = rand() % 100;
    numbers.Print();
    numbers.Sort(new IntCompare());
    numbers.Print();

    Vector<Person> persons;
    persons.PushBack(Person("Bobby", 29));
    persons.PushBack(Person("Sammy", 31));
    persons.PushBack(Person("Jimmy", 22));
    persons.Print();
    persons.Sort(new PersonNameCompare());
    persons.Print();
    persons.Sort(new PersonAgeCompare());
    persons.Print();

}
