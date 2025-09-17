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

	friend Fraction operator+(Fraction left, Fraction right);
	friend Fraction operator+(Fraction fraction, int number);
	friend Fraction operator+(int number, Fraction fraction);

	friend bool operator>(Fraction left, Fraction right);
	friend bool operator<=(Fraction left, Fraction right);
	friend bool operator<(Fraction left, Fraction right);

	friend bool operator==(Fraction left, Fraction right);
	friend bool operator!=(Fraction left, Fraction right);

	friend std::ostream& operator<<(std::ostream& out, Fraction fraction);

	Fraction operator++();
	Fraction operator++(int);

	const char* ToString();
};

