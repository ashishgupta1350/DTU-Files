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
	float priority;
	process(float burstTime=0,float arrivalTime=0)
	{
		this->burstTime=burstTime;
		this->arrivalTime=arrivalTime;
		turnAroundTime=0;
		waitingTime=0;
		this->priority=1;
	}
};
// bool priorityQueueComparitor(process &p1,process &p2)
// {
// 	return p1.priority>=p2.priority;// sorts in decremental order
// }
class priorityQueueComparitor{
    
  public:
    
    bool operator()(const process &p1, const process &p2) const {
      return p1.priority<=p2.priority;
    }
};
bool comparitor(process &p1, process &p2)
{
	return p1.arrivalTime <= p2.arrivalTime;
}
/// WORKS :DDDD 
int main()
{
	// implementation of priority queue scheduling algorithm

	int n;
// 	cout<<"Enter the number of processes: ";
	cin>>n;
	process *p=new process[n];
	process *pDuplicate=new process[n];
	for(int i=0;i<n;i++)
	{
		p[i].processIndex=i;
		// cout<<"enter burst time for process : "<<i+1<<" : ";
		float x,y,z;
		cin>>x;
		p[i].burstTime=x;
		// cout<<"enter arrival time for process : "<<i+1<<" : ";
		cin>>y;
		p[i].arrivalTime=y;

		// cout<<"enter the priority for the process: "<<i+1<<" : ";
		cin>>z;
		p[i].priority=z;
		pDuplicate[i]=p[i];
	}
	
	cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]"<<endl;
	for(int i=0;i<n;i++)
	{
	    int index=i;
	    cout <<setw(10) <<index << setw(6) << p[index].burstTime << setw(9) << p[index].arrivalTime <<endl;
	}
	// Priority Queue scheduling algorithm
	// Sort the process according to start time
	// increase the start time by 1 in a loop. have a priority queue and process queue. in the priority queue, the process
	// get added as they come with time. If the processes priority is > priority of running process, then preemt it and run the
	// higher priority process first
	float currentTime=0;
	sort(p, p+n, comparitor);
	queue<process> q; // index, currentTime
	queue<pair<int,float>> myQ;

	priority_queue<process,vector<process>,priorityQueueComparitor> pq;

	for(int i=0;i<n;i++)
	{
		q.push(p[i]);
	}
// 3
// 3 1 2
// 3 2 7
// 3 3 5
	while(!q.empty() || !pq.empty())
	{
		// cout<<"Here"<<endl;
		process x;
		if(!q.empty())
		{
			x = q.front();
			
			if(x.arrivalTime<=currentTime)
			{
				pq.push(x);
				q.pop();
			}
		}
		if(!pq.empty())
		{
			// do what you were doing
			process H=pq.top();
			cout<<"processing process: "<<H.processIndex<<endl;
			pq.pop();
			H.burstTime-=1;
			if(H.burstTime==0)
			{
				pair<int,float> Pair(H.processIndex,currentTime);
				cout<<"process finished (1 - index): "<<H.processIndex + 1<<endl;
				myQ.push(Pair);
			}
			else{
				pq.push(H);
			}	

		}
		currentTime++;
	}
	// table construction sample
	cout <<setw(10) << "[Process]" << setw(6) << "[Burst Time]" << setw(9) << "[Arrival]" <<setw(9)<<"[T.A.T]"<<setw(9)<<"[WaitingTime]"<<endl;
	while(!myQ.empty())
	{
		pair<int,float>Pair=myQ.front();
		myQ.pop();
		int index=Pair.first;
		int completitionTime=Pair.second;
		cout <<setw(10) <<index << setw(6) << pDuplicate[index].burstTime << setw(9) << pDuplicate[index].arrivalTime <<setw(9)<<completitionTime-pDuplicate[index].arrivalTime<<setw(9)<<completitionTime-pDuplicate[index].arrivalTime-pDuplicate[index].burstTime<<endl;
	}
	
	    
	return 0;
}