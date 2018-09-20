#include<iostream>
using namespace std;

class bird{
public:
	int legs;
	string type; // migratory
	string eatsWhat;
	float life;	
	bird(int legs=20, string type="someRubbish")
	{
		this->legs=legs;
		this->type=type;
		eatsWhat="carnivorous";
		life=5;
	}

};

class flyingBird : public bird{

	int wings;
	bool isMigratory;

public:
	flyingBird(int legs=10,string type="herbivore") : bird(legs,type)
	{
		wings=2;
		isMigratory=false;
		// legs=3;
	}
};

class Box{
public:
	static int objectCount;
	// constructor definition
	Box(double l=2.0, double b=2.0,double h=2.0){
		length=l;
		breadth=b;
		height=h;
		objectCount++;
	}
	double Volume()
	{
		return 0; // something comes here instead of zero
	}
private:
	double length,breadth,height;

};
int Box::objectCount=0;

class node{
	int data;
	node*next;
public:
	node(int data=0,node *next=NULL)
	{
		this->data=data;
		this->next=NULL;
	}

	friend class LinkedList;
};
class LinkedList{
	node*head;
	node*tail;
public:
	LinkedList()
	{
		head=NULL;
		tail=NULL;
	}
	void create()
	{
		if(head) return;

		this->head=new node(10);
		this->tail=head;
		cout<<head->data<<endl; // data for head is private, if not for a friend class I wont be able to access it;
	}

};



// class operator overloading using and without using friend functions
class complex{
private:
	float a,b;
public:
	complex(float a,float b)
	{
		cout<<"constructor called"<<endl;
		this->a=a;
		this->b=b;
	}
	complex operator+(const complex &c2)
	{
		// we are having complex c2
		// lets program the code!
		this->a+=c2.a; // this will produce an error since the c2's a is a private entity
		this->b+=c2.b;
		return *this; // this is returned
	}
	void printData()
	{
		cout<<this->a<<" "<<this->b<<endl;
	}

};

// lets make our own cin

class CIN{
public:
	CIN()
	{

	}
	void operator >>(int &data)
	{
		int x;
		cin>>x;
		data=x;
		return;
	}


};

class COUT{
public:
	COUT()
	{

	}
	void operator <<(int &data)
	{
		cout<<data; // again it can be overloaded
	}
	

};

// pointers to object's variables??? I did not think of that
class someClass{
	public:
		int data;
	public:
		someClass(int data=1000)
		{
			this->data=data;
		}

};


int main()
{

	flyingBird b;
	cout<<b.legs<<endl;
	const flyingBird b2;
	// b2.legs=1000;
	cout<<b2.legs<<endl;
	Box b11,b12;
	cout<<Box::objectCount<<" "<<b11.objectCount<<" "<<b12.objectCount<<endl;



	// friend class maddness
	cout<<"----friend class code----"<<endl;
	LinkedList l1;
	l1.create();
	cout<<endl<<endl;
	cout<<"--- operator overloading and friend functions code --- "<<endl;
	complex c1(10,10);
	complex c2(10,10);
	// cout<<c2.a<<endl;
	complex c3=c1+c2; // its funny that the constructor is not called here?
	c3.printData();
	cout<<endl;
	cout<<endl;
	cout<<endl;
	// making my own Cin Class
	cout<<"--- self made cin code --- "<<endl;
	CIN x;
	int d;
	x>>d;
	cout<<d<<endl;
	// hence it is the fact that cin is actually an object with >> overloaded
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"--- self made COUT code --- "<<endl;
	COUT y;
	y<<d; // this will cout the value of d. we have renamed cout as y now ;)
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"--- pointers to object's variables --- "<<endl;
	someClass sc1;
	int *ptr=&sc1.data;
	cout<<*ptr<<endl;
	cout<<endl;



	return 0;
}