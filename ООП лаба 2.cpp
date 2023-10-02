class Complex {
private:
	double* real;
	double* imag;
public:
	//Complex();
	/// <summary>
	/// конструктор с параметрами
	/// </summary>
	/// <param name="real">действительная часть</param>
	/// <param name="imag">мнимая</param>
	Complex(double real = 0, double imag = 0);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="copy">копируемое</param>
	Complex(const Complex& copy);
	~Complex();
	double* getReal() const { return real; }
	double* getImag() const { return imag; }
	/// <summary>
	/// 
	/// </summary>
	/// <param name="real">реальная часть</param>
	void setReal(double& real) { *(this->real) = real; }
	/// <summary>
	/// 
	/// </summary>
	/// <param name="imag">мнимая часть</param>
	void setImag(double& imag) { *(this->imag) = imag; }
	/// <summary>
	/// 
	/// </summary>
	/// <param name="conclusion">поток вывода</param>
	/// <param name="out">выводимое</param>
	/// <returns>поток ввода</returns>
	friend std::ostream& operator <<(std::ostream& conclusion, Complex& out);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="input">поток ввода</param>
	/// <param name="in">вводимое</param>
	/// <returns>поток вывода</returns>
	friend std::istream& operator >>(std::istream& input, Complex& in);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="summ">слогаемое</param>
	/// <returns>сумма</returns>
	Complex operator +(const Complex& summ);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="subtraction">вычитаемое</param>
	/// <returns>разность</returns>
	Complex operator -(const Complex& subtraction);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="div">делитель</param>
	/// <returns></returns>
	Complex operator /(const Complex& div);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="mult">множитель</param>
	/// <returns></returns>
	Complex operator *(const Complex& mult);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="equally">приравнимое</param>
	/// <returns>деление</returns>
	Complex& operator =(const Complex& equally);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="comp">Сравнимое</param>
	/// <returns>умножение</returns>
	bool operator >(const Complex& comp);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="comp">сравнимое</param>
	/// <returns></returns>
	bool operator <(const Complex& comp);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="comp">сравнимое</param>
	/// <returns></returns>
	bool operator ==(const Complex& comp);

};

#include"Complex.h"

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
	return Complex(*real + *(summ.real), *imag + *(summ.imag));
}

Complex Complex::operator-(const Complex& summ) {
	return  Complex(*real - *(summ.real), *imag - *(summ.imag));
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
