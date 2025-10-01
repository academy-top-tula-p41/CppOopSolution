// CppOop CopyMoveCompare Project.cpp 
//
#include <iostream>
#include <chrono>

template <typename T>
class Array
{
    T* items{};
    int size{};

public:
    Array(int size)
        : size{ size },
        items{ new T[size] } {};
    
    ~Array()
    {
        delete[] items;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    Array(Array&& other) noexcept
        : size{ other.size },
        items{ other.items }
    {
        other.size = 0;
        other.items = nullptr;
    }

    Array& operator=(Array&& other) noexcept
    {
        if (&other == this)
            return *this;
        
        delete[] items;
        
        this->size = other.size;
        this->items = other.items;

        other.size = 0;
        other.items = nullptr;

        return *this;
    }

    int Size() const { return size; }
    T& operator[](int index) { return items[index]; }
    const T& operator[](int index) const { return items[index]; }
};

class Timer
{
    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::duration<double, std::ratio<1>> Second;

    std::chrono::time_point<Clock> begin{ Clock::now() };

public:
    void reset()
    {
        begin = Clock::now();
    }

    double duration() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - begin).count();
    }
    
};

Array<int> CloneArrayDouble(const Array<int>& array)
{
    Array<int> arrayDouble(array.Size());
    for (int i{}; i < array.Size(); i++)
        arrayDouble[i] = array[i] * 2;

    return arrayDouble;
}


int main()
{
    Timer timer;

    Array<int> array(1000000);
    for (int i{}; i < array.Size(); i++)
        array[i] = i;

    array = CloneArrayDouble(array);

    std::cout << timer.duration() << "\n";
}
