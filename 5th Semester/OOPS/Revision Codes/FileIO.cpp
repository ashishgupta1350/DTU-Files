#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	float height[4]={1,2,3.31,4};
	ofstream outfile;
	outfile.open("Binary",ios::app);
	outfile.write((char*)&height,sizeof(height));
	outfile.close();
	ifstream infile;
	for(int i=0;i<4;i++)
	{
		height[i]=0;
	}
	infile.open("Binary");
	infile.read((char*)&height,sizeof(height));
	for(int i=0;i<4;i++)
	{
		cout.setf(ios::showpoint);
		cout<<setw(10)<<setprecision(2)<<height[i];
	}
	infile.close();
	return 0;
}