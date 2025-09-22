// CppOopCopyConstructorProject.cpp 
//
#include <iostream>

class Counter
{
    int* count;
public:
    Counter()
    {
        count = new int;
        *count = 100;

        std::cout << "Counter construct! " << this << "\n";
    }

    Counter(Counter& counter)
    {
        count = new int;
        *count = *counter.count;

        std::cout << "Counter copy construct! " << this << "\n";
    }

    int GetCount()
    {
        return *count;
    }

    void SetCount(int value)
    {
        *(this->count) = value;
    }

    ~Counter()
    {
        std::cout << "Counter destruct! " << this << "\n";
    }
};

void Func(Counter counter3)
{
    std::cout << "Func working!\n";
}

Counter Create()
{
    Counter counter4;
    return counter4;
}

class Array
{
    int* items;
    int size;
public:

    Array(int size) : size{ size }
    {
        items = new int[size];
    }

    Array(const Array& array) : size{ array.size }
    {
        items = new int[size];
        for (int i{}; i < size; i++)
            items[i] = array.items[i];
    }

    Array operator=(const Array& array)
    {
        items = new int[size];
        for (int i{}; i < size; i++)
            items[i] = array.items[i];

        return *this;
    }

    int Size() { return size; }
    int Item(int index) { return items[index]; }
    void Item(int index, int value) { items[index] = value; }

    ~Array()
    {
        if (items)
            delete[] items;
    }
};


int main()
{
    /*Counter counter;
    std::cout << counter.GetCount() << "\n";

    Counter counter2 = counter;
    counter2.SetCount(200);

    std::cout << counter.GetCount() << "\n";*/

    //Func(counter);
    //Create();
    
    Array array1(5);
    for (int i{}; i < array1.Size(); i++)
        array1.Item(i, 100);

    Array array2(5);
    array2 = array1;

    array2.Item(0, 200);

    for (int i{}; i < array1.Size(); i++)
        std::cout << array1.Item(i) << " ";
    std::cout << "\n";
}
