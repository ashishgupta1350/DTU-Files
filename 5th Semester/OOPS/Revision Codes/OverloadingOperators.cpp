#include<iostream>
using namespace std;

void * operator new(size_t size)
{
	cout<<"New operator overloading : "<<endl;
	void *p=malloc(size);
	return p;
}
void operator delete(void * p)
{
	cout<<"delete operator"<<endl;
	free(p);
}

class complex
{
	int x;
	int y;
public:
	complex(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	complex operator++()
	{
		x++;y++;
		// return c;
		return *this;
	}
	void display()
	{
		cout<<x<< "+ i"<<y<<endl;
	}

};


int main()
{
	// int n=5;
	// int i;
	// int *p=new int[3];
	complex c(10,20);
	// complex d=++c;
	++(++c);
	
	c.display();
	return 0;
}