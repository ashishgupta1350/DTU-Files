#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class process{
public:
	int processIndex;
	float burstTime;
	float arrivalTime;
	float waitingTime;
	float turnAroundTime;
	bool isProcessed;
	process(float burstTime=0,float arrivalTime=0)
	{
		this->burstTime=burstTime;
		this->arrivalTime=arrivalTime;
		turnAroundTime=0;
		waitingTime=0;
		this->isProcessed = false;
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
// bool pqComparitor(process p1,process p2)
// {
// 	// return p1.
	
// }
int main()
{
	int n;
// 	cout<<"Enter the number of processes: ";
	cin>>n;
	process *p=new process[n];
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
	}
	int processedCount=0;
	int currentTime=0;
	sort(p,p+n,comparitor);
	priority_queue<process,vector<int>,pqComparitor()> pq;
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			if(p[i].arrivalTime<=currentTime and !p[i].isProcessed)
			{
				p[i].isProcessed=true; // so that it is not pushed again and again in the heap
				pq.push(p[i]);
			}
			else{
				break;
			}
		}
		currentTime++; // check this line
		if(!pq.empty())
		{
			process topProcess=pq.top();
			pq.pop();
			topProcess.burstTime-=1;
			
			if(topProcess.burstTime == 0)
			{
				processedCount++;
				if(processedCount==n)
				{
					break;
				}
				cout<<"Process : "<<topProcess.processIndex<<" ended at : "<<currentTime<<endl;
			}
			else{
				pq.push(topProcess);
			}


		}
	}


	return 0;


}