#include "complex.hpp"

Complex::Complex(double re, double im) : r(re), i(im) {};

double Complex::real() const { return r; }

double Complex::imag() const { return i; }

//function of complex number multiplication
Complex mul(const Complex& z1, const Complex& z2) {
	return Complex(z1.real() * z2.real() - z1.imag() * z2.imag(), z1.imag() * z2.real() + z1.real() * z2.imag()); //(a+bi)(c+di) = (ac-bd)+ (ad+bc)i
}

//function of complex number addition
Complex add(const Complex& z1, const Complex& z2) {

	return Complex(z1.real() + z2.real(), z1.imag() + z2.imag());
}

//function of complex number negation
Complex neg(const Complex& z) {

	return Complex(-z.real(), -z.imag());
}

