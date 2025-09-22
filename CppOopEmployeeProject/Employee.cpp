#include "Employee.h"

Employee::Employee(const char* name, int age)
{
	this->id = ++staticId;

	strcpy_s(this->name, strlen(name) + 1, name);
	this->age = age;
	this->salary = 0;
}

int Employee::StaticId()
{
	return Employee::staticId;
}

int& Employee::operator[](const char* key)
{
	if (!strcmp(key, "age"))
		return this->age;
	if (!strcmp(key, "salary"))
		return this->salary;
}

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
	out << "Id: " << employee.id
		<< ", Name: " << employee.name
		<< ", Age: " << employee.age
		<< ", Salary: " << employee.salary;
	return out;
}
