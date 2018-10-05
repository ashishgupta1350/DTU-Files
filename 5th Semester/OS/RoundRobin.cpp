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
	float tempBurstTime;
	process(float burstTime=0,float arrivalTime=0)
	{
		this->burstTime=burstTime;
		this->arrivalTime=arrivalTime;
		turnAroundTime=0;
		waitingTime=0;
	}
};
class pqComparitor
{

public:
  
  bool operator() (process &p1, process&p2) const
  {
    return p1.burstTime<p2.burstTime;
  }
};
bool comparitor(process p1, process p2)
{
	return p1.arrivalTime <= p2.arrivalTime;
}
int main()
{
	int n;
	cout<<"Enter the number of processes: ";
	cin>>n;
	process *p=new process[n];
	// process *pCopy=new process[n];

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
		p[i].tempBurstTime=x;
		// pCopy[i].processIndex=i;
		// pCopy[i].burstTime=x;
		// pCopy[i].arrivalTime=y;
	}
	int tQuantum;
	cout<<"Enter the time quantum : "<<endl;
	cin>>tQuantum;
	int currentTime=0;
	int myProcessIndex=0;
	sort(p,p+n,comparitor);
	queue<process> running;
	queue<process> ended;
	// the array is an array so...

	while(!running.empty() or myProcessIndex<n)
	{
		while(running.empty())
		{
			for(int i=myProcessIndex;i<n;i++)
			{
				if(currentTime<=p[i].arrivalTime)
				{
					running.push(p[i]); // push the process in running
					myProcessIndex+=1;
				}
			}
			if(running.empty()) currentTime+=1; // increment the time till the running has to 
		}
		// pick the process from running and run it for the time quantum
		process x=running.front();
		running.pop(); // the running array will pop
		if(x.burstTime > tQuantum)
		{
			cout<<"Running process: "<<x.processIndex<<endl;
			currentTime+=tQuantum;
			x.burstTime-=tQuantum;
			running.push(x);

		}
		else{
			currentTime+=x.burstTime;
			x.burstTime=0;
			cout<<"Process : "<<x.processIndex<<" ends at "<<currentTime<<endl;
			x.turnAroundTime=currentTime-x.arrivalTime;
			x.waitingTime=x.turnAroundTime-x.tempBurstTime;
			ended.push(x);

		}
		for(int i=myProcessIndex;i<=n;i++)
		{
			if(currentTime<=p[i].arrivalTime)
			{
				running.push(p[i]); // push the process in running
				myProcessIndex+=1;
			}
		}
	}
	while(!ended.empty())
	{
		process x=ended.front();
		ended.pop();
		cout<<"Process "<<x.processIndex<<" Turn Around Time is "<<x.turnAroundTime<<" and waiting time is "<<x.waitingTime<<endl;
	}

	return 0;
}
