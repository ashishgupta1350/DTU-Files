#include<iostream>
using namespace std;
#include<vector>

// vector& operator*(int a,vector<int>& v)
// {
// 	for(int i=0;i<v.size;i++)
// 	{
// 		v[i]*=a;
// 	}
// 	return v;
// }
// vector& operator*(vector<int>& v,int a)
// {
// 	for(int i=0;i<v.size;i++)
// 	{
// 		v[i]*=a;
// 	}
// 	return v;
// }

void* operator new(size_t size)
{
	void *p=malloc(size);
	return p;
}

void operator delete(void* p)
{
	free(p);
}

void* operator new(size_t size) {void* p=malloc(size); return p; }

void operator delete(void* p) {free(p); } class complex
{
	int a;
public:
	complex()
	{
		a=10;
	}
	complex operator -(){
		a=-a;
		return *this;
	}
	complex operator ++()
	{
		// preincrement operator
		a+=1;
		return *this;
	}
	int getA()
	{
		return this->a;
	}
	friend ostream& operator <<(ostream& dout,complex c)
	{
		 // there should be no argument
		dout<<c.a<<endl;
		return dout;
	}

	ostream & operator >>(istream& din,complex &c)
	{
		// correct done now
	}
};
int main()
{
	// int* arr=new int[10];
	// for(int i=0;i<10;i++)
	// {
	// 	cin>>arr[i];
	// 	cout<<arr[i]<<endl;
	// }
	// cout<<arr;
	// delete arr;
	cout<<endl;
	// well that does it, pen drop!	
	complex c1;
	// c1=-c1;
	// cout<<c1.getA()<<endl;
	cout<<c1<<endl;
	++c1;
	cout<<c1<<endl;
	return 0;
}