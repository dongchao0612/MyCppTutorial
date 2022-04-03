#include<iostream>

using namespace std;

class Base1 {
	public:
		int var;
		void fun() {
			cout << "member of base1" << endl;
		}
};
class Base2 {
	public:
		int var;
		void fun() {
			cout << "member of base2" << endl;
		}
};

class Derived :public Base2, public Base1 {
	public:
		int var;
		void fun() {
			cout << "member of Derived" << endl;
		}
};

int main() {
	Derived d;
	Derived* p = &d;

	d.var = 1;
	d.fun();

	d.Base1::var = 2;
	d.Base1::fun();

	d.Base2::var = 3;
	d.Base2::fun();
	
	return 0;
}
