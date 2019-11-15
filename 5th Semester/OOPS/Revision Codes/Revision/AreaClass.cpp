#include<iostream>
using namespace std;
#define PI 3.14
class shape{
public:
	double x,y;
	shape(double x=0,double y=0): x(x),y(y){

	}
	void getData(double x,double y=1)
	{
		this->x=x;
		this->y=y;
	}
	virtual void displayArea()=0;

};
class rectangle:public shape{
public:

	void displayArea(){
		cout<<x*y<<endl;
	}
		

};
class triangle:public shape{
public:

	void displayArea(){
		cout<<(1/2.0)*x*y<<endl;
	}

};
class circle:public shape{
public:

	void displayArea(){
		cout<<PI*x*x<<endl;
	}

};

int main()
{
	double x,y;
	char ch='A';
	bool flag=false;
	shape *s;
	do{
		cout<<"choose 1 for circle, 2 for rectange, 3 for triangle: ";
		int t;
		cin>>t;
		switch(t){
			case 1:
			{
				cout<<"enter x for circle: ";
				cin>>x;
				circle c;
				s=&c;
				s->getData(x);
				s->displayArea();
				break;
			}
			case 2:{
				cout<<"enter x ,y for rectangle: ";
				cin>>x>>y;
				rectangle r;
				s=&r;

				s->getData(x,y);
				s->displayArea();
				break;
			}
			case 3:{
				cout<<"enter x,y for triangle: ";
				cin>>x>>y;
				triangle t;
				s=&t;
				s->getData(x,y);
				s->displayArea();
				break;
			}
			default:
				flag=true;
				break;
		}
	}while(flag==false);


	return 0;
}