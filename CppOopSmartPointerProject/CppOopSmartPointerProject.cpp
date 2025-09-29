// CppOop SmartPointer Project.cpp 
#include <iostream>

template <typename T>
class SmartPointer
{
    T* _pointer{};

public:
    SmartPointer() : SmartPointer(nullptr) {}
    SmartPointer(T* pointer) : _pointer{ pointer } {}

    SmartPointer(const SmartPointer<T>& other) = delete;
    /*{
        _pointer = new T;
        *_pointer = *other._pointer;
    }*/

    SmartPointer<T>& operator=(const SmartPointer<T>& other) = delete;
    /*{
        if (&other == this)
            return *this;

        delete _pointer;

        _pointer = new T;
        *_pointer = *other._pointer;

        return *this;
    }*/

    SmartPointer(SmartPointer<T>&& other) noexcept
    {
        _pointer = other._pointer;
        other._pointer = nullptr;
    }

    SmartPointer<T>& operator=(SmartPointer<T>&& other) noexcept
    {
        if (&other == this)
            return *this;

        delete _pointer;

        _pointer = other._pointer;
        other._pointer = nullptr;

        return *this;
    }

    T& operator*() const { return *_pointer; }
    T* operator->() const { return _pointer; }

    bool IsNull() const { return _pointer == nullptr; }

    ~SmartPointer()
    {
        delete _pointer;
    }
};

class Resource
{
    int value;
public:
    Resource() : value{}
    {
        std::cout << "Resource construct default\n";
    }

    Resource(int value) : value{ value }
    {
        std::cout << "Resource construct params\n";
    }

    Resource(const Resource& other)
    {
        this->value = other.value;
        std::cout << "Resource construct copy\n";
    }

    ~Resource()
    {
        std::cout << "Resource destruct\n";
    }

    int& Value()
    {
        return this->value;
    }
};

void SomeFunction()
{
    SmartPointer<Resource> resource1(new Resource(100));
    std::cout << resource1->Value() << "\n";

    //SmartPointer<Resource> resource2(resource1);
}

void SecondFunction(SmartPointer<Resource> res)
{

}



SmartPointer<Resource> CreateResource()
{
    SmartPointer<Resource> res(new Resource(100));
    return res;
}


int main()
{
    SmartPointer<Resource> mainRes;
    mainRes = CreateResource();
}
