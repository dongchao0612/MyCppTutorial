#include<iostream>

using namespace std;

class Point
{
public:
	Point();

	Point(int x, int y);
	void move(int newX, int newY);
	int getX()const;
	int getY()const;
	~Point();

private:
	int x, y;
};
Point::Point()
{
	x = y = 0;
	cout << "Default constructor called" << endl;
}

Point::Point(int x, int y) :x(x), y(y)
{
	cout << "constructor called" << endl;
}


int Point::getX()const
{
	return x;
}
int Point::getY()const
{
	return y;
}
void Point::move(int newX, int newY)
{
	x = newX;
	y = newY;
	cout << "moving the point to (" << newX << "," << newY << ")" << endl;
}
Point::~Point()
{
	cout << "destructor called" << endl;
}
int main()
{
	Point p[2] ;
	cout << "(" << p[0].getX() << "," << p[0].getY() << ")" << endl;
	cout << "(" << p[1].getX() << "," << p[1].getY() << ")" << endl;
	for(int i=0;i<2;i++)
		p[i].move(i+10,i+20);
	cout << "(" << p[0].getX() << "," << p[0].getY() << ")" << endl;
	cout << "(" << p[1].getX() << "," << p[1].getY() << ")" << endl;
	return 0;
}
