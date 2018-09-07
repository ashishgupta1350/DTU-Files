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
	process(float burstTime=0,float arrivalTime=0)
	{
		this->burstTime=burstTime;
		this->arrivalTime=arrivalTime;
		turnAroundTime=0;
		waitingTime=0;
	}
};
bool comparitor(process p1, process p2)
{
	return p1.arrivalTime <= p2.arrivalTime;
}
/// WORKS :DDDD 
int main()
{
	// implementation of first come first serve algorithm

	int n;
// 	cout<<"Enter the number of processes: ";
	cin>>n;
	process *p=new process[n];
	process *pDuplicate=new process[n];
	for(int i=0;i<n;i++)
	{
		p[i].processIndex=i;
// 		cout<<"enter burst time for process : "<<i+1<<" : ";
		float x,y;
		cin>>x;
		p[i].burstTime=x;
// 		cout<<"enter arrival time for process : "<<i+1<<" : ";
		cin>>y;
		p[i].arrivalTime=y;
		pDuplicate[i]=p[i];
	}
	
	cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]"<<endl;
	for(int i=0;i<n;i++)
	{
	    int index=i;
	    cout <<setw(10) <<index << setw(6) << p[index].burstTime << setw(9) << p[index].arrivalTime <<endl;
	}
	// first come first serve algorithm
	// sort the processes on the basis of arrival time
	// take the process one by one and have a currentTime pointer to denote the processes that have come
	// complete the process and complete it, set the currentTime pointer to the end of the process. 
	// if the next process [arives] before the current time, then process it and set current time as currentTime+ burstTime, [store the current time and index of the process], it denotes the end of the process,
	//  else also process it, but the currentTime = arrivalTime of next process + burstTime for the next process [ store the current time and the index of the "NEXT" process], since it denotes the end of the next process
	float currentTime=0;
	sort(p, p+n, comparitor);
	queue<pair<int,float>> q; // index, currentTime
	for(int i=0;i<n;i++)
	{
		if(p[i].arrivalTime <= currentTime)
		{
			currentTime=currentTime+p[i].burstTime;
			pair<int,float> Pair(p[i].processIndex,currentTime);
			q.push(Pair);
		}
		else{
			currentTime=p[i].arrivalTime+p[i].burstTime;
			pair<int,float>Pair(p[i].processIndex,currentTime);
			q.push(Pair);
		}
	}
	// table construction sample
	cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]" <<setw(9)<<"[T.A.T]"<<setw(9)<<"[WaitingTime]"<<endl;
	while(!q.empty())
	{
		pair<int,float>Pair=q.front();
		q.pop();
		int index=Pair.first;
		int completitionTime=Pair.second;
		cout <<setw(10) <<index << setw(6) << pDuplicate[index].burstTime << setw(9) << pDuplicate[index].arrivalTime <<setw(9)<<completitionTime-pDuplicate[index].arrivalTime<<setw(9)<<completitionTime-pDuplicate[index].arrivalTime-pDuplicate[index].burstTime<<endl;
	}
	
	    
	return 0;
}