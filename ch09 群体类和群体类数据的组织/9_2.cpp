#include<iostream>

using namespace std;

struct Student {
	int id;
	float gpa;
};
template <class T>
class Store
{
	public:
		Store();
		T& getElem();
		void putElem(const T& elem) ;
	private:
		T item;
		bool havevalue;
};
template<class T>
Store<T>::Store()
{
	this->havevalue = false;
}

template<class T>
T& Store<T>::getElem()
{
	if (!havevalue) {
		cout << "No item present" << endl;
		exit(0);
	}
	return item;
}

template<class T>
void Store<T>::putElem(const T& elem)
{
	this->havevalue = true;
	this->item = elem;
}

int main()
{
	Store<int> s1;
	//s1.getElem();
	s1.putElem(-2);
	cout << s1.getElem() << endl;

	Store<double> s2;
	//s2.getElem();
	s2.putElem(3.3);
	cout << s2.getElem() << endl;

	Student stu;
	stu.id = 1000;
	stu.gpa = 3;
	Store<Student> s3;
	//s3.getElem();
	s3.putElem(stu);
	cout << s3.getElem().id << endl;
	cout << s3.getElem().gpa<< endl;

	return 0;
}



