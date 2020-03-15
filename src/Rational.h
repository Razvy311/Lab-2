#pragma once

#include <iostream>

class Rational {
	private:
		double value;
	public:
		// Specified constructor.
		Rational(double value);
		~Rational();

		// Getters
		double getValue() const;

		// Shows the rational number in its standard form.
		// Kind of the same deal as the getter, but it's a string.
		std::string show_rational();

		// Shows rational number the exponential form.
		std::string show_exp();

		// Adds 2 rational numbers together and returns the sum.
		Rational add(Rational other);

		// Multiplies 2 rational numbers together and returns the result.
		Rational mult(Rational other);

		// Divides 2 rational numbers and returns the result.
		Rational quot(Rational other);

		// Returns the absolute value of a rational number.
		Rational abs();
};


