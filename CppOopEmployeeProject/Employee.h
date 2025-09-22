#pragma once
#include <iostream>

class Employee
{
	static inline int staticId{};

	int id;
	char name[20];
	
	int age;
	int salary;

public:
	Employee(const char* name, int age);

	static int StaticId();

	int& operator[](const char* key);

	friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
};

