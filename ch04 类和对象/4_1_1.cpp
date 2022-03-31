#include<iostream>

using namespace std;

class Clock {										//时钟类的定义 
public:												//共有接口
	void setTime(int newH, int newM, int newS);
	void showTime();
private:											//私有数据成员
	int hour, minute, second;
};
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime() {
	cout << hour << ":" << minute << ":" << second << endl;
}
int main()
{
	Clock myclock;									//创建对象 
	
	myclock.setTime(12, 43, 34);					//设置时间
	cout << "First time set and output:\n";			
	myclock.showTime();								//显示时间 
	
	myclock.setTime(6, 45, 13);						//设置时间
	cout << "Second time set and output:\n";		//显示时间 
	myclock.showTime();
	
	return 0;
}

