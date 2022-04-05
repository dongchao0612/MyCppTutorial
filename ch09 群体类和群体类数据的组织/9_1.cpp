#include<iostream>

using namespace std;
template <class T>
void outputArray(const T array, int count)
{
	for (int i = 0; i < count; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main()
{
	const int A_count = 8, B_count = 8, C_count = 20;
	int A[A_count] = { 1,2,3,4,5,6,7,8 };
	double B[B_count] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8 };
	char C[C_count] = "welcome to see you!";
	cout << "A array contains:" << endl;
	outputArray(A, A_count);
	cout << "B array contains:" << endl;
	outputArray(B, B_count);
	cout << "C array contains:" << endl;
	outputArray(C, C_count);
	return 0;
}
