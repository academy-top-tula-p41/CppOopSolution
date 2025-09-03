#pragma once
#include <iostream>

class Date
{
    int day{};
    int month{};
    int year{};

public:
    Date() : Date(1, 1, 1) {}

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void SetDay(int d)
    {
        if (d >= 1 && d <= 31)
            day = d;
        else
            throw "incorrect day";
    }

    int GetDay() const { return day; }

    void SetMonth(int m) { month = m; }
    int GetMonth() const { return month; }

    void SetYear(int y) { year = y; }
    int GetYear() const { return year; }

    void ConsolePrint()
    {
        std::cout << day << "."
            << month << "."
            << year << "\n";
    }

};
