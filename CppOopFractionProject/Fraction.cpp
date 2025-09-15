#define _CRT_SECURE_NO_WARNINGS

#include "Fraction.h"
#include <string.h>
#include <cmath>

char* Fraction::IntToChars(int number)
{
    bool negative{ number < 0 };

    number = abs(number);

    int radixNumber{ number };
    int radixs{};

    while (radixNumber)
    {
        radixs++;
        radixNumber /= 10;
    }

    char* result = new char[radixs + 1 + negative] {};
    
    /*for (int i{ radixs - 1 + negative }; i >= 0; i--)
    {
        int digit{ number % 10 };
        result[i] = 48 + digit;
        number /= 10;
    }*/
    int i{ radixs - 1 + negative };
    while (number)
    {
        int digit{ number % 10 };
        result[i] = 48 + digit;
        number /= 10;
        i--;
    }
    if (negative) result[0] = '-';

    return result;
}

void Fraction::Reduction()
{
    int n = abs(numerator);
    int d = abs(denominator);
    
    while (n != 0 && d != 0) 
    {
        if (n > d)
            n %= d;
        else
            d %= n;
    }

    n += d;
    this->numerator /= n;
    this->denominator /= n;
}

Fraction::Fraction() : Fraction(0, 1) {}

Fraction::Fraction(int numerator, int denominator)
	: numerator{ numerator }
{
	if (denominator == 0)
		throw 0;

	this->denominator = denominator;
    Reduction();
}

void Fraction::Numerator(int value) { this->numerator = value; }

int Fraction::Numerator() const { return this->numerator; }

void Fraction::Denominator(int value)
{
	if (value == 0) throw 0;
	this->denominator = value;
}

int Fraction::Denominator() const { return this->denominator; }

void Fraction::Add(Fraction other)
{
    this->numerator = this->numerator * other.denominator
        + this->denominator * other.numerator;
    this->denominator *= other.denominator;
    Reduction();
}

Fraction Fraction::Plus(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator
        + this->denominator * other.numerator;
    result.denominator = this->denominator * other.denominator;
    
    result.Reduction();
    return result;
}

Fraction Fraction::Minus(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator
        - this->denominator * other.numerator;
    result.denominator = this->denominator * other.denominator;

    result.Reduction();
    return result;
}

Fraction Fraction::Multiply(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.numerator;
    result.denominator = this->denominator * other.denominator;
    
    result.Reduction();
    return result;
}

Fraction Fraction::Division(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator;
    result.denominator = this->denominator * other.numerator;
    
    result.Reduction();
    return result;
}

Fraction Fraction::operator+(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator
        + this->denominator * other.numerator;
    result.denominator = this->denominator * other.denominator;

    result.Reduction();
    return result;
}

bool Fraction::operator>(Fraction other)
{
    return this->numerator * other.denominator
        > this->denominator * other.numerator;
}

const char* Fraction::ToString()
{
    char* result = new char[2]{ '[', '\0' };
    strcat(result, IntToChars(numerator));
    strcat(result, "/");
    strcat(result, IntToChars(denominator));
    strcat(result, "]");

    return result;
}
