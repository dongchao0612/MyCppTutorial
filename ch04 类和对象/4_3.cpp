#include<iostream>

using namespace std;

const float PI = 3.141593;				// 定义PI的值
const float FENCE_PRICE = 35;			// 栅栏的价格
const float CONCRETE_PRICE = 20;		// 过道水泥的单价

class Cricle {
	public:
		Cricle(float r);					//构造函数
		float circumference();				//计算圆的周长
		float area();						//计算圆的面积

	private:
		float radius;
};

//类的实现
//构造函数 初始化成员 radius
Cricle::Cricle(float r) {
	radius = r;
}
//计算圆的周长
float Cricle::circumference() {
	return 2 * PI*radius;
}

//计算圆的面积
float Cricle::area() {
	return PI * radius*radius;
}

int main() {
	float radius = 10;

	Cricle pool(radius);
	Cricle poolRim(radius + 3);

	//计算栅栏价格并输出
	cout << "Fencing Cost is : " << poolRim.circumference()*FENCE_PRICE << endl;

	//计算过道价格并输出
	cout << "Concrete Cost is : " << (poolRim.area() - pool.area())*CONCRETE_PRICE << endl;
}
