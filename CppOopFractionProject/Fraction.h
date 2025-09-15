#pragma once
class Fraction
{
	int numerator;
	int denominator;

	char* IntToChars(int number);
	void Reduction();

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

	Fraction operator+(Fraction other);

	bool operator>(Fraction other);

	const char* ToString();
};

