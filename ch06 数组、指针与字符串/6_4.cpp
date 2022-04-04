#include<iostream>
#include<cmath>
using namespace std;


class Point
{
	public:
		Point(double x, double y);
		double getX()const;
		double getY()const;
	private:
		double x, y;
};
Point::Point(double x, double y) :x(x), y(y)
{
}
double Point::getX()const
{
	return x;
}
double Point::getY()const
{
	return y;
}
float lineFit(const Point points[],int npoint)
{
	float avgX=0,avgY=0;
	float lxx=0,lyy=0,lxy=0;
	for(int i=0; i<npoint; i++) {
		avgX+=points[i].getX()/npoint;
		avgY+=points[i].getY()/npoint;
	}

	for(int i=0; i<npoint; i++) {
		lxx+=(points[i].getX()-avgX)*(points[i].getX()-avgX);
		lyy+=(points[i].getY()-avgY)*(points[i].getY()-avgY);
		lxy+=(points[i].getX()-avgY)*(points[i].getY()-avgY);
	}
	cout<<"This line acn be fitted by y=a*x+b."<<endl;
	cout<<"a = "<<lxy/lxx<<" ";
	cout<<"b = "<<avgY-lxy*avgX/lxx <<endl;

	return static_cast<float>(lxy/sqrt(lxx*lyy));
}
int main()
{
	//Point p[10]= {Point(6,10),Point(14,20),Point(26,30),Point(33,40),Point(46,50),Point(54,60),Point(67,70),Point(75,80),Point(84,90),Point(100,100)};
	Point P1(6,10),P2(14,20),P3(26,30),P4(33,40),P5(46,50),P6(54,60),P7(67,70),P8(75,80),P9(84,90),P10(100,100);
	Point PP[]= {P1,P2,P3,P4,P5,P6,P7,P8,P9,P10};
	float r=lineFit(PP,10);
	cout<<"Line coefficient r = "<<r;
	return 0;
}
