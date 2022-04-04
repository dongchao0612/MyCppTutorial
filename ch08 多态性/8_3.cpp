#include<iostream>

using namespace std;
class Complex {
	public:
		Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}//≥ı ºªØ
		friend Complex operator+(const Complex& c1, const Complex& c2);
		friend Complex operator-(const Complex& c1, const Complex& c2);
		friend ostream& operator<<(ostream& out, const Complex& cc);
	private:
		double real;
		double imaginary;
};
Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

Complex operator-(const Complex& c1, const Complex& c2) {
	return Complex(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

ostream& operator<<(ostream& out, const Complex& c) {
	out << "(" << c.real << ", " << c.imaginary << ")" << endl;
	return out;
}

int main() {
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1 = " << c1;
	cout << "c2 = " << c2;
	c3 = c1 - c2;
	cout << "c3=c1-c2= " << c3;
	c3 = c1 + c2;
	cout << "c3=c1-c2= " << c3;
	return 0;
}



