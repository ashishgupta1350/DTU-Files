#include<iostream>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	// this will produce a lot of input, It will count the number of lines?
	int countChar=0;
	int countNum=0;
	int spaces,specialChar;
	spaces=specialChar=0;
	for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		if(ch>='0' and ch<='9')
		{
			countNum++;
		}
		else if(ch>='a' and ch<='z')
		{
			countChar++;
		}
		else if(ch>='A' and ch<='Z')
		{
			countChar++;
		}
		else if (ch==' ')
		{
			specialChar++;
			spaces++;
		}
		else {
			specialChar++;
		}

		
	}

	cout<<"SpecialChar: "<<specialChar<<endl;
	cout<<"Spaces: "<<spaces<<endl;
	cout<<"countChar: "<<countChar<<endl;
	cout<<"CountNum: "<<countNum<<endl;

	return 0;


}
