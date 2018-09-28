#include<iostream>
using namespace std;

void* operator new(size_t size)
{
	void* p=malloc(size);
	return p;

}
void operator delete(void* p)
{
	free(p); // I believe I can fly

}
int main()
{
	int* arr=new int[10];
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
		cout<<arr[i]<<endl;
	}
	cout<<arr;
	delete arr;
	// well that does it, pen drop!
	
	return 0;
}