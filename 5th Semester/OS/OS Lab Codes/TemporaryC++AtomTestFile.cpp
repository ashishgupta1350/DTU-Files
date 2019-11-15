#include<iostream>
#include<vector>
using namespace std;
int SIZE;

class Vector{
	vector<int> v;
public:
	Vector()
	{
		// nothing
	}
	friend istream& operator >>(istream&,Vector&);
	friend ostream& operator <<(ostream&,Vector&);
	void insert(int data)
	{
		v.push_back(data);
	}

};

istream& operator >> (istream& din,Vector& v)
{
	for(int i=0;i<SIZE;i++)
	{
		cout<<"enter data: ";
		int x;cin>>x;
		v.insert(x);
	}
	return cin;
}

ostream& operator << (ostream& dout,Vector& v)
{
	for(int i=0;i<SIZE;i++)
	{
		dout<<v.v[i]<<" ";
	}
	dout<<endl;
	return dout;
}

int main()
{
	Vector v;
	SIZE=3;
	cin>>v;
	cout<<v<<endl;
}
