#include<iostream>
using namespace std;
void* operator new(size_t size)
{
	cout<<size<<endl;
	void* p = malloc(size);
	return p;
}
class A{
public:
	void* operator new(size_t size)
	{
		void*p = malloc(size);
		return p;
	}
};

int main()
{
	int *ptr;
	int a;
	ptr=&a;
	cout<<*ptr<<endl;
	int *arr= new int[5];
	arr[0]=1;
	cout<<*arr<<endl;
	return 0;
}
city*ptr[10];
