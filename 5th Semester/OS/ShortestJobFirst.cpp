#include<iostream>
#include<bits/stdc++.h>                                  // Works Well :D
using namespace std;
class process{
public:
	int processIndex;
	float burstTime;
	float arrivalTime;
	float waitingTime;
	float turnAroundTime;
	bool considered;
	process(float burstTime=0,float arrivalTime=0)
	{
		this->burstTime=burstTime;
		this->arrivalTime=arrivalTime;
		turnAroundTime=0;
		waitingTime=0;
		this->considered=false;
	}
};
bool comparitor(process p1, process p2)
{
	return p1.arrivalTime <= p2.arrivalTime;
}
/// WORKS :DDDD 
int main()
{
	// implementation of shortest Job First algorithm

	int n;
	cout<<"Enter the number of processes: ";
	cin>>n;
	process *p=new process[n];
	process *pDuplicate=new process[n];
	for(int i=0;i<n;i++)
	{
		p[i].processIndex=i;
		cout<<"enter burst time for process : "<<i+1<<" : ";
		float x,y;
		cin>>x;
		p[i].burstTime=x;
		cout<<"enter arrival time for process : "<<i+1<<" : ";
		cin>>y;
		p[i].arrivalTime=y;
		pDuplicate[i]=p[i];
	}
	
	// Output of the processes entered
	cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]"<<endl;
	for(int i=0;i<n;i++)
	{
	    int index=i;
	    cout <<setw(10) <<index << setw(6) << p[index].burstTime << setw(9) << p[index].arrivalTime <<endl;
	}
	// Shortest job first algorithm
	// take the process one by one and have a currentTime pointer to denote the processes that have come
	int prIndex=0;
	int minPrTime=100000;
	cout<<endl<<"---- Shortest Job First Algorithm ----"<<endl;
	cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]" <<setw(9)<<"[T.A.T]"<<setw(9)<<"[WaitingTime]"<<endl;
	for(int i=0;i<n;i++)
	{
		minPrTime=100000;
		for(int i=0;i<n;i++)
		{
			// O(n^2) approach
			if(!p[i].considered && p[i].arrivalTime <= currentTime)
			{
				if(p[i].burstTime<minPrTime)
				{
					minPrTime=p[i].burstTime;
					prIndex=i; // this is done
				}
			}
		}
		currentTime+=p[prIndex].burstTime;
		p[prIndex]=true;
		cout <<setw(10) <<prIndex << setw(6) << p[prIndex].burstTime << setw(9) << p[prIndex].arrivalTime <<setw(9)<<currentTime-p[prIndex].arrivalTime<<setw(9)<<currentTime-p[prIndex].arrivalTime-p[prIndex].burstTime<<endl;
		
	}
	// table construction sample
	// cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]" <<setw(9)<<"[T.A.T]"<<setw(9)<<"[WaitingTime]"<<endl;
	// while(!q.empty())
	// {
	// 	pair<int,float>Pair=q.front();
	// 	q.pop();
	// 	int index=Pair.first;
	// 	int completitionTime=Pair.second;
	// 	cout <<setw(10) <<index << setw(6) << pDuplicate[index].burstTime << setw(9) << pDuplicate[index].arrivalTime <<setw(9)<<completitionTime-pDuplicate[index].arrivalTime<<setw(9)<<completitionTime-pDuplicate[index].arrivalTime-pDuplicate[index].burstTime<<endl;
	// }
	
	    
	return 0;
}