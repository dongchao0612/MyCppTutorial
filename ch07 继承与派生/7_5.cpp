#include<iostream>

using namespace std;

class Base1 {
	public:
		Base1(int i) {
			cout << "constructing Base1\t" << i << endl;
		}
		~Base1() {
			cout << "Destructing Base1\t" << endl;
		}
};
class Base2 {
	public:
		Base2(int j) {
			cout << "constructing Base2\t" << j << endl;
		}
		~Base2() {
			cout << "Destructing Base2\t" << endl;
		}
};
class Base3 {
	public:
		Base3() {
			cout << "constructing Base3\t*" << endl;
		}
		~Base3() {
			cout << "Destructing Base3\t*" << endl;
		}
};
class Derived :public Base2, public Base1, public Base3 {
	public:
		Derived(int a, int b, int c, int d) :Base1(a), m2(d), m1(c), Base2(b) {}
	private:
		Base1 m1;
		Base2 m2;
		Base3 m3;
};

int main() {
	Derived obj = Derived(1, 2, 3, 4);
	return 0;
}
