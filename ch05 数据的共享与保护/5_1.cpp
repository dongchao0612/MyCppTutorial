#include<iostream>

using namespace std;
int i;
namespace Ns {
	int j;
}
int main()
{
	i = 5;
	Ns::j = 6;
	{
		using namespace Ns;
		int i;
		i = 7;
		cout << "局部变量i = " << i << endl;
		cout << "全局变量i = " << ::i << endl;
		cout << "Ns::j = " << j << endl;
	}
	cout << "i = " << i << endl;
	return 0;
}
