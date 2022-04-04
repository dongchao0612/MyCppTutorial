#include<iostream>

using namespace std;

class Complex {
	public:
		Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}//初始化
		Complex operator+(const Complex& c2)const;
		Complex operator-(const Complex& c2)const;
		void display()const;
	private:
		double real;
		double imaginary;
};
Complex Complex::operator+(const Complex& c2)const {
	return Complex(real + c2.real, imaginary + c2.imaginary);
}//运算符重载函数(作为成员函数)
Complex Complex::operator-(const Complex& c2)const {
	return Complex(real - c2.real, imaginary - c2.imaginary);
}//运算符重载函数(作为成员函数)
void Complex::display()const {
	cout << "(" << real << ", " << imaginary << "i)" << endl;
}
int main() {
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1 = ";
	c1.display();
	cout << "c2 = ";
	c2.display();
	c3 = c1 - c2;
	cout << "c3=c1-c2= ";
	c3.display();
	c3 = c1 +c2;
	cout << "c3=c1-c2= ";
	c3.display();

	return 0;
}
