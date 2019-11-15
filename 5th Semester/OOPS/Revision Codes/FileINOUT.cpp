// #include<iostream>
// #include<fstream>
// #include<iomanip>

// using namespace std;

// int main()
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class INVENTORY{
	char name[10];
	int code;
	float cost;
public:
	void getData()
	{
		cout<<"enter name, code cost"<<endl;
		cin>>this->name>>this->code>>this->cost;

	}
	void putData()
	{
		cout<<name<<endl<<code<<endl<<cost<<endl;
	}
};
using namespace std;
int main()
{
	INVENTORY item;
	fstream inoutfile;
	inoutfile.open("Stock.DAT",ios::ate|ios::in|ios::out|ios::binary);
	inoutfile.seekg(0,ios::beg);
	while(inoutfile.read((char*) &item,sizeof(item)))
	{
		item.putData();
	}

	cout<<"Add a new item"<<endl;
	item.getData();
	char ch;
	cin.get(ch);
	inoutfile.write((char*) &item,sizeof(item));

	// display the file should be easy;
	while(inoutfile.read((char*) &item,sizeof(item)))
	{
		item.putData();
	}

	// find the number of objects in the file
	int last=inoutfile.tellg();
	int size_=sizeof(item);
	cout<<"number of objects is : "<<last/size_<<endl;
	cout<<"number of bytes is :    "<<last<<endl;
	return 0;

}