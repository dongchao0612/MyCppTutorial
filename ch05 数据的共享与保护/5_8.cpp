#include<iostream>
#include<cmath>
using namespace std;

class A {
	public:
		A(int a) :a(a) {	//�����ݳ�Աֻ�����б��ʼ��
			// this->a=a;����
		}
		void print() {
			cout << a << ":" << b << endl;
		}
	private:
		const int a; 		//�����ݳ�Ա
		static const int b;	//��̬�����ݳ�Ա
};
const int A::b = 30;    //��̬�ݳ�Ա��Ҫ�����ڶ���֮���������ڶ����ڳ�ʼ��
int main() {
	A a1(100), a2(10);
	a1.print();
	a2.print();

}
