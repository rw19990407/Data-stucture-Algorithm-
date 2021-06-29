#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
public:

	Complex(double re = 0, double im = 0); 

	double real() const; //real part

	double imag() const; //imaginary part


private:

	double r = 0; //both part to be zero
	double i = 0;
};

//initialize mult, add, neg
Complex mul(const Complex & z1, const Complex & z2);

Complex add(const Complex & z1, const Complex & z2);

Complex neg(const Complex & z);
#endif
