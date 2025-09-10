#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
    Vector v1;
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
    }
    
    

    
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
}
