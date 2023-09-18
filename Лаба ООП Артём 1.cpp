Time.cpp
#include "Time.h"

Time::Time() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

Time::Time(const unsigned char hour, const unsigned char minute, const unsigned char second) {
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
	if (secIn > 86400) {
		this->hour = 23;
		this->minute = 59;
		this->second = 59;
	}
}

Time::Time(std::string time) {
	if (time.size() < 8) {
		throw;
	}
	hour = (int(time[0]) - 48) * 10 + (int(time[1]) - 48);
	minute = (int(time[3]) - 48) * 10 + (int(time[4]) - 48);
	second = (int(time[6]) - 48) * 10 + (int(time[7]) - 48);
	int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
	if (secIn > 86400) {
		this->hour = 23;
		this->minute = 59;
		this->second = 59;
	}

}

Time::Time(int second) {
	if (second > 86400) {
		this->hour = 23;
		this->minute = 59;
		this->second = 59;
	}
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
	while (second >= 3600) {
		hour += 1;
		second -= 3600;
	}
	while (second >= 60) {
		minute += 1;
		second -= 60;
	}
	this->second = second;
}

Time::Time(const Time& time) {
	this->hour = time.hour;
	this->minute = time.minute;
	this->second = time.second;
}

void Time::TimeAdd(int second) {
	if (second > 86400) {

	}
	else {
		while (second >= 3600) {
			hour += 1;
			second -= 3600;
		}
		while (second >= 60) {
			minute += 1;
			second -= 60;
		}
		this->second = second;
		int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
		if (secIn > 86400) {
			this->hour = 23;
			this->minute = 59;
			this->second = 59;
		}
	}
	
}

int Time::TimeDif(const Time& time) {
	int secOut = int(time.hour) * 3600 + int(time.minute) * 60 + int(time.second);
	int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
	return abs(secOut - secIn);
}

void Time::TimeSub(int second) {
	int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
	secIn -= second;
	if (secIn < 0) {
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
	}
	else {
		this->hour = 0;
		this->minute = 0;
		this->second = 0;
		while (secIn >= 3600) {
			hour += 1;
			secIn -= 3600;
		}
		while (secIn >= 60) {
			minute += 1;
			secIn -= 60;
		}
		this->second = secIn;
	}
}

int Time::ToSecond() {
	int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
	return secIn;
}
int Time::ToMinute() {
	int minIn = int(this->hour) * 60 + int(this->minute);
	return minIn;
}

bool Time::TimeComp(const Time& time) {
	int secOut = int(time.hour) * 3600 + int(time.minute) * 60 + int(time.second);
	int secIn = int(this->hour) * 3600 + int(this->minute) * 60 + int(this->second);
	if (secIn > secOut) {
		return true;
	}
	else {
		return false;
	}
}
void Time::Show() {
	if (int(hour) > 9) {
		std::cout << int(hour);
	}
	else {
		std::cout << '0' << int(hour);
	}
	std::cout << ':';
	if (int(minute) > 9) {
		std::cout << int(minute);
	}
	else {
		std::cout << '0' << int(minute);
	}
	std::cout << ':';
	if (int(second) > 9) {
		std::cout << int(second);
	}
	else {
		std::cout << '0' << int(second);
	}
	std::cout << '\n';
}
Time.h
#include <string>

class Time {
private:
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
public:
	int getHour() const { return int(hour); }
	int getMinute() const { return int(minute); }
	int getSecond() const { return int(second); }
	void setHour(int& hour) { this->hour = hour; }
	void setMinite(int& minute) { this->minute = minute; }
	void setSecond(int& second) { this->second = second; }
	Time();
	Time(const unsigned char hour, const unsigned char minute, const unsigned char second);
	Time(std::string time);
	Time(int second);
	Time(const Time& time);
	int TimeDif(const Time& time);
	void TimeAdd(int second);
	void TimeSub(int second);
	void Show();
	int ToSecond();
	int ToMinute();
	bool TimeComp(const Time& time);

};
