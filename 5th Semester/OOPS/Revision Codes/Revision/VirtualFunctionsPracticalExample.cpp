#include<iostream>
using namespace std;
class media{
public:
	string title;
	float price;
	media(string title="undefined",float price=0)
	{
		this->title=title;
		this->price=price;
	}
	virtual void showDetails()
	{
		cout<<"Why me? I am not even called!"<<endl;
	}
};

class book: public media{
public:
	string author;
	int pages;
	book(string title="media_integer",float price=0,string author="book_author",int pages=0):media(title,price)
	{
		this->author=author;
		this->pages=pages;
	}
	void showDetails()
	{
		cout<<pages<<" "<<author<<" "<<title<<" "<<price<<endl;
	}


};

class tape: public media{
public:
	int length; // time of tape in seconds
	string composer;
	tape(string title="tape_integer",float price=0, string composer="tape_composer",int length=0) : composer(composer),length(length),media(title,price){}
	void showDetails()
	{
		cout<<length<<" "<<composer<<" "<<title<<" "<<price<<endl;
	}
};
int main()
{
	// program uses default arguments to demontrate how the ptr to a media class can access all the books and tapes function using late binding!
	tape t1,t2,t3;
	book a1,a2,a3;
	media **ptr=new media*[6];
	ptr[0]=&t1;
	ptr[1]=&t2;
	ptr[2]=&t3;
	ptr[3]=&a1;
	ptr[4]=&a2;
	ptr[5]=&a3;;
	for(int i=0;i<6;i++)
	{
		ptr[i]->showDetails();
	}
	return 0;
}