#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Polar;

class cartisian{
public:
	float x,y;

	cartisian(float x=0,float y=0)
	{
		this->x=x;
		this->y=y;
	}

	// operator + 
	cartisian operator+(cartisian &c2) 
	{
		cartisian c;
		c.x=x+c2.x;
		c.y=y+c2.y;
		return c;
	}

	// type conversion operator
	operator Polar()
	{
		Polar p;
		p.angle=atan(y/x);
		p.radius=sqrt(x*x+y*y);
		return p;
	}
	void put()
	{
		cout<<"x: "<<x<<endl;
		cout<<"y: "<<y<<endl;

	}
};

class Polar{
	
public:
	float radius;
	float angle;
	Polar(float radius=0,float angle=0)
	{
		this->radius=radius;
		this->angle=angle;
	}
	void put()
	{
		cout<<"radius : "<<radius<<endl;
		cout<<"angle : "<<angle<<endl;
	}

	Polar operator+(Polar p2)
	{
		cartisian c=*this;
		cartisian c2=p2;
		// then just add them
		cartisian c3= c+c2;
		// Polar p=c3;
		Polar p;
		p.angle=atan(c3.y/c3.x);
		p.radius=sqrt(c3.x*c3.x+c3.y*c3.y);
		return p;
	}
	operator cartisian()
	{
		// takes no argument
		cartisian c;
		c.x=radius*cos(angle);
		c.y=radius*sin(angle);
		return c;
	}

};
int main()
{

	Polar p1(10,1);
	Polar p2(20,2);
	Polar p3=p1+p2;
	p3.put();



	return 0;
}