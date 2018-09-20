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
int main()
{

	Time t1(89);
	int duration=85;
	t1=duration;

}