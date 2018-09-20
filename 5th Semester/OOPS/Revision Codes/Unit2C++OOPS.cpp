#include<iostream>
using namespace std;
class xy{
public:
	xy()
	{
		cout<<"calls the constructor"<<endl;
	}
	~xy()
	{
		cout<<"calls the destructor"<<endl;
	}
};
class room{
	int  length;
	int width;
	static int count;
public:
 	room()
 	{
 		length=0;
 		width=0;
 	}
 	void display()
 	{
 		cout<<length<<' '<<width;
 	}
 	room(room&r)
 	{
 		width=r.width;
 		length=r.length;
 		count++;
 	}
 	void displayCount()
 	{
 		cout<<count<<endl;
 	}
};
int room::count=0;
int main()
{

	xy();
	xy c;
	room o1;
	// o1.display();
	o1.displayCount();
	room o2(o1);
	o1.displayCount(); // great 
	room o3;
	o3=o2;
	o1.displayCount();
	room o4=o2;
	o4.displayCount();
	
	return 0;

}