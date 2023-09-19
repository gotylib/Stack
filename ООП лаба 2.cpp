#include <iostream>

class Complex {
private:
	double* real;
	double* imag;
public:
	Complex(double real, double imag);
	Complex(const Complex& copy);
	~Complex();
	double* getReal() const { return real; }
	double* getImag() const { return imag; }
	void setReal(double &real) { *(this->real) = real; }
	void setImag(double &imag) { *(this->imag) = imag; }
	friend std::ostream& operator <<(std::ostream& conclusion, const Complex& out);
	friend std::istream& operator >>(std::istream& input, const Complex& in);
	Complex operator +(const Complex& summ);
	Complex operator -(const Complex& subtraction);
	Complex operator /(const Complex& division);
	Complex operator *(const Complex& multiplication);
};

Complex::Complex(double real, double imag) {
	this->real = new double;
	this->imag = new double;
	*(this->real) = real;
	*(this->imag) = imag;
}
Complex::Complex(const Complex& copy) {
	this->real = copy.real;
	this->imag = copy.imag;
}
Complex::~Complex() {
	delete real;
	delete imag;
}

std::ostream& operator <<(std::ostream& conclusion, const Complex& out) {
	conclusion << "Real: " << *(out.real) << '\n';
	conclusion << "Imaginary: " << *(out.imag) << '\n';
	return conclusion;
}

std::istream& operator >>(std::istream& input, const Complex& in) {
	double real;
	double imag;
	input >> real >> imag;
	*(in.real) = real;
	*(in.imag) = imag;
	return input;

}

Complex Complex::operator+(const Complex& summ) {
	Complex result(*real + *(summ.real), *imag + *(summ.imag));
	return result;
}

Complex Complex::operator-(const Complex& summ) {
	Complex result(*real - *(summ.real), *imag - *(summ.imag));
	return result;
}
