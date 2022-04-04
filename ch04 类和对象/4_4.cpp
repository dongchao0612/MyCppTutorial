#include<iostream>
#include<cmath>
using namespace std;

class Point {
	public:
		Point(int xx, int yy) {
			x = xx;
			y = yy;
		}
		Point(Point &p);
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
	private:
		int x, y;
};

Point::Point(Point &p) {
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of Point" << endl;
}

class Line {
	public:
		Line(Point xp1, Point xp2);
		Line(Line &l);
		double getLen() {
			return len;
		}
	private:
		Point p1, p2;
		double len;
};
// 类名::类名(形参表) :内嵌对象1(形参表), 内嵌对象2(形参表)
Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2) {
	double x = double(p1.getX() - p2.getX());
	double y = double(p1.getY() - p2.getY());
	len = sqrt(x*x + y * y);
	cout << "Calling the  constructor of Line" << endl;
}
Line::Line(Line &l) :p1(l.p1), p2(l.p2) {
	len = l.len;
	cout << "Calling the copy constructor of Line" << endl;
}
int main() {
	Point myp1(1, 1), myp2(4, 5);
	Line line(myp1, myp2);
	cout << endl;
	Line line2(line);
	cout << endl;
	cout << "The length of the line : " << line.getLen() << endl;
	cout << "The length of the line2 : " << line2.getLen() << endl;
}
