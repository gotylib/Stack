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
	void setReal(double& real) { *(this->real) = real; }
	void setImag(double& imag) { *(this->imag) = imag; }
	friend std::ostream& operator <<(std::ostream& conclusion, Complex& out);
	friend std::istream& operator >>(std::istream& input, Complex& in);
	Complex operator +(const Complex& summ);
	Complex operator -(const Complex& subtraction);
	Complex operator /(const Complex& div);
	Complex operator *(const Complex& mult);
	Complex& operator =(const Complex& equally);
	bool operator >(const Complex& comp);
	bool operator <(const Complex& comp);
	bool operator ==(const Complex& comp);

};

Complex::Complex(double real, double imag) {
	this->real = new double;
	this->imag = new double;
	*(this->real) = real;
	*(this->imag) = imag;
}
Complex::Complex(const Complex& copy) {
	real = new double;
	imag = new double;
	real = copy.real;
	imag = copy.imag;
}
Complex::~Complex() {
	delete real;
	delete imag;
}

std::ostream& operator <<(std::ostream& conclusion, Complex& out) {
	conclusion << "Real: " << *(out.real) << '\n';
	conclusion << "Imaginary: " << *(out.imag) << '\n';
	return conclusion;
}

std::istream& operator >>(std::istream& input, Complex& in) {
	double real;
	double imag;
	input >> real >> imag;
	*(in.real) = real;
	*(in.imag) = imag;
	return input;

}

Complex Complex::operator+(const Complex& summ) {
	return Complex (*real + *(summ.real), *imag + *(summ.imag));
}

Complex Complex::operator-(const Complex& summ) {
	 return  Complex (*real - *(summ.real), *imag - *(summ.imag));
}

Complex Complex::operator*(const Complex& mult) {
	return Complex((*real) * (*mult.real) - (*imag) * (*mult.imag), (*real) * (*mult.imag) + (*mult.real) * (*imag));
}

Complex Complex::operator/(const Complex& div) {
	return Complex(((*real) * (*div.real) - (*imag) * (*div.imag)) / ((*div.real) * (*div.real) + (*div.imag) * (*div.imag)), ((*real) * (*div.imag) + (*div.real) * (*imag)) / ((*div.real) * (*div.real) + (*div.imag) * (*div.imag)));
}

Complex& Complex::operator=(const Complex& equally) {
	if (this == &equally) {
		return *this;
	}
	else {
		delete real; 
		delete imag;
		real = new double; 
		imag = new double;
		*real = *(equally.real);
		*imag = *(equally.imag);
		return *this;
	}
}

bool Complex::operator >(const Complex& comp) {
	double lenl = abs((*real) * ((*real))) + abs((*imag) * ((*imag)));
	double lenr = abs((*comp.real) * ((*comp.real))) + abs((*comp.imag) * ((*comp.imag)));

	if (lenl > lenr) {
		return true;
	}
	else {
		return false;
	}
}

bool Complex::operator <(const Complex& comp) {
	double lenl = abs((*real) * ((*real))) + abs((*imag) * ((*imag)));
	double lenr = abs((*comp.real) * ((*comp.real))) + abs((*comp.imag) * ((*comp.imag)));

	if (lenl < lenr) {
		return true;
	}
	else {
		return false;
	}
}

bool Complex::operator ==(const Complex& comp) {
	double lenl = abs((*real) * ((*real))) + abs((*imag) * ((*imag)));
	double lenr = abs((*comp.real) * ((*comp.real))) + abs((*comp.imag) * ((*comp.imag)));
	double epsilon = 0.00001;
	if (abs(lenl - lenr) < epsilon) {
		return true;
	}
	else {
		return false;
	}
}
