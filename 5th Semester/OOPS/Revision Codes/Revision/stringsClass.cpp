#include<iostream>
#include<string>
using namespace std;


int main()
{
	string s="hello";
	string t="hello";
	string u="Iamgeek";
	// cout<<s.compare(t)<<endl;
	// cout<<s.compare(u)<<endl;
	// cout<<s.compare(s)<<endl;
	cout<<s.compare(0,3,t)<<endl;



}