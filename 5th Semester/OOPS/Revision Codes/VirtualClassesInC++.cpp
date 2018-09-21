#include<iostream>
using namespace std;
class A{
public:
	void display()
	{
		cout<<"A"<<endl;
	}
};
class B:public virtual A{

};
class C:public virtual A{
// resolves the issue
};
class D: public B, public C{
public:
	void print()
	{
		display();
	}

};
int main()
{
	D d;
	d.print();
	return 0;
}