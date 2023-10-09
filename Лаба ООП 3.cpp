#include <iostream>
#include <ctime>
#include <random>
#include "Money.h"
#include "NumberToStringRu.h"


class Account {
protected:
	std::string* surname;
	unsigned long* accountNumber;
	double* accrualPercentage;
	Money* money;

	void Setsurname(std::string& surname) { *(this->surname) = surname; }
	void SetaccrualPercentage(double& accPer) { *(accrualPercentage) = accPer; }
	void Setmoney(Money& money) { *(this->money) = money; }

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	/// <param name="surname"></param>
	Account();
	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="amount"></param>
	Account(const std::string surname, const int accountNumber, const double accrualPercentage, const Money money);
	~Account();
	std::string* GetSurname() const { return surname; }
	unsigned long* GetaccrualNumber() const { return accountNumber; }
	double* GetaccrualPercentage() const { return accrualPercentage; }
	Money* Getmoney() const { return money; }
	/// <summary>
	/// Смена владельца счёта
	/// </summary>
	/// <param name="surname">Новый пользователь</param>
	void ChangeAccountOwner(const std::string& surname);
	/// <summary>
	/// Вывод денег
	/// </summary>
	/// <param name="amount">Сумма выводимых денег</param>
	/// <returns></returns>
	bool WithdrawMoney(const Money& amount);
	/// <summary>
	/// Внесение денег на счёт
	/// </summary>
	/// <param name="amount">Сумма вносимых денег</param>
	void DepositMoneyToTheAccount(const Money& amount);
	/// <summary>
	/// Изменение процентной ставки
	/// </summary>
	/// <param name="percent">Новый процент</param>
	/// <returns></returns>
	bool ChargeInterest(const double& percent);
	/// <summary>
	/// Перевод в доллары
	/// </summary>
	/// <returns></returns>
	double ToDollar() const { return money->ToDollar(); }
	/// <summary>
	/// перевод в евро
	/// </summary>
	/// <returns></returns>
	double ToEuro() const { return money->ToEuro(); }
	std::string GetTheAmountInWords();
};

#include "Account.h"

Account::Account() {
	srand(time(0));
	surname = new std::string;
	accountNumber = new unsigned long;
	accrualPercentage = new double;
	money = new Money(long(0),unsigned char(0));
	*surname = "None";
	*accountNumber = rand() % (9999999999999999 - 1000000000000000 + 1) + 1000000000000000;
	std::uniform_real_distribution<double> unif(0, 200);
	std::default_random_engine re;
	*accrualPercentage = unif(re);
	
}
Account::Account(const std::string surname, const int accountNumber, 
	const double accrualPercentage, const Money money) {
	this->surname = new std::string;
	this->accountNumber = new unsigned long;
	this->accrualPercentage = new double;
	this->money = new Money();
	*(this->surname) = surname;
	*(this->accountNumber) = accountNumber;
	*(this->accrualPercentage) = accrualPercentage;
	*(this->money) = money;
}

Account::~Account() {
	delete surname;
	delete accountNumber;
	delete accrualPercentage;
	delete money;
}

void Account::ChangeAccountOwner(const std::string& surname) {
	std::cout << "you have changed the user from : " << *this->surname << " to: " << surname<<std::endl;
	*(this->surname) = surname;
}

bool Account::WithdrawMoney(const Money& amount) {
	std::cout << "You have deduced:\n";
	std::cout << amount << std::endl;
	if (*money < amount) {
		std::cout << "You can't withdraw that much money\n";
		return false;
	}
	else {
		*(money) = *(money)-amount;
		std::cout << "Your account has left" << std::endl;
		std::cout << *money << std::endl;
		return true;
	}
	
}

void Account::DepositMoneyToTheAccount(const Money& amount) {
	std::cout << "You have contributed:\n";
	std::cout << amount << std::endl;
	*(money) = *(money)+amount;
	std::cout << "Now on your account!" << std::endl;
	std::cout << *money << std::endl;
}

