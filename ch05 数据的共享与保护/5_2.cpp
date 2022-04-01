#include<iostream>

using namespace std;
int i=1;			//局部变量,静态生存期 

void other()
{
	static int a=3,b; //第二次进入不会被初始化
	int c=10;
	a+=2;
	i+=32;
	c+=5;
	cout<<"---OTHER---"<<endl;
	cout<<"i : "<<i<<" a : "<<a<<" b : "<<b<<" c : "<<c<<endl;
	
 } 
int main()
{
	
	static int a;		//静态局部变量，全局寿命 
	int b=-10,c=0;		//局部变量，局部寿命 
	
	cout<<"---MAIN---"<<endl;
	cout<<"i : "<<i<<" a : "<<a<<" b : "<<b<<" c : "<<c<<endl;
	c+=8;
	other();
	cout<<"---MAIN---"<<endl;
	cout<<"i : "<<i<<" a : "<<a<<" b : "<<b<<" c : "<<c<<endl;
	i+=10;
	other();
	return 0;
}
