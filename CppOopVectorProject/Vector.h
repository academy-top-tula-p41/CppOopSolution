#pragma once
template <typename T>
class Vector
{
	T* items;
	int size;
	int capacity;

public:
	Vector() : items{ nullptr },
		size{},
		capacity{} {};

	Vector(int size) : items{ new T[size] {} },
		size{ size },
		capacity{ size } {}

	Vector(const Vector<T>& other)
		: size{ other.size }, capacity{ other.capacity }
	{
		items = new T[capacity];
		for (int i{}; i < size; i++)
			items[i] = other.items[i];
	}

	Vector(Vector<T>&& other) noexcept
		: size{ other.size },
		capacity{ other.capacity },
		items{ other.items } 
	{
		other.capacity = 0;
		other.size = 0;
		other.items = nullptr;
	}

	Vector<T>& operator=(const Vector<T>& other)
	{
		if (&other == this)
			return *this;

		delete[] items;

		items = new T[capacity];
		for (int i{}; i < size; i++)
			items[i] = other.items[i];

		return *this;
	}

	Vector<T>& operator=(const Vector<T>&& other) noexcept
	{
		if (&other == this)
			return *this;

		delete[] items;

		this->size = other.size;
		this->capacity = other.capacity;
		this->items = other.items;

		other.capacity = 0;
		other.size = 0;
		other.items = nullptr;

		return *this;
	}


	T& operator[](int index);

	const int& Size() const { return size; }
	const int& Capacity() const { return capacity; }

	void PushBack(T value);
	void PushFront(T value);
	void Insert(int index, T value);

	T PopBack();
	T PopFront();
	T Remove(int index);
	
	void Print();

	~Vector()
	{
		if (items)
			delete[] items;
	}
};

template <typename T>
inline T& Vector<T>::operator[](int index)
{
	return items[index];
}

template <typename T>
void Vector<T>::PushBack(T value)
{
	if (size < capacity)
	{
		items[size] = value;
		size++;
		return;
	}

	(capacity) ? capacity *= 1.5 : capacity = 2;
	T* newItems = new T[capacity] {};
	for (int i{}; i < size; i++)
		newItems[i] = items[i];
	newItems[size] = value;
	size++;

	if(items)
		delete[] items;
	items = newItems;
}

template <typename T>
void Vector<T>::PushFront(T value)
{
	if (!capacity)
	{
		PushBack(value);
		return;
	}

	if (size < capacity)
	{
		for (int i{ size - 1 }; i >= 0; i--)
			items[i + 1] = items[i];
		items[0] = value;
		size++;
		return;
	}

	capacity *= 1.5;
	T* newItems = new T[capacity] {};

	for (int i{}; i < size; i++)
		newItems[i + 1] = items[i];
	newItems[0] = value;
	size++;

	delete[] items;
	items = newItems;
}

template <typename T>
void Vector<T>::Insert(int index, T value)
{
	if (!capacity)
	{
		PushBack(value);
		return;
	}

	if (size < capacity)
	{
		for (int i{ size - 1 }; i >= index; i--)
			items[i + 1] = items[i];
		items[index] = value;
		size++;
		return;
	}

	capacity *= 1.5;
	T* newItems = new T[capacity];
	for (int i{}; i < index; i++)
		newItems[i] = items[i];
	for (int i{ index }; i < size; i++)
		newItems[i + 1] = items[i];
	newItems[index] = value;
	size++;

	delete[] items;
	items = newItems;
}

template <typename T>
void Vector<T>::Print()
{
	for (int i{}; i < size; i++)
		std::cout << items[i] << " ";
	std::cout << "\n";
}

template <typename T>
T Vector<T>::PopBack()
{
	if (size <= 0)
		throw "vector is empty";

	if (capacity <= size * 1.5)
	{
		size--;
		return items[size];
	}

	capacity = size * 1.5;
	T* newItems = new T[capacity];
	for (int i{}; i < size; i++)
		newItems[i] = items[i];
	size--;

	delete[] items;
	items = newItems;

	return items[size];
}