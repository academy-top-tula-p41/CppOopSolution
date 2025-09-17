#pragma once
class Vector
{
	int* items;
	int size;
	int capacity;

public:
	Vector() : items{ nullptr },
		size{},
		capacity{} {};

	Vector(int size) : items{ new int[size] {} },
		size{ size },
		capacity{ size } {}

	Vector(const Vector& other)
		: size{ other.size }, capacity{ other.capacity }
	{
		items = new int[capacity];
		for (int i{}; i < size; i++)
			items[i] = other.items[i];
	}
	

	const int& Size() const { return size; }
	const int& Capacity() const { return capacity; }

	void PushBack(int value);
	void PushFront(int value);
	void Insert(int index, int value);

	int PopBack();
	int PopFront();
	int Remove(int index);
	
	void Print();

	~Vector()
	{
		if (items)
			delete[] items;
	}
};

void Vector::PushBack(int value)
{
	if (size < capacity)
	{
		items[size] = value;
		size++;
		return;
	}

	(capacity) ? capacity *= 1.5 : capacity = 2;
	int* newItems = new int[capacity] {};
	for (int i{}; i < size; i++)
		newItems[i] = items[i];
	newItems[size] = value;
	size++;

	if(items)
		delete[] items;
	items = newItems;
}

void Vector::PushFront(int value)
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
	int* newItems = new int[capacity] {};

	for (int i{}; i < size; i++)
		newItems[i + 1] = items[i];
	newItems[0] = value;
	size++;

	delete[] items;
	items = newItems;
}

void Vector::Insert(int index, int value)
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
	int* newItems = new int[capacity];
	for (int i{}; i < index; i++)
		newItems[i] = items[i];
	for (int i{ index }; i < size; i++)
		newItems[i + 1] = items[i];
	newItems[index] = value;
	size++;

	delete[] items;
	items = newItems;
}

void Vector::Print()
{
	for (int i{}; i < size; i++)
		std::cout << items[i] << " ";
	std::cout << "\n";
}

int Vector::PopBack()
{
	if (size <= 0)
		throw "vector is empty";

	if (capacity <= size * 1.5)
	{
		size--;
		return items[size];
	}

	capacity = size * 1.5;
	int* newItems = new int[capacity];
	for (int i{}; i < size; i++)
		newItems[i] = items[i];
	size--;

	delete[] items;
	items = newItems;

	return items[size];
}