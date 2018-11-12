#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes: ";
	cin>>n;
	int *arr=new int[n];
	int *selected=new int[n];
	cout<<"Enter the processes position on disk : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		selected[i]=0; //selected
	}
	int k;
	cout<<"enter initial diskHead position : ";
	cin>>k;
	int diskHead=k;
	int travelDistance=0;
	for(int i=0;i<n;i++)
	{
		// for each of the n processes;
		int minimum=100000;
		int minIndex=0;
		for(int j=0;j<n;j++)
		{
			if(selected[j]==0)
			{
				int diff=abs(diskHead-arr[j]);
				if(diff<minimum)
				{
					minimum=diff;
					minIndex=j;
					cout<<diff<<endl;
					
				}
			}

		}
		selected[minIndex]=1; // that selected is true;
		travelDistance+=abs(diskHead-arr[minIndex]);
		cout<<"Selected process : "<<minIndex+1<<endl;
		diskHead=arr[minIndex];
	}

	cout<<"The sum of distance traveled by head is : "<<travelDistance<<endl;
	return 0;
	


}