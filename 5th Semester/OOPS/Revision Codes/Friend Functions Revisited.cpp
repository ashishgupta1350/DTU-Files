#include<iostream>
using namespace std;
class A{
	int data;
public:
	A(int data=10)
	{
		this->data=data;
	}
	friend void getData( A x);

};

class B{public: int x;int y;int z; B() {x=y=z=10; } };

class C{public: int x,y,z; C() {x=y=z=20; } };

class D:public B, public C {public: void printData() {cout<<C::x<<endl; } };

void getData(A x)
{
	cout<<x.data<<endl;
}

int main()
{
	cout<<"Hello"<<endl;
	A a(10);
	getData(a);
	// cout<<a.data<<endl;
	D d;
	d.printData();

	cout<<endl; return 0;
}