#include <string>
#include "Money.h"

class Payment {
private:
    std::string fullname;
    Money* salary;
    int* employmentYear;
    double* bonusPercentage;
    double* incomeTax;
    int* workedDays;
    int* workingDays;
    Money* earnings;
    Money* deductions;

public:
    Payment(const std::string name, Money salary, int year, double bonusPercentage, double incomeTax,
        int workedDays, int workingDays, int employmentYear);
    Payment();
    Money calculateEarnings();
    Money calculateDeductions();
    Money calculateNetPayment();
    int calculateExperience();
};

#include "Payment.h"


Payment::Payment(const std::string name, Money salary, int year, double bonusPercentage, double incomeTax,
	int workedDays, int workingDays, int employmentYear)
{
	this->salary = new Money(salary);
	this->bonusPercentage = new double(bonusPercentage);
	this->incomeTax = new double(incomeTax);
	this->workedDays = new int(workedDays);
	this->workingDays = new int(workingDays);
	this->deductions = new Money();
	this->earnings = new Money();
	this->employmentYear = new int(employmentYear);

}

Payment::Payment() {
	this->salary = new Money();
	this->bonusPercentage = new double(0.0);
	this->incomeTax = new double();
	this->workedDays = new int(0);
	this->workingDays = new int(0);
	this->deductions = new Money();
	this->earnings = new Money();
	this->employmentYear = new int(0);
}

Money Payment::calculateEarnings()
{
	double res = int(*workedDays / *workingDays);
	Money baseEarnings = salary->MultiplyByScalar(res);
	Money bE(baseEarnings);
	Money bonus;
	bonus = bE.MultiplyByScalar(*bonusPercentage);
	*earnings = baseEarnings + bonus;
	return *earnings;
}

Money Payment::calculateDeductions()
{
	double res = 0.01;
	Money er(*earnings);
	Money er2(*earnings);
	Money pensionFund = er.MultiplyByScalar (res);
	er = (er2 - pensionFund);
	Money tax = er.MultiplyByScalar(*incomeTax);
	*deductions = pensionFund + tax;
	return *deductions;
}

Money Payment::calculateNetPayment()
{
	return (*earnings - *deductions);
}

int Payment::calculateExperience()
{
	int currentYear = 2022;  // текущий год
	return currentYear - *employmentYear;
}


#include <iostream>

class Money {
private:
    long* rubles;
    unsigned char* kopecks;

public:
    Money() : rubles(new long(0)), kopecks(new unsigned char(0)) {}
    Money(long r, unsigned char k) : rubles(new long(r)), kopecks(new unsigned char(k)) {}
    Money(const Money& other) : rubles(new long(*other.rubles)), kopecks(new unsigned char(*other.kopecks)) {}
    ~Money() {
        delete rubles;
        delete kopecks;
    }

    Money MultiplyByScalar(double& scal) {
        long allKop = long(*rubles*100 + int(*kopecks));
        allKop *= scal;
        *rubles = 0;
        *kopecks = 0;
        while (allKop >= 100) {
            *rubles += 1;
            allKop -= 100;
        }
        *kopecks = allKop;
        return *this;
    }

    Money& operator=(const Money other) {
        if (*this != other) {
            *rubles = *other.rubles;
            *kopecks = *other.kopecks;
        }
        return *this;
    }

    Money operator+(const Money& other) const {
        long allKop = long(*rubles * 100 + int(*kopecks));
        long allKopOt = long(*other.rubles * 100 + int(*other.kopecks));
        long res = allKop + allKopOt;
        *rubles = 0;
        *kopecks = 0;
        while (res >= 100) {
            *rubles += 1;
            res -= 100;
        }
        *kopecks = res;
        return *this;
    }

    Money operator-(const Money& other) const {
        long allKop = long(*rubles * 100 + int(*kopecks));
        long allKopOt = long(*other.rubles * 100 + int(*other.kopecks));
        long res = allKop - allKopOt;
        *rubles = 0;
        *kopecks = 0;
        while (res >= 100) {
            *rubles += 1;
            res -= 100;
        }
        *kopecks = res;
        return *this;
    }
    Money operator*(const Money& other) const {
        long r = static_cast<long>(*rubles * *other.rubles);
        unsigned char k = static_cast<unsigned char>(*kopecks * *other.kopecks);
        if (k >= 100) {
            r += k / 100;
            k %= 100;
        }
        return Money(r, k);
    }

    Money operator/(const Money& other) const {
        long r = static_cast<long>(*rubles / *other.rubles);
        unsigned char k = static_cast<unsigned char>((*rubles / *other.rubles - r) * 100 + (*kopecks / *other.kopecks));
        return Money(r, k);
    }

    bool operator==(const Money& other) const {
        return *rubles == *other.rubles && *kopecks == *other.kopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool operator<(const Money& other) const {
        if (*rubles < *other.rubles) {
            return true;
        }
        else if (*rubles > *other.rubles) {
            return false;
        }
        else {
            return *kopecks < *other.kopecks;
        }
    }

    bool operator>(const Money& other) const {
        return !(*this < other || *this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        os << *money.rubles << " rubles " << static_cast<int>(*money.kopecks)<<" kopecks ";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Money& money) {
        char comma;
        is >> *money.rubles >> comma >> *money.kopecks;
        return is;
    }

    double ToDollar() {
        return (*rubles + *kopecks / 100.0) / 72.0;
    }

    double ToEuro() {
        return (*rubles + *kopecks / 100.0) / 86.0;
    }
};



#include "Payment.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Money salary(long(30000), unsigned char(0));
    Money bonusPer(10000, 0);
    Payment employee("Иванов Иван Иванович", salary, 2018, 0.1, 0.13, 24, 22, 2018);
    Money earnings = employee.calculateEarnings();
    Money deductions = employee.calculateDeductions();
    Money netPayment = employee.calculateNetPayment();
    int experience = employee.calculateExperience();

    std::cout << "Начисленная сумма: " << earnings << std::endl;
    std::cout << "Удержанная сумма: " << deductions << std::endl;
    std::cout << "Сумма, выдаваемая на руки: " << netPayment << std::endl;
    std::cout << "Стаж: " << experience << " лет" << std::endl;

    return 0;
}
