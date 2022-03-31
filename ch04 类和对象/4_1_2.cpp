#include<iostream>

using namespace std;

class Clock{
public:
	Clock(){
		hour=0;
		minute=0;
		second=0;
	}
	Clock(int newH,int newM,int newS); 
	
	void setTime(int newH,int newM,int newS); 
	void showTime();
private:
	int hour,minute,second;
};

Clock::Clock(int newH,int newM,int newS){
	hour=newH;
	minute=newM;
	second=newS;
}

void Clock::setTime(int newH,int newM,int newS){
	hour=newH;
	minute=newM;
	second=newS;
}

void Clock:: showTime(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main()
{
	Clock myclock1;
	Clock myclock2(12,34,12);
	
	myclock1.showTime();
	myclock2.showTime();
	
	return 0;
} 
