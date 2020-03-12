#include "Complex.h"

Complex::Complex(double realPart, double imaginaryPart) {
	this->realPart = realPart;
	this->imaginaryPart = imaginaryPart;
}

Complex::~Complex() {}

double Complex::getRealPart(){
	return this->realPart;
}

double Complex::getImaginaryPart(){
	return this->imaginaryPart;
}

std::string Complex::show_compl(){
	std::string showComplex = std::to_string(this->realPart) + " + " + std::to_string(this->imaginaryPart) + " * i";
	return showComplex;
}

std::string Complex::show_exp(){
	double radius = this->abs(); 
	double argument = atan(double(this->imaginaryPart/this->realPart));
	std::string showExp = std::to_string(radius) + " * e ^ (i * " + std::to_string(argument) + ")";
	return showExp;
}

Complex Complex::add(Complex other) {
	// TODO
	return Complex(this->realPart + other.realPart, this->imaginaryPart + other.imaginaryPart);
}

Complex Complex::mult(Complex other) {
	// TODO
	return Complex(this->realPart * other.realPart - this->imaginaryPart * other.imaginaryPart, this->realPart * other.imaginaryPart + this->imaginaryPart * other.realPart);
}

Complex Complex::quot(Complex other) {
	// TODO
	double realPartDivision = (this->realPart * other.realPart + this->imaginaryPart + other.imaginaryPart)/(pow(other.realPart, 2) + pow(other.imaginaryPart, 2));
	double imaginaryPartDivision = (other.realPart * this->imaginaryPart - this->realPart * other.imaginaryPart)/(pow(other.realPart, 2) + pow(other.imaginaryPart, 2));
	return Complex(realPartDivision, imaginaryPartDivision);
}

double Complex::abs() {
	// TODO
	return sqrt(pow(this->realPart, 2) + pow(this->imaginaryPart, 2));
}

std::string Complex::compute_polar() {
	// TODO
	double radius = this->abs();
	double argument = atan(double(this->imaginaryPart/this->realPart));
	std::string computePolar = std::to_string(radius) + "*(cos " + std::to_string(argument) + " + i * sin " + std::to_string(argument) + ")";
	return computePolar;
}