bool Account::ChargeInterest(const double& percent) {
	int posswordAdmin = 15472342;
	int posswordPeople;
	std::cout << "To increase the percentage, enter the administrator threshold:\n";
	std::cin >> posswordPeople;
	if (posswordAdmin == posswordPeople) {
		std::cout << "Your password is correct, now your percentage:\n";
		*accrualPercentage = *accrualPercentage + percent;
		std::cout << *accrualPercentage << std::endl;
		return true;
	}
	else {
		std::cout << "your password is not correct!\n";
		return false;
	}
}

std::string Account::GetTheAmountInWords()
{
	return  NumberToStringRu::numberLongToString(money->GetRubles()) +" rubles "
		+ NumberToStringRu::numberUnCharToString(money->GetKopecks()) +" kopeks\n";
}

#include <iostream>

class Money {
private:
    long* rubles;
    unsigned char* kopecks;

public:
    /// <summary>
    /// Конструктор по умолчанию
    /// </summary>
    Money();
    /// <summary>
    /// конструктор копирования
    /// </summary>
    /// <param name="other">сумма</param>
    Money(const Money& other);
    /// <summary>
    /// без сылочный конструктор
    /// </summary>
    /// <param name="r">рубли</param>
    /// <param name="k">копейки</param>
    Money(long r, unsigned char k);

    ~Money();
    /// <summary>
    /// Перегруженный оператор присваивания
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    long& GetRubles() { return *rubles; }
    unsigned char& GetKopecks() { return *kopecks; }
    Money& operator=(const Money& other);
    

    /// <summary>
    /// Перегруженный оператор сложения
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    Money operator+(const Money& other)const;

    /// <summary>
    /// перегруженный оператор вычитания
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    Money operator-(const Money& other)const;
    /// <summary>
    /// перегруженный оператор сравнения
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    bool operator==(const Money& other)const;
    /// <summary>
    /// перегруженный оператор неравенства
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    bool operator!=(const Money& other)const;
    /// <summary>
    /// перегруженные оператор сравнения
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    bool operator<(const Money& other)const;
    /// <summary>
    /// перегруженный оператор сравнения
    /// </summary>
    /// <param name="other">сумма</param>
    /// <returns>рубли и копейки</returns>
    bool operator>(const Money& other)const;
    /// <summary>
    /// перегруженная операци ввода
    /// </summary>
    /// <param name="os">поток</param>
    /// <param name="money">сумма</param>
    /// <returns>рубли и копейки</returns>
    friend std::ostream& operator<<(std::ostream& os, const Money& money);

    /// <summary>
    /// перегруженная операция вывода
    /// </summary>
    /// <param name="is">поток</param>
    /// <param name="money">сумма</param>
    /// <returns>рубли и копейки</returns>
    friend std::istream& operator>>(std::istream& is, Money& money);
    /// <summary>
    /// Возвращает сумму в долларах
    /// </summary>
    /// <returns></returns>
    double ToDollar();
    /// <summary>
    /// возвращает сумму в евро
    /// </summary>
    /// <returns></returns>
    double ToEuro();
};


#include "Money.h"

Money::Money() : rubles(new long(0)), kopecks(new unsigned char(0)) {}
Money::Money(long r, unsigned char k) : rubles(new long(r)), kopecks(new unsigned char(k)) {}
Money::Money(const Money& other) : rubles(new long(*other.rubles)), kopecks(new unsigned char(*other.kopecks)) {}
Money::~Money() {
    delete rubles;
    delete kopecks;
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        *rubles = *other.rubles;
        *kopecks = *other.kopecks;
    }
    return *this;
}

Money Money::operator+(const Money& other) const {

    long result = long(*rubles * 100 + int(*kopecks))+ long(*other.rubles * 100 + int(*other.kopecks));
    long r = 0;
    unsigned char k = 0;
    while (result >= 100) {
        r += 1;
        result -= 100;
    }
    k = result;
    return Money(r, k);
}

