#include<iostream>
using namespace std;
class String
{
public:
	string s;
	String()
	{
		s="hey";
	}
	String(int a)
	{
		s="I have changed";

	}
	operator double();
	operator float();
	operator int();
};
String::operator double()
{
	double sum=s.length();
	return sum;
}
String:: operator int()
{
	int sum=s.length();
	return sum;
}

int main()
{
	String s;
	s=10;
	cout<<s.s<<endl;
	double x=s;
	cout<<x<<endl;
}