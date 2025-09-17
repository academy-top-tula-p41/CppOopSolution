#pragma once
#include <iostream>

class Counter;

class FriendClass
{
	int value;
public:
	void PrintCounter(Counter counter);
};

class Counter
{
	int count;

public:
	friend class FriendClass;
	friend void PrintCount(Counter counter);
	void PrintValue(FriendClass friendObj)
	{
		//std::cout << friendObj.value;
	}
};

void PrintCount(Counter counter)
{
	std::cout << counter.count << "\n";
}

void FriendClass::PrintCounter(Counter counter)
{
	std::cout << counter.count << "\n";
}
