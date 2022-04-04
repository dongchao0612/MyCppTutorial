#include<iostream>

using namespace std;

class Clock {
	public:

		Clock(int hour, int minute, int second);
		void showTime()const;
		Clock& operator++();
		Clock operator++(int);
	private:
		int hour, minute, second;
};

Clock::Clock(int hour, int minute, int second) {
	if (0 <= hour && hour <= 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	} else {
		cout << "Time error!!!" << endl;
		exit(0);
	}
}
void Clock::showTime()const {
	cout << hour << ":" << minute << ":" << second<<endl;
}

Clock& Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}

Clock Clock::operator++(int) {
	Clock old = *this;
	++(*this);
	return old;
}

int main() {
	Clock c(23, 59, 59);
	cout << "c show:\t";
	c.showTime();
	(c++).operator++();
	cout << "c++ show:\t";
	c.showTime();
	cout << "++c show:\t";
	(++c).showTime();
	return 0;
}