Money Money::operator-(const Money& other) const {
    long result = long(*rubles * 100 + int(*kopecks)) - long(*other.rubles * 100 + int(*other.kopecks));
    long r = 0;
    unsigned char k = 0;
    while (result >= 100) {
        r += 1;
        result -= 100;
    }
    k = result;
    return Money(r, k);
}

bool Money::operator==(const Money& other) const {
    return *rubles == *other.rubles && *kopecks == *other.kopecks;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Money::operator<(const Money& other) const {
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

bool Money::operator>(const Money& other) const {
    return !(*this < other || *this == other);
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << *money.rubles << "," << static_cast<int>(*money.kopecks);
    return os;
}

std::istream& operator>>(std::istream& is, Money& money) {
    char comma;
    is >> *money.rubles >> comma >> *money.kopecks;
    return is;
}

double Money::ToDollar() {
    return (*rubles + *kopecks / 100.0) / 72.0;
}

double Money::ToEuro() {
    return (*rubles + *kopecks / 100.0) / 86.0;
}

#include <string>

static class NumberToStringRu {
public:
    /// <summary>
    /// Преобразовывает чисто типа long в пропись
    /// </summary>
    /// <param name="number"></param>
    /// <returns></returns>
    static std::string numberLongToString(long number) {
        std::string result;
        static const char* const ones[] = { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
        static const char* const tens[] = { "", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
        static const char* const hundreds[] = { "", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };
        static const char* const thousands[] = { "", "тысяча", "тысячи", "тысяч" };
        int partCount = 0;
        while (number > 0) {
            int part = number % 1000;
            if (part > 0) {
                std::string partStr;
                if (part >= 100) {
                    partStr += hundreds[part / 100];
                    partStr += " ";
                    part %= 100;
                }
                if (part >= 20) {
                    partStr += tens[part / 10];
                    partStr += " ";
                    part %= 10;
                }
                if (part >= 10) {
                    partStr += ones[part];
                }
                else if (part > 0) {
                    partStr += ones[part];
                }
                if (partCount > 0) {
                    partStr += " ";
                    partStr += thousands[partCount];
                }
                if (!result.empty()) {
                    result = partStr + " " + result;
                }
                else {
                    result = partStr;
                }
            }
            number /= 1000;
            ++partCount;
        }
        if (result.empty()) {
            result = "ноль";
        }
        return result;
    }
    /// <summary>
    /// Преобразовывает чисто типа unsigned char в пропись
    /// </summary>
    /// <param name="number"></param>
    /// <returns></returns>
    static std::string numberUnCharToString(unsigned char number) {
        std::string result;
        static const char* const ones[] = { "", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
        static const char* const tens[] = { "", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };
        static const char* const teens[] = { "десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
        static const char* const thousands[] = { "", "тысяча", "тысячи", "тысяч" };
        int partCount = 0;
        int num = number; // приводим unsigned char к int
        while (num > 0) {
            int part = num % 1000;
            if (part > 0) {
                std::string partStr;
                if (part >= 100) {
                    partStr += ones[part / 100];
                    partStr += "сот ";
                    part %= 100;
                }
                if (part >= 20) {
                    partStr += tens[part / 10];
                    partStr += " ";
                    part %= 10;
                }
                if (part >= 10) {
                    partStr += teens[part - 10];
                }
                else if (part > 0) {
                    partStr += ones[part];
                }
                if (partCount > 0) {
                    partStr += " ";
                    partStr += thousands[partCount];
                }
                if (!result.empty()) {
                    result = partStr + " " + result;
                }
                else {
                    result = partStr;
                }
            }
            num /= 1000;
            ++partCount;
        }
        if (result.empty()) {
            result = "ноль";
        }
        return result;
    }

};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	long a = 1;
	unsigned char c = 2;
	Money b(1000, 4);
	Account people("Aren", 12323424232, 12.3, b);
	people.ChangeAccountOwner("Bill");
	people.ChargeInterest(13.1);
	people.DepositMoneyToTheAccount(Money(3, 2));
	people.WithdrawMoney(Money(15,0));
	std::cout << people.GetTheAmountInWords() << std::endl;

}
