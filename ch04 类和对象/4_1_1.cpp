#include<iostream>

using namespace std;

class Clock {										//ʱ����Ķ��� 
public:												//���нӿ�
	void setTime(int newH, int newM, int newS);
	void showTime();
private:											//˽�����ݳ�Ա
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
	Clock myclock;									//�������� 
	
	myclock.setTime(12, 43, 34);					//����ʱ��
	cout << "First time set and output:\n";			
	myclock.showTime();								//��ʾʱ�� 
	
	myclock.setTime(6, 45, 13);						//����ʱ��
	cout << "Second time set and output:\n";		//��ʾʱ�� 
	myclock.showTime();
	
	return 0;
}

