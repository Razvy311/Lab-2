#include "Rational.h"
#include <iostream>

using namespace std;

/**
 * Constructs an instance of a rational number.
 *
 * @param value
 *            - the value of the rational number.
 */
Rational::Rational(double value) {
	this->value = value;
}

/** The destructor of class Rational. */
Rational::~Rational() {}

/**
 * Returns the value of this rational number.
 *
 * @return The value of this rational number.
 */
double Rational::getValue() const {
	return this->value;
}

/**
 * Returns a string representation of this rational number.
 *
 * Just convert the double to a string and strip the zeroes if any.
 *
 * @return A string representation of this rational number.
 */
string Rational::show_rational() {
	string resultString = to_string(this->value);

	resultString.erase(resultString.find_last_not_of('0') + 1, string::npos);
	if(resultString.find('.') == resultString.length() - 1)
		resultString = resultString.substr(0, resultString.length() - 1);

	return resultString;
}

/**
 * Returns a string representation of the exponential form of this rational number.
 *
 * @return A string representation of the exponential form of this rational number.
 */
string Rational::show_exp() {
	string rationalNumber = show_rational();

	string wholePart = rationalNumber.substr(0, rationalNumber.find('.'));

	string decimalPart = "";
	if(rationalNumber.find('.') != -1)
		decimalPart = rationalNumber.substr(rationalNumber.find('.') + 1, rationalNumber.length() - wholePart.length() - 1);

	// Construct the exponential form.
	string result = "";

	// Whole part.
	for(unsigned int i = 0; i < wholePart.length(); ++i) {
		if(wholePart.at(i) == '-') {
			result += " -";
			continue;
		}

		result += string(1, wholePart.at(i)) + "*10^" + to_string(wholePart.length() - i - 1);
		if(i != wholePart.length() - 1)
			result += " + ";
	}

	// Decimal part.
	for(unsigned int i = 0; i < decimalPart.length(); ++i)
		result += " + " + string(1, decimalPart.at(i)) + "*10^(-" + to_string(i + 1) + ")";

	return result;
}

/**
 * Returns the result of an addition of 2 rational numbers.
 *
 * @param other
 *            - the rational number to add to this one.
 *
 * @return A new instance of a rational number holding the result of the addition.
 */
Rational Rational::add(Rational other) {
	return Rational(this->value + other.getValue());
}

/**
 * Returns the result of a multiplication of 2 rational numbers.
 *
 * @param other
 *            - the rational number to multiply to this one.
 *
 * @return A new instance of a rational number holding the result of the multiplication.
 */
Rational Rational::mult(Rational other) {
	return Rational(this->value * other.getValue());
}

/**
 * Returns the result of a division of 2 rational numbers.
 *
 * @param other
 *            - the rational number to divide this one to.
 *
 * @return A new instance of a rational number holding the result of the division.
 */
Rational Rational::quot(Rational other) {
	return Rational(this->value / other.getValue());
}

/**
 * Returns the absolute value of a rational number.
 *
 * @return The absolute value of a rational number.
 */
Rational Rational::abs() {
	return Rational(this->value >= 0 ? this->value : -this->value);
}

/** The default sort operator. */
bool operator <(const Rational &rational1, const Rational &rational2) {
	return (rational1.getValue() < rational2.getValue());
}
