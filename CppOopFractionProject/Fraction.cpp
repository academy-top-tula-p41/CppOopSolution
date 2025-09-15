#define _CRT_SECURE_NO_WARNINGS

#include "Fraction.h"
#include <string.h>

char* Fraction::IntToChars(int number)
{
    int radixNumber{ number };
    int radixs{};

    while (radixNumber)
    {
        radixs++;
        radixNumber /= 10;
    }

    char* result = new char[radixs + 1] {};

    for (int i{ radixs - 1 }; i >= 0; i--)
    {
        int digit{ number % 10 };
        result[i] = 48 + digit;
        number /= 10;
    }

    return result;
}

Fraction::Fraction() : Fraction(0, 1) {}

Fraction::Fraction(int numerator, int denominator)
	: numerator{ numerator }
{
	if (denominator == 0)
		throw 0;

	this->denominator = denominator;
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
}

Fraction Fraction::Plus(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator
        + this->denominator * other.numerator;
    result.denominator = this->denominator * other.denominator;
    
    return result;
}

Fraction Fraction::Minus(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator
        - this->denominator * other.numerator;
    result.denominator = this->denominator * other.denominator;

    return result;
}

Fraction Fraction::Multiply(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.numerator;
    result.denominator = this->denominator * other.denominator;
    return result;
}

Fraction Fraction::Division(Fraction other)
{
    Fraction result;
    result.numerator = this->numerator * other.denominator;
    result.denominator = this->denominator * other.numerator;
    return result;
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
