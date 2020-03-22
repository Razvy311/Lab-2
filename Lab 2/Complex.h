/*
 * Complex
 *
 *  Created on: Mar 9, 2020
 *      Author: Razvy311
 */
#pragma once

#include <utility>
#include <math.h>
#include <iostream>
#include <string>

class Complex {
	private:
		double realPart;
		double imaginaryPart;

	public:
		// Specified constructor.
		Complex(double realPart, double imaginaryPart);
		~Complex();

		// Getters.
		double getRealPart();
		double getImaginaryPart();

		// Shows the complex number in its standard form.
		std::string show_compl();

		// Shows the complex number in exponential form.
		std::string show_exp();

		// Adds 2 complex numbers together and returns the sum.
		Complex add(Complex other);

		// Multiplies 2 complex numbers together and returns the result.
		Complex mult(Complex other);

		// Divides 2 complex numbers and returns the result.
		Complex quot(Complex other);

		// Returns the absolute values of a complex number.
		double abs() const;

		// Returns the polar form of a complex number.
		std::string compute_polar();
};

// The default comparison operator.
bool operator <(const Complex &complex1, const Complex &complex2);
