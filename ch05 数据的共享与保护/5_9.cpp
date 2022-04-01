#include<iostream>
#include<cmath>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}
	Point(Point& p)
	{
		x = p.x;
		y = p.y;
		cout << "Point(Point& p)" << endl;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	friend float dist(const Point& p1, const Point& p2);   //不发生复制构造 
private:
	int x, y;
};

float dist(const Point& p1, const Point& p2)
{
	return static_cast<float>(sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

int main()
{
	const Point p1(1, 1), p2(4, 5);
	cout << "The distence is " << dist(p1, p2) << endl;
}
