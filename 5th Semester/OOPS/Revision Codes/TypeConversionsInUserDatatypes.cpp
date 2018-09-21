// #include<iostream>
// using namespace std;
// #include<string>
// class String{
// public:
// 	string s;
// 	String();
// 	String(string);
// 	void add()
// 	{
// 		for(int i=0;i<s.length();i++)
// 		{
// 			s[i]+=1;
// 		}
// 	}

// };
// String::String(string passedString)
// {
// 	// this does something
// 	this->s=passedString; // string copy constructor is called?

// }
// int main()
// {
// 	string s,t;
// 	String a="Hello",b;
// 	String c(s); 
// 	s=String(a);
// 	t=a;
// 	return 0;
// }

#include<iostream>
using namespace std;
class Time{
	int hrs;
	int mins;
public:
	Time(int t)
	{
		hrs=t/60;
		mins=t%60;
	}
};

// int main()
// {

// 	Time t1(89);
// 	int duration=85;
// 	t1=duration;

// }

// type conversion class to class (new concept)
class bike{
public:

	int tires;
	int price;
	bike(int tires=2,int price=5)
	{
		this->tires=tires;
		this->price=price;
	}

};

class car{
	int tires;
	int price;
public:
	car(int tires=4,int price=10)
	{
		this->tires=tires;
		this->price=price;
	}
	// use type conversion operator
	operator bike()
	{
		// takes no arguments
		// does something and returns a bike
		bike b;
		b.tires=this->tires;
		b.price=this->price;
		return b;
		
	}

};


int main()
{
	car c;
	bike b;
	b=c; // converts a car to a bike
	// print b will do
	cout<<"After converting my bike to a car since bike b= car c, the tires in the bike are : ";
	cout<<b.tires<<endl;
}