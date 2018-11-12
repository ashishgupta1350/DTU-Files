#include<iostream>
using namespace std;
#include<list>


// advanced delete to do work of 2 functions at a time
bool deleteKey(list<int> &myList,int key)
{
	auto it=myList.begin();
	bool flag=false;
	for(it=myList.begin();it!=myList.end();it++)
	{
		
		if(*it == key)
		{
			
			flag=true;

			break;

		}
	}
	if(flag)
	{
		myList.erase(it);
		return true;
	}

	return false; // not found key
}

void printCache(list<int>& l)
{
	for(auto it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
}

int main()
{
	int n;
	cout<<"Enter the number of pages coming: ";
	cin>>n;
	cout<<"Enter incoming pages: ";
	int *incommingPages=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>incommingPages[i];
	}

	int pageMemorySize;
	cout<<"Enter the size of Cache: ";
	cin>>pageMemorySize;
	// initialize the page memory as blank
	list<int> pageCache;
	int hitCount=0;
	// so the page cache is empty
	for(int i=0;i<n;i++)
	{
		int key=incommingPages[i];
		// for each key do this :
		if(pageCache.size()<pageMemorySize)
		{
			if(deleteKey(pageCache,key))
			{
				pageCache.push_front(key); // no hit count, so bring the key forward ( delete and append back )
			}
			else{
				pageCache.push_front(key);
				hitCount++;
				cout<<"Miss!"<<endl;
			}
		}
		else{
			if(deleteKey(pageCache,key))
			{
				pageCache.push_front(key);
			}
			else{
				pageCache.push_front(key);
				pageCache.pop_back();
				hitCount++;
				cout<<"Miss!"<<endl;
			}

		}
		cout<<"The new cache is : ";
		printCache(pageCache);
		cout<<endl;

	}
	cout<<"The total miss count is : "<<hitCount<<endl;
	
	return 0;
}