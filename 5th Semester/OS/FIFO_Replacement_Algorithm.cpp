#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node*next;
	node(int data=0)
	{
		this->data=data;
		this->next=NULL;
	}
};
class PageMemory{
	node*head;
	node*tail;
	int pageSize;
	int hitCount;
	// int pageCount;
	int currSize;
public:
	PageMemory(int pageSize=3)
	{
		this->head=this->tail=NULL;
		this->pageSize=pageSize;
		currSize=hitCount=0;
	}
	bool search(int x)
	{
		node*temp=head;
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				return true;
			}
			temp=temp->next;
		}
		return false;
	}
	void insert(int x)
	{
		if(search(x))
		{
			return;
		}
		else{
			hitCount++;
			node* n=new node(x);
			cout<<"here"<<endl;
			if(currSize<pageSize)
			{
				currSize++;
				if(!head)
				{
					head=tail=n;

				}
				else{
					tail->next=n;
					tail=tail->next;
				}
				return;
			}
			else{
				head=head->next;// Delete permanently from heap memory should be done
				tail->next=n;
				tail=tail->next;
				return;
			}
		}
		cout<<"here too"<<endl;
	}
	int getHitCount()
	{
		return this->hitCount;
	}
	void printPageMemory()
	{
		node*temp=head;
		while(temp)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
	}
};
int main()
{
	int pageSize=3;
	int arr[]={1,2,3,1,2,5,6};
	PageMemory pm(pageSize);
	for(int i=0;i<7;i++)
	{
		pm.insert(arr[i]);
		// cout<<"Hit count after inserting "<<arr[i]<<" is "<<pm.getHitCount()<<endl;
	}

	cout<<"Hit count is : "<<pm.hitCount<<endl;
	return 0;
}