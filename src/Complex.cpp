#include "Complex.h"

/**
 * Constructs an instance of a complex number.
 *
 * @param realPart
 *            - the real part of the complex number.
 * @param imaginaryPart
 *            - the imaginary part of the complex number.
 */
Complex::Complex(double realPart, double imaginaryPart) {
	this->realPart = realPart;
	this->imaginaryPart = imaginaryPart;
}

/** The destructor of class Complex. */
Complex::~Complex() {}

/**
 * Returns the real part of this complex number.
 *
 * @return The real part of this complex number.
 */
double Complex::getRealPart() {
	return this->realPart;
}

/**
 * Returns the imaginary part of this complex number.
 *
 * @return The imaginary part of this complex number.
 */
double Complex::getImaginaryPart() {
	return this->imaginaryPart;
}

/**
 * Returns a string representation of this complex number.
 *
 * Format: <realPart> + <imaginaryPart>i
 *
 * @return a string representation of this complex number.
 */
std::string Complex::show_compl(){
	return std::to_string(this->realPart) + " + " + std::to_string(this->imaginaryPart) + " * i";
}

/**
 * Returns the string representation of the exponential form of this complex number.
 *
 * Format: <radius> * e^(i*<argument>)
 *
 * @return the string representation of the exponential form of this complex number.
 */
std::string Complex::show_exp(){
	double radius = this->abs(); 
	double argument = atan(double(this->imaginaryPart / this->realPart));
	return std::to_string(radius) + " * e ^ (i * " + std::to_string(argument) + ")";
}

/**
 * Returns the result of an addition of 2 complex numbers.
 *
 * @param other
 *            - the complex number to add to this one.
 *
 * @return A new instance of a complex number holding the result of the addition.
 */
Complex Complex::add(Complex other) {
	return Complex(this->realPart + other.realPart, this->imaginaryPart + other.imaginaryPart);
}

/**
 * Returns the result of a multiplication of 2 complex numbers.
 *
 * @param other
 *            - the complex number to multiply to this one.
 *
 * @return A new instance of a complex number holding the result of the multiplication.
 */
Complex Complex::mult(Complex other) {
	return Complex(this->realPart * other.realPart - this->imaginaryPart * other.imaginaryPart, this->realPart * other.imaginaryPart + this->imaginaryPart * other.realPart);
}

/**
 * Returns the result of a division of 2 complex numbers.
 *
 * @param other
 *            - the complex number to divide this one to.
 *
 * @return A new instance of a complex number holding the result of the division.
 */
Complex Complex::quot(Complex other) {
	double realPartDivision = (this->realPart * other.realPart + this->imaginaryPart + other.imaginaryPart) / (pow(other.realPart, 2) + pow(other.imaginaryPart, 2));
	double imaginaryPartDivision = (other.realPart * this->imaginaryPart - this->realPart * other.imaginaryPart) / (pow(other.realPart, 2) + pow(other.imaginaryPart, 2));
	return Complex(realPartDivision, imaginaryPartDivision);
}

/**
 * Returns the absolute value of a complex number.
 *
 * @return The absolute value of a complex number.
 */
double Complex::abs() {
	return sqrt(pow(this->realPart, 2) + pow(this->imaginaryPart, 2));
}

/**
 * Returns the string representation of the polar form of this complex number.
 *
 * Format: <radius> * e^(i*<argument>)
 *
 * @return the string representation of the polar form of this complex number.
 */
std::string Complex::compute_polar() {
	double radius = this->abs();
	double argument = atan(double(this->imaginaryPart / this->realPart));
	return std::to_string(radius) + "*(cos " + std::to_string(argument) + " + i * sin " + std::to_string(argument) + ")";
}
