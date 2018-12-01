#include<iostream>
#define MAX 3
using namespace std;
void myUnexpected()
{
  cout<<"Oh, How did I get called?"<<endl;
}

class queue{
  int arr[MAX];
  int front;
  int rear;

public:
  queue(int x=10,int y=10)
  {

    front=rear=-1;

  }
  ~queue()
  {
    cout<<"Destructor is called!"<<endl;
  }
  // get the exception handelling via return qclas
  class qFull{
  public:
    void message()
    {
      cout<<"queue is full"<<endl;
    }
  };
  class qDel{
  public:
    void message()
    {
      cout<<"q is empty\n";
    }

  };

  void addElement(int x)
  {
    if(front==-1){
      front++;
      rear=front;
      arr[rear++]=x;
      printQ();

      return;
    }
    if(rear==MAX)
    {
      throw qFull();
    }
    arr[rear++]=x;
    printQ();
    return;
  }
  void delElement()
  {
    if(front==-1)
    {
      throw(qDel());
    }
    front++;
    printQ();
    if(front==rear)
    {
      front=rear=-1;
    }


  }
  void printQ()
  {
    if(front==-1)
    {
      cout<<endl;
      return;
    }
    for(int i=front;i<rear;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  }
  void size()
  {
    cout<<"Size is : "<<rear-front+1<<endl;
  }
};
int main()
{
  queue myQ;
  try{
    myQ.addElement(10);
    myQ.addElement(430);
    myQ.addElement(430);



  }
  catch(queue::qFull)
  {
    cout<<"I am sorry, but you filled the array!"<<endl;
  }

  try{
    myQ.delElement();
    myQ.delElement();
    myQ.delElement();
    myQ.delElement();
    myQ.delElement();

  }
  catch(queue::qDel)
  {
    cout<<"The queue is empty!"<<endl;
  }
  cout<<"END"<<endl;


  queue y;
  set_unexpected(myUnexpected);
  try{

    try{
      queue testDestructor; // calls destructor as soon as we encounter a exception! This is so cool!
    y.addElement(10);
    y.addElement(10);
    y.addElement(10);
    y.addElement(10); // it gave an error while throwing some class, which I did not catch, so the compiller auto quit the application

    y.addElement(10);
    }
    catch(int something)
    {
      cout<<"this will not run"<<endl;
    }
  }
  catch(queue::qFull)
  {
    cout<<"Hello!"<<endl;
  }


  // y.delElement(20);
  return 0;
}
