#pragma once
class Fraction
{
	int numerator;
	int denominator;

	char* IntToChars(int number);

public:

	Fraction();
	Fraction(int numerator, int denominator);

	void Numerator(int value);
	int Numerator() const;

	void Denominator(int value);
	int Denominator() const;

	void Add(Fraction other);

	Fraction Plus(Fraction other);
	Fraction Minus(Fraction other);
	Fraction Multiply(Fraction other);
	Fraction Division(Fraction other);

	const char* ToString();
};

