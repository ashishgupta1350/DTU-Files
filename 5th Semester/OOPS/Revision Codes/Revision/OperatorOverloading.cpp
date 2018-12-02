#include<iostream>
using namespace std;
class complex{
	int x,y;
public:
	complex(int x=0,int y=0): x(x),y(y)
	{

	}
	// complex operator ++()
	// {
	// 	x++;y++;
	// 	return *this;
	// }
	complex operator - (int y)
	{
		this->x-=y;
		this->y-=y;
		return *this;
	}
	// friend complex operator ++(complex &,complex &);
	// friend complex operator ++(complex &,int);
	void print()
	{
		cout<<x<<" +i"<<y<<endl;
	}
	friend complex operator ++(complex &,int );

	friend complex operator-(complex &,int &);
	friend complex operator+(complex &,int &);

	friend complex operator-(int &,complex &);

};

complex operator-(complex &c2,int &x)
{
	c2.x-=x;
	c2.y-=x;
	return c2;
}

complex operator+(complex &c2,int &x)
{
	c2.x+=x;
	c2.y+=x;
	return c2;
}

complex operator-(int &x,complex &c2)
{
	c2.x-=x;
	c2.y-=x;
	return c2;
}
// complex operator ++(complex &c2,int y)
// {
// 	c2.x+=1;
// 	c2.y+=1;
// 	return c2;
// }

complex operator ++(complex &c2,int y)
{
	c2.x+=1;
	c2.y+=1;
	return c2;
}

int main()
{
	complex c(10,10);
	// ++c;
	c.print();
	// c=c-2;
	// c.print();
	// c++;
	c++;
	c=c-1;
	c=c+1;
	c=1-c;
	c.print();


	return 0;
}