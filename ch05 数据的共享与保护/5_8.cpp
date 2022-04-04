#include<iostream>
#include<cmath>
using namespace std;

class A {
	public:
		A(int a) :a(a) {	//常数据成员只能用列表初始化
			// this->a=a;报错
		}
		void print() {
			cout << a << ":" << b << endl;
		}
	private:
		const int a; 		//常数据成员
		static const int b;	//静态常数据成员
};
const int A::b = 30;    //静态据成员需要在类内定义之后在类外在定义于初始化
int main() {
	A a1(100), a2(10);
	a1.print();
	a2.print();

}
