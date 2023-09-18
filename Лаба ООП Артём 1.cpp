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
}

Time::Time(std::string time) {
	if (time.size() < 8) {
		throw;
	}
	hour = (int(time[0]) - 48) * 10 + (int(time[1]) - 48);
	minute = (int(time[3]) - 48) * 10 + (int(time[4]) - 48);
	second = (int(time[6]) - 48) * 10 + (int(time[7]) - 48);
}

Time::Time(int second) {
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

std::string Time::ToString() {
	std::string str;
	unsigned char first;
	unsigned char second;
	unsigned char hours = this->hour;
	unsigned char minutes = this->minute;
	unsigned char seconds = this->second;
	if (int(hours) > 10) {
		first = int(hours) % 10;
		int(hours) = int(hours) / 10;
		second = int(hours) % 10;
		str += first + second + ':';
	}
	else {
		first = int(hours) % 10;
		str += '0' + first + ':';
	}
	if (int(minutes) > 10) {
		first = int(minutes) % 10;
		int(minutes) = int(minutes) / 10;
		second = int(hours) % 10;
		str += first + second + ':';
	}
	else {
		first = int(minutes) % 10;
		str += '0' + first + ':';
	}
	if (int(seconds) > 10) {
		first = int(seconds) % 10;
		int(minutes) = int(seconds) / 10;
		second = int(seconds) % 10;
		str += first + second + ':';
	}
	else {
		first = int(seconds) % 10;
		str += '0' + first + ':';
	}
	return str;
}
Time.h
#include <string>

class Time {
private:
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
public:
	unsigned char getHour() const { return hour; }
	unsigned char getMinute() const { return minute; }
	unsigned char getSecond() const { return second; }
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
	int ToSecond();
	int ToMinute();
	bool TimeComp(const Time& time);
	std::string ToString();

};
