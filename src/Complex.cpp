#include <Complex.h>

Complex::Complex() {
	this->realPart = 0.0;
	this->imaginaryPart = 0.0;
}

Complex::~Complex() {
	delete this->realPart;
	delete this->imaginaryPart;
}

Complex add(Complex other) {
	// TODO
	return this;
}

Complex mult(Complex other) {
	// TODO
	return this;
}

Complex quot(Complex other) {
	// TODO
	return this;
}

Complex abs() {
	// TODO
	return this;
}

Complex compute_polar() {
	// TODO
	return this;
}
