#include <Complex.h>

Complex::Complex() {
	this->realPart = 0.0;
	this->imaginaryPart = 0.0;
}

Complex::~Complex() {
	delete this->realPart;
	delete this->imaginaryPart;
}

Complex Complex::add(Complex other) {
	// TODO
	return this;
}

Complex Complex::mult(Complex other) {
	// TODO
	return this;
}

Complex Complex::quot(Complex other) {
	// TODO
	return this;
}

Complex Complex::abs() {
	// TODO
	return this;
}

Complex Complex::compute_polar() {
	// TODO
	return this;
}
