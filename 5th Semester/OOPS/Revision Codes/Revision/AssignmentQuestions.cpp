#include<iostream>
using namespace std;

int main()
{
	char ch='x';
	char *const p=&ch;
	char ch1='y';
	char const*q=&ch1;
	cout<<*p<<" "<<*q<<endl;00  
	q=&ch;
	cout<<*p<<" "<<*q<<endl;
	return 0;
}