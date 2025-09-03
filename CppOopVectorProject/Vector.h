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

	Vector(int size) : items{ new int[size] },
		size{ size },
		capacity{ size } {}

	const int& Size() const { return size; }
	const int& Capacity() const { return capacity; }

	~Vector()
	{
		if (items)
			delete[] items;
	}
};

