/*
 * Complex
 *
 *  Created on: Mar 9, 2020
 *      Author: Razvy311
 */

#include <utility>

class Complex {
	private:
		double realPart;
		double imaginaryPart;

	public:
		// Specified constructor.
		Complex();

		// Adds 2 complex numbers together and returns the sum.
		Complex add(Complex other);

		// Multiplies 2 complex numbers together and returns the result.
		Complex mult(Complex other);

		// Divides 2 complex numbers and returns the result.
		Complex quot(Complex other);

		// Returns the absolute values of a complex number.
		Complex abs();

		// Returns the polar form of a complex number.
		Complex compute_polar();
};
