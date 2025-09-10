#pragma once
class Fraction
{
	int numerator;
	int denominator;

public:

	Fraction();
	Fraction(int numerator, int denominator);

	void Numerator(int value);
	int Numerator();

	void Denominator(int value);
	int Denominator();
};

